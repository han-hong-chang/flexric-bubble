package main

import "C"
import (
	"encoding/json"
	xapp "final.com/xapp_sdk"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strconv"
	"sync"
	"time"
)

// ------------------------------------------------------------------------ //
//  SLICE INDICATION MSG TO JSON
// ------------------------------------------------------------------------ //

var assoc_rnti int

func sliceIndToDictJSON(ind xapp.Swig_slice_ind_msg_t) {

	// lock the mutex
	mu.Lock()
	dlDict := RanState["RAN"].(map[string]interface{})["dl"].(map[string]interface{})

	if ind.GetSlice_stats().GetDl().GetLen_slices() <= 0 {
		dlDict["num_of_slices"] = ind.GetSlice_stats().GetDl().GetLen_slices()
		dlDict["slice_sched_algo"] = "null"
		dlDict["ue_sched_algo"] = ind.GetSlice_stats().GetDl().GetSched_name().Get(0)
	} else {
		dlDict["num_of_slices"] = ind.GetSlice_stats().GetDl().GetLen_slices()
		dlDict["slice_sched_algo"] = "null"
		dlDict["slices"] = []map[string]interface{}{}

		var sliceAlgo string = ""

		for i := 0; i < int(ind.GetSlice_stats().GetDl().GetSlices().Size()); i++ {
			// obtain current slice
			var currSlice = ind.GetSlice_stats().GetDl().GetSlices().Get(i)
			// obtain current slice's parameters type
			var sliceType = currSlice.GetParams().GetXtype()

			switch sliceType {
			case 1:
				sliceAlgo = "STATIC"
			case 2:
				sliceAlgo = "NVS"
			case 4:
				sliceAlgo = "EDF"
			default:
				sliceAlgo = "unknown"
			}
			dlDict["slice_sched_algo"] = sliceAlgo

			sliceDict := map[string]interface{}{
				"index":         int(currSlice.GetId()),
				"label":         currSlice.GetLabel().Get(0),
				"ue_sched_algo": currSlice.GetSched().Get(0),
			}

			if dlDict["slice_sched_algo"] == "STATIC" {
				sliceDict["slice_algo_params"] = map[string]interface{}{
					"pos_low":  currSlice.GetParams().GetU().GetSta().GetPos_low(),
					"pos_high": currSlice.GetParams().GetU().GetSta().GetPos_high(),
				}
			} else if dlDict["slice_sched_algo"] == "NVS" {
				if currSlice.GetParams().GetU().GetNvs().GetConf() == 0 {
					sliceDict["slice_algo_params"] = map[string]interface{}{
						"type":      "RATE",
						"mbps_rsvd": currSlice.GetParams().GetU().GetNvs().GetU().GetRate().GetU1().GetMbps_required(),
						"mbps_ref":  currSlice.GetParams().GetU().GetNvs().GetU().GetRate().GetU2().GetMbps_reference(),
					}
				} else if currSlice.GetParams().GetU().GetNvs().GetConf() == 1 {
					sliceDict["slice_algo_params"] = map[string]interface{}{
						"type":     "CAPACITY",
						"pct_rsvd": currSlice.GetParams().GetU().GetNvs().GetU().GetCapacity().GetU().GetPct_reserved(),
					}
				} else {
					sliceDict["slice_algo_params"] = map[string]interface{}{
						"type": "unknown",
					}
				}
			} else if dlDict["slice_sched_algo"] == "EDF" {
				sliceDict["slice_algo_params"] = map[string]interface{}{
					"deadline":        currSlice.GetParams().GetU().GetEdf().GetDeadline(),
					"guaranteed_prbs": currSlice.GetParams().GetU().GetEdf().GetGuaranteed_prbs(),
					"max_replenish":   currSlice.GetParams().GetU().GetEdf().GetMax_replenish(),
				}
			} else {
				fmt.Println("unknown slice algorithm, cannot handle params")
			}
			dlDict["slices"] = append(dlDict["slices"].([]map[string]interface{}), sliceDict)
		}

	}
	ueDict := RanState["UE"].(map[string]interface{})
	if ind.GetUe_slice_stats().GetLen_ue_slice() <= 0 {
		ueDict["num_of_ues"] = ind.GetUe_slice_stats().GetLen_ue_slice()
	} else {
		ueDict["num_of_ues"] = ind.GetUe_slice_stats().GetLen_ue_slice()
		ueDict["ues"] = []map[string]interface{}{}

		for i := 0; i < int(ind.GetUe_slice_stats().GetUes().Size()); i++ {
			// obtain current ue
			var currUe = ind.GetUe_slice_stats().GetUes().Get(i)

			var dlId string
			if currUe.GetDl_id() >= 0 && dlDict["num_of_slices"].(uint) > 0 {
				dlId = string(currUe.GetDl_id())
			} else {
				dlId = "Null"
			}

			uesDict := map[string]interface{}{
				"rnti":              fmt.Sprintf("%x", currUe.GetRnti()),
				"assoc_dl_slice_id": dlId,
			}
			ueDict["ues"] = append(ueDict["ues"].([]map[string]interface{}), uesDict)
			assoc_rnti = int(currUe.GetRnti())
		}
	}

	indDict := RanState

	file, _ := os.Create("rt_slice_stats.json")
	defer file.Close()

	indJson, _ := json.Marshal(indDict)
	file.Write(indJson)

	mu.Unlock()
}

// ------------------------------------------------------------------------ //
//  SLICE INDICATION CALLBACK
// ------------------------------------------------------------------------ //

type SLICECallback struct {
	//xapp.SwigcptrSlice_cb
}

func (c SLICECallback) Handle(ind xapp.Swig_slice_ind_msg_t) {
	sliceIndToDictJSON(ind)
}

// ------------------------------------------------------------------------ //
//  SLICE CONTROL FUNCS
// ------------------------------------------------------------------------ //

func CreateSlice(sliceParams Slices, sliceSchedAlgo string) xapp.Fr_slice_t {
	newSlice := xapp.NewFr_slice_t()

	newSlice.SetId(uint(sliceParams.Id))
	newSlice.SetLabel(sliceParams.Label)
	newSlice.SetLen_label(uint(len(sliceParams.Label)))
	newSlice.SetSched(sliceParams.UeSchedAlgo)
	newSlice.SetLen_sched(uint(len(sliceParams.UeSchedAlgo)))

	if sliceSchedAlgo == "STATIC" {
		params := xapp.NewSlice_params_t()
		sliceU := xapp.NewSlice_params_u()
		sta := xapp.NewStatic_slice_t()

		sta.SetPos_low(uint(sliceParams.SliceAlgoParams.PosLow))
		sta.SetPos_high(uint(sliceParams.SliceAlgoParams.PosHigh))

		sliceU.SetSta(sta)
		params.SetXtype(xapp.Slice_algorithm_e(xapp.SLICE_ALG_SM_V0_STATIC))
		params.SetU(sliceU)
		newSlice.SetParams(params)
	} else if sliceSchedAlgo == "NVS" {
		params := xapp.NewSlice_params_t()

		params.SetXtype(xapp.Slice_algorithm_e(xapp.SLICE_ALG_SM_V0_NVS))

		if sliceParams.Type == "SLICE_SM_NVS_V0_RATE" {
			params := xapp.NewSlice_params_t()
			sliceU := xapp.NewSlice_params_u()
			nvs := xapp.NewNvs_slice_t()
			nvsSliceU := xapp.NewNvs_slice_u()
			rate := xapp.NewNvs_rate_t()
			u1 := xapp.NewNvs_rate_req_u()
			u2 := xapp.NewNvs_rate_ref_u()

			u1.SetMbps_required(float32(sliceParams.SliceAlgoParams.MbpsRsvd))
			u2.SetMbps_reference(float32(sliceParams.SliceAlgoParams.MbpsRef))

			rate.SetU1(u1)
			rate.SetU2(u2)

			nvsSliceU.SetRate(rate)

			nvs.SetConf(xapp.Nvs_slice_conf_e(xapp.SLICE_SM_NVS_V0_RATE))
			nvs.SetU(nvsSliceU)

			sliceU.SetNvs(nvs)

			params.SetU(sliceU)

			newSlice.SetParams(params)
		} else if sliceParams.Type == "SLICE_SM_NVS_V0_CAPACITY" {
			params := xapp.NewSlice_params_t()
			sliceU := xapp.NewSlice_params_u()
			nvs := xapp.NewNvs_slice_t()
			nvsSliceU := xapp.NewNvs_slice_u()
			capacity := xapp.NewNvs_capacity_t()
			capacityU := xapp.NewNvs_capacity_u()

			capacityU.SetPct_reserved(float32(sliceParams.SliceAlgoParams.PctRsvd))

			capacity.SetU(capacityU)
			nvsSliceU.SetCapacity(capacity)
			nvs.SetConf(xapp.Nvs_slice_conf_e(xapp.SLICE_SM_NVS_V0_CAPACITY))
			nvs.SetU(nvsSliceU)
			sliceU.SetNvs(nvs)
			params.SetU(sliceU)
			newSlice.SetParams(params)
		} else {
			log.Println("ERROR: Unknown NVS slice type")
		}
	} else if sliceSchedAlgo == "EDF" {
		params := xapp.NewSlice_params_t()
		sliceU := xapp.NewSlice_params_u()
		edf := xapp.NewEdf_slice_t()

		edf.SetDeadline(uint(sliceParams.SliceAlgoParams.Deadline))
		edf.SetGuaranteed_prbs(uint(sliceParams.SliceAlgoParams.GuaranteedPrbs))
		edf.SetMax_replenish(uint(sliceParams.SliceAlgoParams.MaxReplenish))

		sliceU.SetEdf(edf)

		params.SetXtype(xapp.Slice_algorithm_e(xapp.SLICE_ALG_SM_V0_EDF))
		params.SetU(sliceU)
	} else {
		log.Println("ERROR: Unknown slice scheduling algorithm")
	}

	return newSlice
}

// ------------------------------------------------------------------------ //
//  SLICE CONTROL PARAMETER EXAMPLE - ADD SLICE
// ------------------------------------------------------------------------ //

type SliceAlgoParams struct {
	PosLow  int `json:"pos_low,omitempty"`
	PosHigh int `json:"pos_high,omitempty"`

	MbpsRsvd int `json:"mbps_rsvd,omitempty"`
	MbpsRef  int `json:"mbps_ref,omitempty"`

	PctRsvd float64 `json:"pct_rsvd,omitempty"`

	Deadline       int `json:"deadline"`
	GuaranteedPrbs int `json:"guaranteed_prbs"`
	MaxReplenish   int `json:"max_replenish"`
}

type Slices struct {
	Id              int             `json:"id"`
	Label           string          `json:"label"`
	UeSchedAlgo     string          `json:"ue_sched_algo"`
	Type            string          `json:"type,omitempty"`
	SliceAlgoParams SliceAlgoParams `json:"slice_algo_params,omitempty"`
}

type Ues struct {
	Rnti           int `json:"rnti"` // TODO: get rnti from slice_ind_to_dict_json()
	AssocDlSliceId int `json:"assoc_dl_slice_id"`
}

type Request struct {
	NumSlices       int      `json:"num_slices,omitempty"`
	SliceSchedAlgo  string   `json:"slice_sched_algo,omitempty"`
	Slices          []Slices `json:"slices,omitempty"`
	NumDlSlices     int      `json:"num_dl_slices,omitempty"`
	DeleteDlSliceId []int    `json:"delete_dl_slice_id"`

	NumUes int   `json:"num_ues,omitempty"`
	Ues    []Ues `json:"ues,omitempty"`
}

func FillSliceCtrlMsg(ctrlType string, ctrlMsg Request) xapp.Slice_ctrl_msg_t {
	msg := xapp.NewSlice_ctrl_msg_t()

	if ctrlType == "ADDMOD" {
		msg.SetXtype(xapp.Slice_ctrl_msg_e(xapp.SLICE_CTRL_SM_V0_ADD))
		dl := xapp.NewUl_dl_slice_conf_t()
		//TODO: UL SLICE CTRL ADD
		//ul = ric.ul_dl_slice_conf_t()
		//ue_sched_algo can be "RR"(round-robin), "PF"(proportional fair) or "MT"(maximum throughput) and it has to be set in any len_slices

		var ueSchedAlgo string = "PF"
		dl.SetSched_name(ueSchedAlgo)
		dl.SetLen_sched_name(uint(len(ueSchedAlgo)))

		dl.SetLen_slices(uint(ctrlMsg.NumSlices))

		slices := xapp.NewSlice_array(ctrlMsg.NumSlices)
		//slices = xapp.Slice_array(ctrlMsg.(map[string]interface{})["slices"].(xapp.Slice_array))

		for i := 0; i < ctrlMsg.NumSlices; i++ {
			slices.Setitem(i, CreateSlice(ctrlMsg.Slices[i], ctrlMsg.SliceSchedAlgo))
		}

		dl.SetSlices(slices.Cast())

		u := xapp.NewSlice_ctrl_msg_u()
		addModSlice := xapp.NewSlice_conf_t()

		addModSlice.SetDl(dl)
		u.SetAdd_mod_slice(addModSlice)
		msg.SetU(u)

	} else if ctrlType == "DEL" {
		msg.SetXtype(xapp.Slice_ctrl_msg_e(xapp.SLICE_CTRL_SM_V0_DEL))
		u := xapp.NewSlice_ctrl_msg_u()
		delSlice := xapp.NewDel_slice_conf_t()

		delSlice.SetLen_dl(uint(ctrlMsg.NumDlSlices))
		u.SetDel_slice(delSlice)
		msg.SetU(u)

		del_dl_id := xapp.NewDel_dl_array(ctrlMsg.NumDlSlices)

		for i := 0; i < ctrlMsg.NumDlSlices; i++ {
			del_dl_id.Setitem(i, uint(ctrlMsg.DeleteDlSliceId[i]))
		}

		u2 := xapp.NewSlice_ctrl_msg_u()
		delSlice2 := xapp.NewDel_slice_conf_t()

		delSlice2.SetDl(del_dl_id.Cast())
		u2.SetDel_slice(delSlice2)
		msg.SetU(u2)

	} else if ctrlType == "ASSOC_UE_SLICE" {
		msg.SetXtype(xapp.Slice_ctrl_msg_e(xapp.SLICE_CTRL_SM_V0_UE_SLICE_ASSOC))

		u := xapp.NewSlice_ctrl_msg_u()
		ueSlice := xapp.NewUe_slice_conf_t()

		ueSlice.SetLen_ue_slice(uint(ctrlMsg.NumUes))
		u.SetUe_slice(ueSlice)
		msg.SetU(u)

		assoc := xapp.NewUe_slice_assoc_array(ctrlMsg.NumUes)
		for i := 0; i < ctrlMsg.NumUes; i++ {
			a := xapp.NewUe_slice_assoc_t()
			a.SetRnti(uint16(assoc_rnti))
			a.SetDl_id(uint(ctrlMsg.Ues[i].AssocDlSliceId))
			// TODO: UL SLICE CTRL ASSOC
			// a.ul_id = 0
			assoc.Setitem(i, a)
		}

		u2 := xapp.NewSlice_ctrl_msg_u()
		ueSlice2 := xapp.NewUe_slice_conf_t()
		ueSlice2.SetUes(assoc.Cast())
		u2.SetUe_slice(ueSlice2)
		msg.SetU(u2)
	}

	return msg
}

// ------------------------------------------------------------------------ //
//  Global Sharable Structure for RAN State
// ------------------------------------------------------------------------ //

var RanState = map[string]interface{}{
	"RAN": map[string]interface{}{
		"dl": map[string]interface{}{},
	},
	"UE": map[string]interface{}{},
}

var Conn xapp.E2NodeVector

var NodeIdx = 0

var Hndlr int

var Inner SLICECallback
var Callback xapp.Slice_cb

var mu sync.Mutex

var TrashedSliceId = -1

// ------------------------------------------------------------------------ //
//  Goroutine Function to Handle Report of RAN State
// ------------------------------------------------------------------------ //

func HandleSliceIndication() {
	Hndlr = xapp.Report_slice_sm(Conn.Get(NodeIdx).GetId(), xapp.Interval_ms_5, Callback)
	fmt.Println("Slice Indication Handler = ", Hndlr)

}

// ------------------------------------------------------------------------ //
// Goroutine Function to Handle Policy Enforcement
// ------------------------------------------------------------------------ //

func HandlePolicyEnforcement() {
	fmt.Println("Handle Policy Enforcement")

	// Here we know the policy. Lets say that the policy is to have maximum of 2 UEs
	policyMaxNumUes := 2

	// loop until policy is met
	for i := 0; i < 5; i++ {
		// Read the RAN State
		mu.Lock()
		// Get all slices
		//numOfSlices := RanState["RAN"].(map[string]interface{})["dl"].(map[string]interface{})["num_of_slices"].(int)
		//slices := RanState["RAN"].(map[string]interface{})["dl"].(map[string]interface{})["slices"].([]interface{})

		// Get all UEs
		numOfUes := int(RanState["UE"].(map[string]interface{})["num_of_ues"].(uint))
		ues := RanState["UE"].(map[string]interface{})["ues"].([]map[string]interface{})

		// Check if policy is met
		if numOfUes > policyMaxNumUes {
			// Remove one random UE by associating it with the trash slice
			trashedUeIdx := rand.Intn(numOfUes)
			trashedUeRnti := ues[trashedUeIdx]["rnti"].(string)

			trashedUeRntiInt, err := strconv.Atoi(trashedUeRnti)

			if err != nil {
				fmt.Println("Error during conversion")
				return
			}
			// Associate the UE with the trash slice
			ues := Ues{
				Rnti:           trashedUeRntiInt,
				AssocDlSliceId: TrashedSliceId,
			}
			assocUeSlice := Request{
				NumUes: 1,
				Ues:    []Ues{ues},
			}
			msg2 := FillSliceCtrlMsg("ASSOC_UE_SLICE", assocUeSlice)
			xapp.Control_slice_sm(Conn.Get(NodeIdx).GetId(), msg2)

		}
		mu.Unlock()
		time.Sleep(1 * time.Second)
	}
}

// ------------------------------------------------------------------------ //
//  MAIN
// ------------------------------------------------------------------------ //
func main() {

	xapp.Init()

	// Connect
	Conn = xapp.Conn_e2_nodes()

	var nodes_len int64 = Conn.Size()

	if nodes_len <= 0 {
		panic(fmt.Sprintf("panic"))
	}

	fmt.Printf("Connected E2 nodes = %d\n", nodes_len)

	// ----------------------- CREATE TRASH SLICE ----------------------- //
	trashsliceParams := SliceAlgoParams{PosLow: 0, PosHigh: 2}
	trashSlice := Slices{
		Id:              TrashedSliceId,
		Label:           "s3",
		UeSchedAlgo:     "PF",
		SliceAlgoParams: trashsliceParams}

	// AddStaticSlices
	AddTrashSlice := Request{
		NumSlices:      1,
		SliceSchedAlgo: "STATIC",
		Slices:         []Slices{trashSlice},
	}

	msg := FillSliceCtrlMsg("ADDMOD", AddTrashSlice)
	xapp.Control_slice_sm(Conn.Get(NodeIdx).GetId(), msg)

	// ----------------------- SET GOROUTINE FOR RAN STATE REPORT ----------------------- //
	// Define Callback
	Inner = SLICECallback{}
	Callback = xapp.NewDirectorSlice_cb(Inner)
	go HandleSliceIndication()

	time.Sleep(5 * time.Second)
	// ----------------------- SET GOROUTINE FOR POLICY ENFORCEMENT ----------------------- //
	HandlePolicyEnforcement()

	// ----------------------- END ----------------------- //
	xapp.Rm_report_slice_sm(Hndlr)
	// --------------------------------------------------------- //
	// Stop the xApp. Avoid deadlock.
	for xapp.Try_stop() == false {
		time.Sleep(1000 * time.Microsecond)
	}

	fmt.Printf("Test xApp run SUCCESSFULLY\n")

}

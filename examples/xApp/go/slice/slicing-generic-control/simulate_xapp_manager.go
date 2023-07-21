package main

import "C"
import (
	"time"
	"net/http"
	//"os"
	//"os/signal"
	//"syscall"
	//"context"
	"log"
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"

	utils "build/examples/xApp/go/utils/slice_utils"
)


var server1URL = "http://localhost:9000/api/policy"

func main() {
	time.Sleep(3 * time.Second)

	// ----------------- GET SliceStats ----------------- //
	resp, err := http.Get("http://localhost:9000/api/slice/stats")
	if err != nil {
		fmt.Println("Error:", err)
		return
	} 
		
	fmt.Println("GET SliceStats")
	
	defer resp.Body.Close()

	
	err = json.NewDecoder(resp.Body).Decode(&utils.SliceStats)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	// Marshal the interface back to JSON with indentation
	prettyJSON, err := json.MarshalIndent(utils.SliceStats, "", "    ")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	// Convert the byte slice to a string and print it
	fmt.Println(string(prettyJSON))

	// Use the sliceStats variable as needed
	//fmt.Println(utils.SliceStats)
	rntis := utils.ReadSliceStats("rntis", -1)
	fmt.Println("RNTIS: ",rntis)

	time.Sleep(10 * time.Second)
	// ----------------- First Policy ----------------- //
	s1_params_nvs := utils.SliceAlgoParams{PctRsvd: 0.5}
	s1_nvs := utils.Slice{
		Id:          0,
		Label:       "s1",
		UeSchedAlgo: "PF",
		Type:        "SLICE_SM_NVS_V0_CAPACITY",
		SliceAlgoParams: s1_params_nvs}

	// Idle slice
	s2_params_nvs := utils.SliceAlgoParams{PctRsvd: 0.05}
	s2_nvs := utils.Slice{
		Id:          2,
		Label:       "idle",
		UeSchedAlgo: "PF",
		Type:        "SLICE_SM_NVS_V0_CAPACITY",
		SliceAlgoParams: s2_params_nvs}

	// AddStaticSlices
	addNvsSlicesCap := utils.Request{
		NumSlices:      2,
		SliceSchedAlgo: "NVS",
		Slices:         []utils.Slice{s1_nvs, s2_nvs},
	}

	controlType := "ADDMOD"
	config := utils.Configuration{
		PolicyID:   2,
		PolicyType: "sliceGenericControl",
		Scope: utils.ScopeConfig{
			SliceID: 0,
			CellID:  3584,
		},
		Statement: utils.StatementConfig{
			CtrlType:       controlType,
			CtrlRequest:	addNvsSlicesCap,
		},
	}

	err = sendConfiguration(config)
	if err != nil {
		log.Printf("Failed to send configuration: %s", err)
	} else {
		log.Println("Configuration sent successfully, [controlType]: ", controlType)
	}

	time.Sleep(10 * time.Second)

	// ----------------- Second Policy ----------------- //
	ue := utils.Ue{
		Rnti:           0,
		AssocDlSliceId: 2,
	}
	assocUeSlice := utils.Request{
		NumUes: 1,
		Ues:    []utils.Ue{ue},
	}

	controlType = "ASSOC_UE_SLICE"
	config = utils.Configuration{
		PolicyID:   2,
		PolicyType: "sliceGenericControl",
		Scope: utils.ScopeConfig{
			SliceID: 0,
			CellID:  3584,
		},
		Statement: utils.StatementConfig{
			CtrlType:       controlType,
			CtrlRequest:	assocUeSlice,
		},
	}

	err = sendConfiguration(config)
	if err != nil {
		log.Printf("Failed to send configuration: %s", err)
	} else {
		log.Println("Configuration sent successfully, [controlType]: ", controlType)
	}

	time.Sleep(10 * time.Second)

	// ----------------- Third Policy ----------------- //
	ue = utils.Ue{
		Rnti:           0,
		AssocDlSliceId: 0,
	}
	assocUeSlice = utils.Request{
		NumUes: 1,
		Ues:    []utils.Ue{ue},
	}

	controlType = "ASSOC_UE_SLICE"
	config = utils.Configuration{
		PolicyID:   2,
		PolicyType: "sliceGenericControl",
		Scope: utils.ScopeConfig{
			SliceID: 0,
			CellID:  3584,
		},
		Statement: utils.StatementConfig{
			CtrlType:       controlType,
			CtrlRequest:	assocUeSlice,
		},
	}

	err = sendConfiguration(config)
	if err != nil {
		log.Printf("Failed to send configuration: %s", err)
	} else {
		log.Println("Configuration sent successfully, [controlType]: ", controlType)
	}

	time.Sleep(10 * time.Second)

	// ----------------- Finish ----------------- //
	url := "http://localhost:9000/api/finish"

	// Create the request body (if needed)
	// requestBody := []byte(`{"key": "value"}`)

	// Send the POST request
	resp, err = http.Post(url, "application/json", bytes.NewBuffer(nil)) // Replace nil with requestBody if you have a request body
	if err != nil {
		fmt.Println("Error sending request:", err)
		return
	}
	defer resp.Body.Close()

	// Check the response status code
	if resp.StatusCode != http.StatusOK {
		fmt.Println("Unexpected response status code:", resp.StatusCode)
		return
	}

	fmt.Println("POST request sent successfully")
}

func sendConfiguration(config utils.Configuration) error {
	payload, err := json.Marshal(config)
	if err != nil {
		return err
	}

	client := &http.Client{Timeout: 30 * time.Second}
	resp, err := client.Post(server1URL, "application/json", bytes.NewBuffer(payload))
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	if resp.StatusCode != http.StatusOK {
		body, _ := ioutil.ReadAll(resp.Body)
		return fmt.Errorf("failed to send configuration: %s", string(body))
	}

	return nil
}
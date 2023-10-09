package main

import "C"
import (
	xapp "build/examples/xApp/go/xapp_sdk"
	parser "build/examples/xApp/go/FlexPolicy/utils/parser"
	callbacks "build/examples/xApp/go/FlexPolicy/callbacks"
	sm "build/examples/xApp/go/FlexPolicy/utils/sm"
	api "build/examples/xApp/go/FlexPolicy/utils/api"

	"fmt"
	"time"
	"os"
)

func main() {

	// Initialization
	xapp.Init(xapp.SlToStrVec(os.Args))

	// Parse A1 parameters
	conf := os.Args[2]
	A1IP, A1Port, smList, policyID := parser.ParseXAppConfig(conf)

	// E2 Connect
	sm.E2Nodes = xapp.Conn_e2_nodes()

	var nodes_len int64 = sm.E2Nodes.Size()

	if nodes_len <= 0 {
		panic(fmt.Sprintf("panic"))
	}

	fmt.Printf("Connected E2 nodes = %d\n", nodes_len)

	// Subscribe to the SMs
	sm.SmSubscription(smList)

	// find policy callback id
	callback := callbacks.FindCallback(policyID)
	if callback == nil {
		fmt.Printf("Policy Callback with given ID %s not found.\n", policyID)
	} else{
		api.OpenA1Apis(callback, A1IP, A1Port)
	}

	// Unsubscribe from the SMs
	sm.SmUnsubscription(smList)

	// Stop the xApp. Avoid deadlock.
	for xapp.Try_stop() == false {
		time.Sleep(1 * time.Second)
	}

	fmt.Printf("Test xApp run SUCCESSFULLY\n")
	
}

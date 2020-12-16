PROGRAM _CYCLIC  
(* _____________________Description_____________________
This program functions as a OPC-UA client to connect to Ignition OPC server. It does not currently function; 
!!!!!!!!!!!!!!!!!! Ignition uses its client to connect to PLC server !!!!!!!!!!!!!!!!!!
*)
CASE steps OF
	Retain:
		steps := Connect;
		
		///////////////////////////////////////////// B&R OPC UA Guides available in F1 /Programming/Communication/Libraries/AsOpcUac/*	- are sometimes mentioned in the code /////////////////////////////////////////////////////////
	Connect: //Function block UA_Connect establishes a connection between the OPC UA client and an OPC UA server. Function block UA_Connect is executed only once per connection //https://www.rtautomation.com/rtas-blog/opc-ua-client-vs-server/
		SessionConnectInfo_0.SecurityMsgMode := UASecurityMsgMode_None;
		SessionConnectInfo_0.SecurityPolicy := UASecurityPolicy_None;
		SessionConnectInfo_0.TransportProfile := UATP_UATcp;
		SessionConnectInfo_0.UserIdentityToken.UserIdentityTokenType := UAUITT_Anonymous; //Type of authentication and login for a session (communication between OPC UA client and OPC UA server).
		//SessionConnectInfo_0.UserIdentityToken.TokenParam1 := 'admin';	//  username
		//SessionConnectInfo_0.UserIdentityToken.TokenParam2 := 'admin';	//  password 
		SessionConnectInfo_0.SessionName := 'PLC - Nord Modules'; //Put a name variable  If the string is empty, then the server generates a session name
		SessionConnectInfo_0.SessionTimeout := T#1m; 	
		SessionConnectInfo_0.MonitorConnection := T#50s; //After an active session has been set up with UA_Connect, monitoring of the connection begins. This is done by configuring parameter MonitorConnection in UASessionConnectInfo.
		
		UA_Connect_0(Execute := NOT UA_Connect_0.Done AND NOT UA_Connect_0.Error, //Function does not reset .Done and .Error until the empty (Execute := FALSE) call of this function is executed (atleast it seems to be working that way)
		ServerEndpointUrl := 'opc.tcp://172.20.1.1:4096',	//syntax opc.tcp://<ip-address>:<port>  
		SessionConnectInfo := SessionConnectInfo_0,
		Timeout := T#10s);	// When the timeout expires, the function block is terminated with the error number specified in ErrorID. 
		IF (UA_Connect_0.Busy = 0) THEN	//The function block has not yet finished executing. (=TRUE). 
			//ExecuteConnect_0 := 0;
			IF (UA_Connect_0.Done = 1) THEN	//Done: The connection between OPC UA server and OPC UA client was established successfully (TRUE). Gets set to 0 by calling previous step function
				em.description := 'Connection established succesfully'; 
				ErrorID := 0;
				ConnectionHdl := UA_Connect_0.ConnectionHdl; //OPC UA connection handle. Identifies the current connection for use as an input in function blocks. 
				steps := GetNamespaceIndex;
				
			END_IF
			IF (UA_Connect_0.Error = 1) THEN
				em.description := 'Connection establishment ERROR';
				ErrorID := DWORD_TO_UDINT(UA_Connect_0.ErrorID); 
				ConnectionHdl := 0;
				
				IF ErrorID = 2148139008 THEN //error 0xA0080000 - Bad Timeout - caused if there is no connection to be found //2684878848 
					em.description := 'Connection not found, reconnecting...';
					steps := Connect;	  
				ELSE
					steps := ErrorHandling;
				END_IF;
					
			END_IF
		END_IF
		
	ConnectionGetStatus: //explanation for ~/AsOpcUac/ErrorHandling/Connection Monitoring and ~/Restoring a connection
		UA_ConnectionGetStatus_0(Execute := NOT UA_ConnectionGetStatus_0.Done AND NOT UA_ConnectionGetStatus_0.Error, //ExecuteConnectionGetStatus_0,
		ConnectionHdl := ConnectionHdl,
		Timeout := T#10s);
		IF (UA_ConnectionGetStatus_0.Busy = 0) THEN
			ExecuteConnectionGetStatus_0 := 0;
			IF (UA_ConnectionGetStatus_0.Done = 1) THEN
				em.description := 'ConnectionGetStatus obtained, resolving results';
				ServerState := UA_ConnectionGetStatus_0.ServerState; // ~/AsOpcUac/Data types and constants/Enumerators/UAServerState							
				ServiceLevel := UA_ConnectionGetStatus_0.ServiceLevel;
				ConnectionStatus := UA_ConnectionGetStatus_0.ConnectionStatus;
				
				CASE ConnectionStatus OF
					UACS_Connected: //A UA client is connected to the UA server.
						em.description := 'UACS_Connected, moving onto writing/reading';
						ErrorID := 0;
						steps := WriteList; 
						//steps := NodeReleaseHandleList; //release the old handles and acquire new ones
					UACS_ConnectionError: //The connection from the UA client to the UA server is faulty.
						em.description := 'UACS_ConnectionERROR, keep obtaining ConnectionGetStatus';
						steps := ConnectionGetStatus;
					UACS_Shutdown: //The UA client has been disconnected from the UA server.
						em.description := 'UACS_Shutdown, Reconnecting...';
						steps := Connect;
				END_CASE;							
			END_IF
			IF (UA_ConnectionGetStatus_0.Error = 1) THEN
				em.description := 'ConnectionGetStatus ERROR';
				ErrorID := DWORD_TO_UDINT(UA_ConnectionGetStatus_0.ErrorID);
				ConnectionStatus := 0;
				steps := ErrorHandling;							
			END_IF
		END_IF
		
		
		
	GetNamespaceIndex:					
		(* UA_GetNamespaceIndex - read index of required namespace for PVs *)
		//Function block UA_GetNamespaceIndex reads the namespace index from the NamespaceUri area on the OPC UA server. Function block UA_GetNamespaceIndex is executed only once for each namespace.				
		UA_GetNamespaceIndex_0(Execute := NOT UA_GetNamespaceIndex_0.Done AND NOT UA_GetNamespaceIndex_0.Error, 
		ConnectionHdl := ConnectionHdl,
		NamespaceUri := 'urn:B&R/pv/', //Specifies the namespace URI. Example: The current "urn:B&R/pv/" Addresses namespace 6 (this contains the process variables on B&R controllers).
		Timeout := T#5s);
		
		IF (UA_GetNamespaceIndex_0.Busy = 0) THEN
			ExecuteGetnamespaceindex_0 := 0;
			IF (UA_GetNamespaceIndex_0.Done = 1) THEN
				em.description := 'NameSpaceIndex acquired';
				ErrorID := 0;
				NamespaceIndex := UA_GetNamespaceIndex_0.NamespaceIndex;							
				steps := NodeGetHandleList;										
			END_IF
			IF (UA_GetNamespaceIndex_0.Error = 1) THEN
				em.description := 'NameSpaceIndex ERROR';
				ErrorID := DWORD_TO_UDINT(UA_GetNamespaceIndex_0.ErrorID);
				NamespaceIndex := 0;				
				steps := ErrorHandling;
			END_IF
		END_IF
	
		
	NodeGetHandleList: //Function block UA_NodeGetHandle gets a handle for a defined node. This handle represents the node for other functions. Function block UA_NodeGetHandle is queried once per method. 					        
		//WRITE NODES
		NodeCount_W := 2;
		
	(*	NodeCount_W := NodeCount_W + 1;;
		NodeIDs_W[NodeCount_W].NamespaceIndex := NamespaceIndex;
		NodeIDs_W[NodeCount_W].Identifier := '::main:this.io.di_estop'; //'::server:mirFree'; //QuickMover config '::QuickMover:this.io.do_mirFree'
		NodeIDs_W[NodeCount_W].IdentifierType := UAIdentifierType_String; *)
		 
		//NodeCount_W := NodeCount_W + 1;;
		NodeIDs_W[0].NamespaceIndex := NamespaceIndex;
		NodeIDs_W[0].Identifier := '::main:New_Variable';//'::AsGlobalPV:radioComm.radioIN_plateDetect'; //'::server:pickupDropoff'; //QuickMover config '::QuickMover:this.io.di_pickupDropoff' //Addressing OPC UA variables
		NodeIDs_W[0].IdentifierType := UAIdentifierType_String; 
		
		//NodeCount_W := NodeCount_W + 1;
		NodeIDs_W[1].NamespaceIndex := NamespaceIndex;
		NodeIDs_W[1].Identifier := '::main:New_Variable1';//'::server:mirGo'; //QuickMover config '::QuickMover:this.io.di_mirGo'
		NodeIDs_W[1].IdentifierType := UAIdentifierType_String; 
		
		////Change to match NodeIDs_W[n] - This variable is used later on for clearing the array					
		UA_NodeGetHandleList_W(Execute := NOT UA_NodeGetHandleList_W.Done AND NOT UA_NodeGetHandleList_W.Error,
			ConnectionHdl := ConnectionHdl,
			NodeIDCount := NodeCount_W,
			NodeIDs := NodeIDs_W,
		Timeout := T#10s);
		
		IF (UA_NodeGetHandleList_W.Busy = 0) THEN
			//ExecuteNodeGetHandleList_0 := 0;
			IF (UA_NodeGetHandleList_W.Done = 1) THEN
				em.description := 'Node_Write created and handled';
				ErrorID := 0;
				NodeHdls_W := UA_NodeGetHandleList_W.NodeHdls;
					//steps := SubscriptionCreate;
			END_IF
			IF (UA_NodeGetHandleList_W.Error = 1) THEN
				em.description := 'Node_Write handle ERROR';
				ErrorID := DWORD_TO_UDINT(UA_NodeGetHandleList_W.ErrorID);
				FOR I := 0 TO NodeCount_W DO
					NodeHdls_W[I] := 0;
				END_FOR;
				steps := ErrorHandling;
			END_IF
		END_IF
		
		//READ NODES not used in current setup  
		NodeCount_R := 0;
		
		NodeIDs_R[0].NamespaceIndex := NamespaceIndex;
		NodeIDs_R[0].Identifier := '::main:New_Variable2';//'::AsGlobalPV:radioComm.radioOUT_mirAck';//'::server:mirPickupAck';
		NodeIDs_R[0].IdentifierType := UAIdentifierType_String;
		
		//NodeCount_R := NodeCount_R + 1;;
		
		UA_NodeGetHandleList_R(Execute := NOT UA_NodeGetHandleList_R.Done AND NOT UA_NodeGetHandleList_R.Error,
			ConnectionHdl := ConnectionHdl,
			NodeIDCount := 1,
			NodeIDs := NodeIDs_R,
		Timeout := T#10s);
		
		IF (UA_NodeGetHandleList_R.Busy = 0) THEN
		//ExecuteNodeGetHandleList_0 := 0;
			IF (UA_NodeGetHandleList_R.Done = 1) THEN
				em.description := 'Node_Read created and handled';
				ErrorID := 0;
				NodeHdls_R := UA_NodeGetHandleList_R.NodeHdls; 							
				IF (UA_NodeGetHandleList_W.Done = 1) THEN //ensures the process moves to next step only if both nodes are being handled							
					steps := SubscriptionCreate;
				END_IF
				
			END_IF
			IF (UA_NodeGetHandleList_R.Error = 1) THEN
				em.description := 'Node_Read handle ERROR';
				ErrorID := DWORD_TO_UDINT(UA_NodeGetHandleList_R.ErrorID);
				FOR I := 0 TO NodeCount_R DO
					NodeHdls_R[I] := 0;
				END_FOR;
				steps := ErrorHandling;
			END_IF
		END_IF 
		
	SubscriptionCreate: //UA_SubscriptionCreate - creates a subscription (TO receive information about changes TO the values OF defined variables) on the OPC UA client. The OPC UA server monitors the variables AND sends notification when a value changes.
		PublishingInterval := T#1s;
		PublishingEnable := TRUE;
		
		UA_SubscriptionCreate_0(Execute := NOT UA_SubscriptionCreate_0.Done AND NOT UA_SubscriptionCreate_0.Error,
			ConnectionHdl := ConnectionHdl,
			PublishingEnable := PublishingEnable,
			Priority := 10,
			Timeout := T#10s,
		PublishingInterval := PublishingInterval);
		
		IF (UA_SubscriptionCreate_0.Busy = 0) THEN
			//ExecuteSubscriptionCreate_0 := 0;
			IF (UA_SubscriptionCreate_0.Done = 1) THEN
				em.description := 'Subscription created';
				SubscriptionHdl := UA_SubscriptionCreate_0.SubscriptionHdl;
					steps := MonitoredItemAddList;
				
			END_IF
			IF (UA_SubscriptionCreate_0.Error = 1) THEN
				em.description := 'Subscription ERROR';
				ErrorID := DWORD_TO_UDINT(UA_SubscriptionCreate_0.ErrorID);
				SubscriptionHdl := 0;
					steps := ErrorHandling;
			END_IF
		END_IF
		
	MonitoredItemAddList: (* UA_MonitoredItemAdd - Registers a list of variables (monitored items) to be monitored on the OPC UA server so that the OPC UA client is informed when their values change *)
		NodeAddInfos_0[0].AttributeId := UAAI_Value;
		NodeAddInfos_0[0].IndexRangeCount := 0;
		MonitoringSettings_0[0].SamplingInterval := T#1s;//Interval in milliseconds at which the data source is checked for changes
		//MonitoringSettings_0[0].QueueSize := 0; //Size of the value change queue on the server. QueueSize = 0: The values in the queue are automatically transferred TO the process variable. QueueSize > 0: The values in the queue are transferred when function block UA_MonitoredItemOperate OR UA_MonitoredItemOperateList is called.
							
		Variables_0[0] := '::conveyor:this.io.di_mirPickupAck'; //'::QuickMover:this.io.di_mirPickupAck'; //Has to be implemented to QM, since in there it is called smthing else
		
		UA_MonitoredItemAddList_0(Execute := NOT UA_MonitoredItemAddList_0.Done AND NOT UA_MonitoredItemAddList_0.Error,
			SubscriptionHdl := SubscriptionHdl,
(* Changes *)			NodeHdlCount := 1,
			NodeHdls := NodeHdls_R,
			NodeAddInfos := NodeAddInfos_0,
			Timeout := T#10s,
			Variables := Variables_0,
			MonitoringSettings := MonitoringSettings_0,
			ValuesChanged :=  ValuesChanged_0,
			RemainingValueCount := RemainingValueCount_0,
			TimeStamps := TimeStamps_0, 
		NodeQualityIDs := NodeQualityIDs_0);
		
		IF (UA_MonitoredItemAddList_0.Busy = 0) THEN
			//ExecuteMonitoredItemAddList_0 := 0;
			IF (UA_MonitoredItemAddList_0.Done = 1) THEN
				em.description := 'MonitoredItemAddList created';
				MonitoredItemHdls := UA_MonitoredItemAddList_0.MonitoredItemHdls;
					steps := WriteList;
			END_IF
			IF (UA_MonitoredItemAddList_0.Error = 1) THEN
				ErrorID := DWORD_TO_UDINT(UA_MonitoredItemAddList_0.ErrorID);
				em.description := 'MonitoredItemAddList ERROR';
				MonitoredItemHdls[NodeHdlCount] := 0;
				steps := ErrorHandling;
			END_IF
		END_IF
	
	WriteList: //UA_WriteList - write local plc variables to required nodes from OPC UA Server
		(* Y *)   
	(*	FOR I := 0 TO NodeCount_W DO
			NodeAddInfos_W[NodeCount_W].AttributeId := UAAI_Value;
			NodeAddInfos_W[NodeCount_W].IndexRangeCount := 0;
		END_FOR *)
		NodeAddInfos_W[0].AttributeId := UAAI_Value;
		NodeAddInfos_W[0].IndexRangeCount := 0;
		NodeAddInfos_W[1].AttributeId := UAAI_Value;
		NodeAddInfos_W[1].IndexRangeCount := 0;
			
			
		//	Variables_Wr0[0] := '::conveyor:this.io.do_mirFree';
		Variables_Wr0[0] := '::conveyor:this.io.do_pickupDropoff'; 
		Variables_Wr0[1] := '::conveyor:this.io.do_mirGo'; 
	            
		UA_WriteList_0(Execute := NOT UA_WriteList_0.Done AND NOT UA_WriteList_0.Error, //Runs on Execute := FALSE  until either .Done or .Error gets cleared by itself (the function clears it I guess)
			ConnectionHdl := ConnectionHdl,
			NodeHdlCount := NodeCount_W,
			NodeHdls := NodeHdls_W,
			NodeAddInfo := NodeAddInfos_W,
			Timeout := T#10s,
		Variables := Variables_Wr0);
		
		IF (UA_WriteList_0.Busy = 0 ) THEN 
			//ExecuteWriteList_0 := 0;
			IF (UA_WriteList_0.Done = 1) THEN
				em.description := 'Write successful';
				ErrorID := 0;
				//steps := NodeGetHandleList;									
			END_IF
			IF (UA_WriteList_0.Error = 1) THEN
				em.description := 'Write ERROR';
				ErrorID := DWORD_TO_UDINT(UA_WriteList_0.ErrorID);
					steps := ErrorHandling;
			END_IF
		END_IF 
		
	ReadList: //Function block UA_Read reads the value of a variable from a single node. Read access can occur at any interval permitted/limited by the system.					
		NodeAddInfos_R[0].AttributeId := UAAI_Value;
		NodeAddInfos_R[0].IndexRangeCount := 0;
		Variables_Rd0[0] := '::conveyor:this.io.di_mirPickupAck';
		
		UA_ReadList_0(Execute := NOT UA_ReadList_0.Done AND NOT UA_ReadList_0.Error,
			ConnectionHdl := ConnectionHdl,
			NodeHdlCount := 1, 
			NodeHdls := NodeHdls_R,
			NodeAddInfo := NodeAddInfos_R,
			Timeout := T#10s,
		Variables := Variables_Rd0);

		IF (UA_ReadList_0.Busy = 0 ) THEN 
			//ExecuteReadList_0 := FALSE;
			IF (UA_ReadList_0.Done = 1) THEN
				em.description := 'Read succesful';
				ErrorID := 0;
					steps := WriteList;	
			END_IF
			IF (UA_ReadList_0.Error = 1) THEN 
				em.description := 'Read ERROR';
				ErrorID := DWORD_TO_UDINT(UA_ReadList_0.ErrorID);
					steps := ErrorHandling;
			END_IF
		END_IF

	NodeReleaseHandleList: //Function block UA_NodeReleaseHandle frees up the handle for a node. Function block UA_NodeReleaseHandle is called only once per node					     
		UA_NodeReleaseHandleList_W(Execute := NOT UA_NodeReleaseHandleList_W.Done AND NOT UA_NodeReleaseHandleList_W.Error, //.Done gets reset by calling any read/write UA_function
			ConnectionHdl := ConnectionHdl,
			NodeHdlCount := NodeCount_W,
			NodeHdls := NodeHdls_W,
		Timeout := T#10s);
		
		IF (UA_NodeReleaseHandleList_W.Busy = 0) THEN
			IF (UA_NodeReleaseHandleList_W.Done = 1) THEN
				em.description := 'Node_W released';
				ErrorID := 0;
				FOR I := 0 TO NodeCount_W DO
					NodeHdls_W[NodeCount_W] := 0;
				END_FOR;
					steps := MonitoredItemRemoveList;
				
			END_IF
			IF (UA_NodeReleaseHandleList_W.Error = 1) THEN
				em.description := 'Node_W release ERROR';
				ErrorID := DWORD_TO_UDINT(UA_NodeReleaseHandleList_W.ErrorID);
				FOR I := 0 TO NodeCount_W DO
					NodeHdls_W[I] := 0;
				END_FOR;	
					steps := ErrorHandling;
			END_IF
		END_IF
		
		//READ ReleaseHandles
		UA_NodeReleaseHandleList_R(Execute := NOT UA_NodeReleaseHandleList_R.Done AND NOT UA_NodeReleaseHandleList_0.Error,
			ConnectionHdl := ConnectionHdl,
			NodeHdlCount := NodeCount_R,
			NodeHdls := NodeHdls_R,
		Timeout := T#10s);
		IF (UA_NodeReleaseHandleList_R.Busy = 0) THEN
			IF (UA_NodeReleaseHandleList_R.Done = 1) THEN
				em.description := 'Node_R released';
				ErrorID := 0;
				FOR I := 0 TO NodeCount_R DO
					NodeHdls_R[I] := 0;
				END_FOR;
				IF (UA_NodeReleaseHandleList_W.Done = 1) THEN //makes sure it moves to next step only if both handles are released								
					steps := NodeGetHandleList;
				END_IF														
			END_IF
			
			IF (UA_NodeReleaseHandleList_0.Error = 1) THEN
				em.description := 'Node_R release ERROR';
				ErrorID := DWORD_TO_UDINT(UA_NodeReleaseHandleList_0.ErrorID);
				FOR I := 0 TO NodeCount_R DO
					NodeHdls_R[I] := 0;
				END_FOR;
					steps := ErrorHandling;
				END_IF
			END_IF 
		
	MonitoredItemRemoveList:
		UA_MonitoredItemRemoveList_0(Execute := NOT UA_MonitoredItemRemoveList_0.Done AND NOT UA_MonitoredItemRemoveList_0.Error, 
			SubscriptionHdl := SubscriptionHdl, 
			MonitoredItemHdlCount := NodeCount_R, 
			MonitoredItemHdls := MonitoredItemHdls, 
		Timeout := T#10s);
		
		IF (UA_MonitoredItemRemoveList_0.Busy = 0) THEN
			ExecuteMonitoredItemRemove_0 := 0;
			IF (UA_MonitoredItemRemoveList_0.Done = 1) THEN
				em.description := 'MonitoredItemRemoveList removed';
				MonitoredItemHdls[NodeCount_R] := 0;
					steps := SubscriptionDelete;
			END_IF
			IF (UA_MonitoredItemRemoveList_0.Error = 1) THEN
				em.description := 'MonitoredItemRemoveList ERROR';
				ErrorID := DWORD_TO_UDINT(UA_MonitoredItemRemoveList_0.ErrorID);
				MonitoredItemHdls[NodeCount_R] := 0;
					steps := ErrorHandling;
			END_IF
		END_IF
		
	SubscriptionDelete:
		UA_SubscriptionDelete_0(Execute := NOT UA_SubscriptionDelete_0.Done AND NOT UA_SubscriptionDelete_0.Error,
			SubscriptionHdl := SubscriptionHdl,
		Timeout := T#10s);
		IF (UA_SubscriptionDelete_0.Busy = 0) THEN
			ExecuteSubscriptionDelete_0 := 0;
			IF (UA_SubscriptionDelete_0.Done = 1) THEN
				em.description := 'SubscriptionDelete done';
				SubscriptionHdl := 0;
					steps := Disconnect;
			END_IF
			IF (UA_SubscriptionDelete_0.Error = 1) THEN
				em.description := 'SubscriptionDelete ERROR';
				ErrorID := DWORD_TO_UDINT(UA_SubscriptionDelete_0.ErrorID);
				SubscriptionHdl := 0;
					steps := ErrorHandling;
			END_IF
		END_IF
		
	Disconnect: //Function block UA_Disconnect closes the connection between the OPC UA client and an OPC UA server. The connection is also closed in the event of error or timeout. Function block UA_Disconnect is executed only once per connection.
		UA_Disconnect_0(Execute := NOT UA_Disconnect_0.Done AND NOT UA_Disconnect_0.Error, //.Done get reset by calling UA_NodeReleaseHandle function
			ConnectionHdl := ConnectionHdl,
		Timeout := T#10s);
		IF (UA_Disconnect_0.Busy = 0) THEN
			IF (UA_Disconnect_0.Done = 1) THEN
				em.description := 'Disconnected';
				ErrorID := 0;
				ConnectionHdl := 0;
					steps := Connect;
				//gClient.status.complete := TRUE;
			END_IF
			IF (UA_Disconnect_0.Error = 1) THEN
				em.description := 'Disconnect ERROR';
				ErrorID := DWORD_TO_UDINT(UA_Disconnect_0.ErrorID);
				ConnectionHdl := 0;
					steps := ErrorHandling;
			END_IF
		END_IF
		
	ErrorHandling: 
		em.description := 'ERROR - being resolved';
		
		CASE ErrorID OF //the .ErrorIDs variables get written in a syntax of 16#80AD_0000, therefore the decimal value is a little bit different that what a normal converter would give, but I don't think that is going to cause any long term issues, hopefully.
			2148139008: //Bad_Timeout 0xA0080000 OR 2684878848? // Remote system down or connection broken 
				steps := ConnectionGetStatus;
			2158821376: //0x80AD0000 Bad_Disconnect 
				steps := ConnectionGetStatus;
			2684878848: //0xA0080000 Intended ConnectionHdl is unknown.  - ConnectionHdl = 0
				steps := Connect;
			2153119744: //0x80560000The server has reached its maximum number of sessions. 
				em.description := 'The server has reached its maximum number of sessions';
				//steps? Gotta restard the handles and fix autoconnecting
			2147811328://Bad_CommunicationError 0x80050000 A low level communication error occurred. 
				//steps? 
			2685140992, 2150825984:// PlcOpen_BadNodeInvalidHdl 0xA00C0000 Intended NodeHdl is unknown OR Bad_NodeIdUnknown 0x80340000 The node ID refers to a node that does not exist in the server address space.
				//fix NodeHandle NodeID's variable name
			2155085824: //Bad_TypeMismatch 0x80740000 The value provided for the attribute is not of the same type as the attribute's value 
				//steps := UA_NodeGetInfo //UA_NodeGetInfo.DataType then convert
			2148466688: //Bad_NothingToDo 0x800F0000 There was nothing to do because the client passed a list of operations with no elements 
				//check what and how many NodeHdlCount you are passing (if you have 1 node handle, then it is 0th handle but you have to pass 1 handle count							
											
			
			ELSE
				steps := ConnectionGetStatus;
		END_CASE; 
	
END_CASE

END_PROGRAM

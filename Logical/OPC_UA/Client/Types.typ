
TYPE
	opc_steps : 
		(
		Retain,
		Connect,
		ConnectionGetStatus,
		GetNamespaceIndex,
		NodeGetHandle,
		NodeGetHandleList,
		SubscriptionCreate,
		MonitoredItemAdd,
		MonitoredItemAddList,
		MonitoredItemOperateList,
		MonitoredItemRemoveList,
		SubscriptionDelete,
		WriteList,
		ReadList,
		NodeReleaseHandle,
		NodeReleaseHandleList,
		ErrorHandling,
		Disconnect
		);
	Structure_type : 	STRUCT 
		description : STRING[80];
	END_STRUCT;
END_TYPE

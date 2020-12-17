
TYPE
	io_type : 	STRUCT 
		Mission_startButton : BOOL;
	END_STRUCT;
	modbus_type : 	STRUCT 
		Attachment_Type : UINT := 10; (*Value uniquely identifying the type of attachment. Unsigned int 16:: 76 LIFT / 67 CONVEYOR*)
		HoldReg : UDINT;
		Safe_to_Move : BOOL;
		Mission_create_0 : UINT;
	END_STRUCT;
END_TYPE

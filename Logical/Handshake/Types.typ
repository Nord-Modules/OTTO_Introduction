
TYPE
	GPIO_Hanshake_type : 	STRUCT 
		ROBOT_ENABLE : BOOL;
		PA_FAULT_STATUS : BOOL;
		PA_ENABLE : BOOL;
	END_STRUCT;
	io_type : 	STRUCT 
		handshake : GPIO_Hanshake_type;
		LED : BOOL;
	END_STRUCT;
END_TYPE

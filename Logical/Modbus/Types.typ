
TYPE
	modbus_type : 	STRUCT 
		Attachment_Type : INT; (*Value uniquely identifying the type of attachment. Unsigned int 16:: 76 LIFT / 67 CONVEYOR*)
		Safe_to_Move : BOOL;
	END_STRUCT;
END_TYPE

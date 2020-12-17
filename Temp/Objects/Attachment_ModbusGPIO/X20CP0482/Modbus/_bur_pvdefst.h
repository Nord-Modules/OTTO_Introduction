#ifndef __AS__TYPE_modbus_type
#define __AS__TYPE_modbus_type
typedef struct modbus_type
{	unsigned short Attachment_Type;
	unsigned long HoldReg;
	plcbit Safe_to_Move;
	unsigned short Create_mission_1;
	unsigned short Create_mission_0;
} modbus_type;
#endif

_BUR_LOCAL modbus_type modbus;

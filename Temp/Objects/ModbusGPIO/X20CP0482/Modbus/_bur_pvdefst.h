#ifndef __AS__TYPE_modbus_type
#define __AS__TYPE_modbus_type
typedef struct modbus_type
{	unsigned short Attachment_Type;
	unsigned long HoldReg;
	plcbit Safe_to_Move;
} modbus_type;
#endif

_BUR_LOCAL modbus_type modbus;

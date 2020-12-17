#ifndef __AS__TYPE_io_type
#define __AS__TYPE_io_type
typedef struct io_type
{	plcbit Mission_startButton;
} io_type;
#endif

#ifndef __AS__TYPE_modbus_type
#define __AS__TYPE_modbus_type
typedef struct modbus_type
{	unsigned short Attachment_Type;
	unsigned long HoldReg;
	plcbit Safe_to_Move;
	unsigned short Mission_create_0;
} modbus_type;
#endif

_BUR_LOCAL unsigned short counter;
_BUR_LOCAL io_type io;
_BUR_LOCAL modbus_type modbus;

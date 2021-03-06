/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1608210651_1_
#define _BUR_1608210651_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct io_type
{	plcbit Mission_startButton;
} io_type;

typedef struct modbus_type
{	unsigned short Attachment_Type;
	unsigned long HoldReg;
	plcbit Safe_to_Move;
	unsigned short Mission_create_0;
} modbus_type;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Modbus/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1608210651_1_ */


/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1608196443_2_
#define _BUR_1608196443_2_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct GPIO_Hanshake_type
{	plcbit ROBOT_ENABLE;
	plcbit PA_FAULT_STATUS;
	plcbit PA_ENABLE;
} GPIO_Hanshake_type;

typedef struct io_type
{	struct GPIO_Hanshake_type handshake;
	plcbit LED;
} io_type;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Handshake/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1608196443_2_ */


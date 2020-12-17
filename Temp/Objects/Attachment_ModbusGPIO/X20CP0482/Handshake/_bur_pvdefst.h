#ifndef __AS__TYPE_GPIO_Hanshake_type
#define __AS__TYPE_GPIO_Hanshake_type
typedef struct GPIO_Hanshake_type
{	plcbit ROBOT_ENABLE;
	plcbit PA_FAULT_STATUS;
	plcbit PA_ENABLE;
} GPIO_Hanshake_type;
#endif

#ifndef __AS__TYPE_io_type
#define __AS__TYPE_io_type
typedef struct io_type
{	GPIO_Hanshake_type handshake;
	plcbit LED;
} io_type;
#endif

struct TON
{	plctime PT;
	plctime ET;
	plctime StartTime;
	unsigned long Restart;
	plcbit IN;
	plcbit Q;
	plcbit M;
};
_BUR_PUBLIC void TON(struct TON* inst);
_BUR_LOCAL io_type io;
_BUR_LOCAL struct TON timer;

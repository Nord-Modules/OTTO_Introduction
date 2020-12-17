#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/Attachment_ModbusGPIO/X20CP0482/Handshake/handshakest.h"
#line 1 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Handshake/handshake.nodebug"
#line 1 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Handshake/handshake.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

(io.handshake.PA_FAULT_STATUS=1);
(io.handshake.ROBOT_ENABLE=1);


(timer.PT=1000);

}}
#line 9 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Handshake/handshake.nodebug"
#line 11 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Handshake/handshake.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


if(io.handshake.PA_ENABLE){
(io.handshake.ROBOT_ENABLE=0);
(io.LED=1);
(timer.IN=1);
}


if(timer.Q){
(timer.IN=0);
(io.handshake.ROBOT_ENABLE=1);
(io.LED=0);
}

TON(&timer);
}}
#line 28 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Handshake/handshake.nodebug"

void __AS__ImplInithandshake_st(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUac/AsOpcUac.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUas/AsOpcUas.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUac/AsOpcUac.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUas/AsOpcUas.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUac/AsOpcUac.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUas/AsOpcUas.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Handshake/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Handshake/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/Attachment_ModbusGPIO/X20CP0482/Handshake/handshake.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/Attachment_ModbusGPIO/X20CP0482/Handshake/handshake.st.c\\\" \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Handshake/handshake.st\\\"\\n\"");
__asm__(".previous");

#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/ModbusForIgnition/X20CP0482/Modbus/modbusst.h"
#line 1 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Modbus/modbus.nodebug"
#line 2 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Modbus/modbus.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

}}
#line 4 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Modbus/modbus.nodebug"
#line 6 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Modbus/modbus.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{







if((io.Mission_startButton&~Edge0000100000&1?((Edge0000100000=io.Mission_startButton&1),1):((Edge0000100000=io.Mission_startButton&1),0))){
(counter=(counter+1));
}
(modbus.Mission_create_0=counter);

}}
#line 19 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Modbus/modbus.nodebug"

void __AS__ImplInitmodbus_st(void){__BUR__ENTRY_INIT_FUNCT__();}

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
__asm__(".ascii \"iecfile \\\"Logical/Modbus/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Modbus/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/ModbusForIgnition/X20CP0482/Modbus/modbus.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/ModbusForIgnition/X20CP0482/Modbus/modbus.st.c\\\" \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/Modbus/modbus.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/ModbusForIgnition/X20CP0482/Modbus/modbus.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");

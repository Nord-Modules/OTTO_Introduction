#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/mafio/OneDrive/BandR/OTTO/Temp/Objects/Config1/X20CP0482/Attachment/Modbusst.h"
#line 1 "C:/Users/mafio/OneDrive/BandR/OTTO/Logical/Libraries/Attachment/Modbus.nodebug"
#line 1 "C:/Users/mafio/OneDrive/BandR/OTTO/Logical/Libraries/Attachment/Modbus.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

(timer.PT=1000);
(LiftToggleON=1);
(modbus.Attachment_Type=76);
}}
#line 6 "C:/Users/mafio/OneDrive/BandR/OTTO/Logical/Libraries/Attachment/Modbus.nodebug"
#line 8 "C:/Users/mafio/OneDrive/BandR/OTTO/Logical/Libraries/Attachment/Modbus.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{
(timer.IN=1);

if((timer.Q&LiftToggleON)){
(timer.IN=0);

(LiftToggleON=0);

(modbus.Lift_Raise=1);
(modbus.Lift_Lower=0);

}

if((timer.Q&(LiftToggleON^1))){
(timer.IN=0);

(LiftToggleON=1);

(modbus.Lift_Raise=0);
(modbus.Lift_Lower=1);

}

TON(&timer);
}}
#line 32 "C:/Users/mafio/OneDrive/BandR/OTTO/Logical/Libraries/Attachment/Modbus.nodebug"

void __AS__ImplInitModbus_st(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Attachment/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Attachment/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/mafio/OneDrive/BandR/OTTO/Temp/Objects/Config1/X20CP0482/Attachment/Modbus.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/mafio/OneDrive/BandR/OTTO/Temp/Objects/Config1/X20CP0482/Attachment/Modbus.st.c\\\" \\\"C:/Users/mafio/OneDrive/BandR/OTTO/Logical/Libraries/Attachment/Modbus.st\\\"\\n\"");
__asm__(".previous");

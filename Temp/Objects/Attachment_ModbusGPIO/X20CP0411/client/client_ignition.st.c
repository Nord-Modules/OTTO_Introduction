#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/Config1/X20CP0411/client/client_ignitionst.h"
#line 1 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/OPC_UA/client/client_ignition.nodebug"
#line 1 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/OPC_UA/client/client_ignition.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


switch(steps){
case 0:{



}break;case 1:{
(SessionConnectInfo_0.SecurityMsgMode=1);
(SessionConnectInfo_0.SecurityPolicy=1);
(SessionConnectInfo_0.TransportProfile=1);
(SessionConnectInfo_0.UserIdentityToken.UserIdentityTokenType=0);


{int zzIndex; plcstring* zzLValue=(plcstring*)SessionConnectInfo_0.SessionName; plcstring* zzRValue=(plcstring*)"PLC - Nord Modules"; for(zzIndex=0; zzIndex<18l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SessionConnectInfo_0.SessionTimeout=60000);
(SessionConnectInfo_0.MonitorConnection=50000);




(UA_Connect_0.Execute=((UA_Connect_0.Done^1)&(UA_Connect_0.Error^1)));;{int zzIndex; plcstring* zzLValue=(plcstring*)UA_Connect_0.ServerEndpointUrl; plcstring* zzRValue=(plcstring*)"opc.tcp://192.168.1.7:4096"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};;(UA_Connect_0.SessionConnectInfo=*(struct UASessionConnectInfo*)&SessionConnectInfo_0);;(UA_Connect_0.Timeout=10000);;UA_Connect(&UA_Connect_0);
if((((unsigned long)(unsigned char)UA_Connect_0.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_Connect_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Connection established succesfully"; for(zzIndex=0; zzIndex<34l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
(ConnectionHdl=UA_Connect_0.ConnectionHdl);
(steps=3);

}
if((((unsigned long)(unsigned char)UA_Connect_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Connection establishment ERROR"; for(zzIndex=0; zzIndex<30l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_Connect_0.ErrorID);
(ConnectionHdl=0);

if((((unsigned long)ErrorID==(unsigned long)2148139008))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Connection not found, reconnecting..."; for(zzIndex=0; zzIndex<37l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(steps=1);
}else{
(steps=16);
}

}
}

}break;case 2:{


(UA_ConnectionGetStatus_0.Execute=((UA_ConnectionGetStatus_0.Done^1)&(UA_ConnectionGetStatus_0.Error^1)));;(UA_ConnectionGetStatus_0.ConnectionHdl=ConnectionHdl);;(UA_ConnectionGetStatus_0.Timeout=10000);;UA_ConnectionGetStatus(&UA_ConnectionGetStatus_0);
if((((unsigned long)(unsigned char)UA_ConnectionGetStatus_0.Busy==(unsigned long)(unsigned char)0))){
(ExecuteConnectionGetStatus_0=0);
if((((unsigned long)(unsigned char)UA_ConnectionGetStatus_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"ConnectionGetStatus obtained, resolving results"; for(zzIndex=0; zzIndex<47l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ServerState=UA_ConnectionGetStatus_0.ServerState);
(ServiceLevel=UA_ConnectionGetStatus_0.ServiceLevel);
(ConnectionStatus=UA_ConnectionGetStatus_0.ConnectionStatus);

switch(ConnectionStatus){
case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"UACS_Connected, moving onto writing/reading"; for(zzIndex=0; zzIndex<43l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
(steps=12);

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"UACS_ConnectionERROR, keep obtaining ConnectionGetStatus"; for(zzIndex=0; zzIndex<56l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(steps=2);
}break;case 2:{
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"UACS_Shutdown, Reconnecting..."; for(zzIndex=0; zzIndex<30l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(steps=1);
}break;}
}
if((((unsigned long)(unsigned char)UA_ConnectionGetStatus_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"ConnectionGetStatus ERROR"; for(zzIndex=0; zzIndex<25l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_ConnectionGetStatus_0.ErrorID);
(ConnectionStatus=0);
(steps=16);
}
}



}break;case 3:{





(UA_GetNamespaceIndex_0.Execute=((UA_GetNamespaceIndex_0.Done^1)&(UA_GetNamespaceIndex_0.Error^1)));;(UA_GetNamespaceIndex_0.ConnectionHdl=ConnectionHdl);;{int zzIndex; plcstring* zzLValue=(plcstring*)UA_GetNamespaceIndex_0.NamespaceUri; plcstring* zzRValue=(plcstring*)"urn:B&R/pv/"; for(zzIndex=0; zzIndex<11l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};;(UA_GetNamespaceIndex_0.Timeout=5000);;UA_GetNamespaceIndex(&UA_GetNamespaceIndex_0);

if((((unsigned long)(unsigned char)UA_GetNamespaceIndex_0.Busy==(unsigned long)(unsigned char)0))){
(ExecuteGetnamespaceindex_0=0);
if((((unsigned long)(unsigned char)UA_GetNamespaceIndex_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"NameSpaceIndex acquired"; for(zzIndex=0; zzIndex<23l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
(NamespaceIndex=UA_GetNamespaceIndex_0.NamespaceIndex);
(steps=5);
}
if((((unsigned long)(unsigned char)UA_GetNamespaceIndex_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"NameSpaceIndex ERROR"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_GetNamespaceIndex_0.ErrorID);
(NamespaceIndex=0);
(steps=16);
}
}


}break;case 5:{

(NodeCount_W=2);







(NodeIDs_W[0].NamespaceIndex=NamespaceIndex);
{int zzIndex; plcstring* zzLValue=(plcstring*)NodeIDs_W[0].Identifier; plcstring* zzRValue=(plcstring*)"::main:New_Variable"; for(zzIndex=0; zzIndex<19l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(NodeIDs_W[0].IdentifierType=1);


(NodeIDs_W[1].NamespaceIndex=NamespaceIndex);
{int zzIndex; plcstring* zzLValue=(plcstring*)NodeIDs_W[1].Identifier; plcstring* zzRValue=(plcstring*)"::main:New_Variable1"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(NodeIDs_W[1].IdentifierType=1);






(UA_NodeGetHandleList_W.Execute=((UA_NodeGetHandleList_W.Done^1)&(UA_NodeGetHandleList_W.Error^1)));;(UA_NodeGetHandleList_W.ConnectionHdl=ConnectionHdl);;(UA_NodeGetHandleList_W.NodeIDCount=NodeCount_W);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_NodeGetHandleList_W.NodeIDs; unsigned char* zzRValue=(unsigned char*)NodeIDs_W; for(zzIndex=0; zzIndex<16896l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_NodeGetHandleList_W.Timeout=10000);;UA_NodeGetHandleList(&UA_NodeGetHandleList_W);

if((((unsigned long)(unsigned char)UA_NodeGetHandleList_W.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_NodeGetHandleList_W.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_Write created and handled"; for(zzIndex=0; zzIndex<30l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
{int zzIndex; unsigned char* zzLValue=(unsigned char*)NodeHdls_W; unsigned char* zzRValue=(unsigned char*)UA_NodeGetHandleList_W.NodeHdls; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};

}
if((((unsigned long)(unsigned char)UA_NodeGetHandleList_W.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_Write handle ERROR"; for(zzIndex=0; zzIndex<23l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_NodeGetHandleList_W.ErrorID);
for((I=0);I<=NodeCount_W;I+=1){
(NodeHdls_W[I]=0);
}imp1_endfor15_0:;
(steps=16);
}
}


(NodeCount_R=0);

(NodeIDs_R[0].NamespaceIndex=NamespaceIndex);
{int zzIndex; plcstring* zzLValue=(plcstring*)NodeIDs_R[0].Identifier; plcstring* zzRValue=(plcstring*)"::main:New_Variable2"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(NodeIDs_R[0].IdentifierType=1);







(UA_NodeGetHandleList_R.Execute=((UA_NodeGetHandleList_R.Done^1)&(UA_NodeGetHandleList_R.Error^1)));;(UA_NodeGetHandleList_R.ConnectionHdl=ConnectionHdl);;(UA_NodeGetHandleList_R.NodeIDCount=1);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_NodeGetHandleList_R.NodeIDs; unsigned char* zzRValue=(unsigned char*)NodeIDs_R; for(zzIndex=0; zzIndex<16896l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_NodeGetHandleList_R.Timeout=10000);;UA_NodeGetHandleList(&UA_NodeGetHandleList_R);

if((((unsigned long)(unsigned char)UA_NodeGetHandleList_R.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_NodeGetHandleList_R.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_Read created and handled"; for(zzIndex=0; zzIndex<29l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
{int zzIndex; unsigned char* zzLValue=(unsigned char*)NodeHdls_R; unsigned char* zzRValue=(unsigned char*)UA_NodeGetHandleList_R.NodeHdls; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};
if((((unsigned long)(unsigned char)UA_NodeGetHandleList_W.Done==(unsigned long)(unsigned char)1))){
(steps=6);
}

}
if((((unsigned long)(unsigned char)UA_NodeGetHandleList_R.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_Read handle ERROR"; for(zzIndex=0; zzIndex<22l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_NodeGetHandleList_R.ErrorID);
for((I=0);I<=NodeCount_R;I+=1){
(NodeHdls_R[I]=0);
}imp1_endfor20_0:;
(steps=16);
}
}

}break;case 6:{
(PublishingInterval=1000);
(PublishingEnable=1);






(UA_SubscriptionCreate_0.Execute=((UA_SubscriptionCreate_0.Done^1)&(UA_SubscriptionCreate_0.Error^1)));;(UA_SubscriptionCreate_0.ConnectionHdl=ConnectionHdl);;(UA_SubscriptionCreate_0.PublishingEnable=PublishingEnable);;(UA_SubscriptionCreate_0.Priority=10);;(UA_SubscriptionCreate_0.Timeout=10000);;UA_SubscriptionCreate_0.PublishingInterval=&PublishingInterval;UA_SubscriptionCreate(&UA_SubscriptionCreate_0);

if((((unsigned long)(unsigned char)UA_SubscriptionCreate_0.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_SubscriptionCreate_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Subscription created"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SubscriptionHdl=UA_SubscriptionCreate_0.SubscriptionHdl);
(steps=8);

}
if((((unsigned long)(unsigned char)UA_SubscriptionCreate_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Subscription ERROR"; for(zzIndex=0; zzIndex<18l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_SubscriptionCreate_0.ErrorID);
(SubscriptionHdl=0);
(steps=16);
}
}

}break;case 8:{
(NodeAddInfos_0[0].AttributeId=13);
(NodeAddInfos_0[0].IndexRangeCount=0);
(MonitoringSettings_0[0].SamplingInterval=1000);


{int zzIndex; plcstring* zzLValue=(plcstring*)Variables_0[0]; plcstring* zzRValue=(plcstring*)"::conveyor:this.io.di_mirPickupAck"; for(zzIndex=0; zzIndex<34l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};












(UA_MonitoredItemAddList_0.Execute=((UA_MonitoredItemAddList_0.Done^1)&(UA_MonitoredItemAddList_0.Error^1)));;(UA_MonitoredItemAddList_0.SubscriptionHdl=SubscriptionHdl);;(UA_MonitoredItemAddList_0.NodeHdlCount=1);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_MonitoredItemAddList_0.NodeHdls; unsigned char* zzRValue=(unsigned char*)NodeHdls_R; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_MonitoredItemAddList_0.NodeAddInfos; unsigned char* zzRValue=(unsigned char*)NodeAddInfos_0; for(zzIndex=0; zzIndex<2560l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_MonitoredItemAddList_0.Timeout=10000);;UA_MonitoredItemAddList_0.Variables=&Variables_0;UA_MonitoredItemAddList_0.MonitoringSettings=&MonitoringSettings_0;UA_MonitoredItemAddList_0.ValuesChanged=&ValuesChanged_0;UA_MonitoredItemAddList_0.RemainingValueCount=&RemainingValueCount_0;UA_MonitoredItemAddList_0.TimeStamps=&TimeStamps_0;UA_MonitoredItemAddList_0.NodeQualityIDs=&NodeQualityIDs_0;UA_MonitoredItemAddList(&UA_MonitoredItemAddList_0);

if((((unsigned long)(unsigned char)UA_MonitoredItemAddList_0.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_MonitoredItemAddList_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"MonitoredItemAddList created"; for(zzIndex=0; zzIndex<28l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; unsigned char* zzLValue=(unsigned char*)MonitoredItemHdls; unsigned char* zzRValue=(unsigned char*)UA_MonitoredItemAddList_0.MonitoredItemHdls; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};
(steps=12);
}
if((((unsigned long)(unsigned char)UA_MonitoredItemAddList_0.Error==(unsigned long)(unsigned char)1))){
(ErrorID=(unsigned long)UA_MonitoredItemAddList_0.ErrorID);
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"MonitoredItemAddList ERROR"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(MonitoredItemHdls[NodeHdlCount]=0);
(steps=16);
}
}

}break;case 12:{





(NodeAddInfos_W[0].AttributeId=13);
(NodeAddInfos_W[0].IndexRangeCount=0);
(NodeAddInfos_W[1].AttributeId=13);
(NodeAddInfos_W[1].IndexRangeCount=0);



{int zzIndex; plcstring* zzLValue=(plcstring*)Variables_Wr0[0]; plcstring* zzRValue=(plcstring*)"::conveyor:this.io.do_pickupDropoff"; for(zzIndex=0; zzIndex<35l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)Variables_Wr0[1]; plcstring* zzRValue=(plcstring*)"::conveyor:this.io.do_mirGo"; for(zzIndex=0; zzIndex<27l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};







(UA_WriteList_0.Execute=((UA_WriteList_0.Done^1)&(UA_WriteList_0.Error^1)));;(UA_WriteList_0.ConnectionHdl=ConnectionHdl);;(UA_WriteList_0.NodeHdlCount=NodeCount_W);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_WriteList_0.NodeHdls; unsigned char* zzRValue=(unsigned char*)NodeHdls_W; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_WriteList_0.NodeAddInfo; unsigned char* zzRValue=(unsigned char*)NodeAddInfos_W; for(zzIndex=0; zzIndex<2560l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_WriteList_0.Timeout=10000);;UA_WriteList_0.Variables=&Variables_Wr0;UA_WriteList(&UA_WriteList_0);

if((((unsigned long)(unsigned char)UA_WriteList_0.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_WriteList_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Write successful"; for(zzIndex=0; zzIndex<16l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);

}
if((((unsigned long)(unsigned char)UA_WriteList_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Write ERROR"; for(zzIndex=0; zzIndex<11l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_WriteList_0.ErrorID);
(steps=16);
}
}

}break;case 13:{
(NodeAddInfos_R[0].AttributeId=13);
(NodeAddInfos_R[0].IndexRangeCount=0);
{int zzIndex; plcstring* zzLValue=(plcstring*)Variables_Rd0[0]; plcstring* zzRValue=(plcstring*)"::conveyor:this.io.di_mirPickupAck"; for(zzIndex=0; zzIndex<34l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};







(UA_ReadList_0.Execute=((UA_ReadList_0.Done^1)&(UA_ReadList_0.Error^1)));;(UA_ReadList_0.ConnectionHdl=ConnectionHdl);;(UA_ReadList_0.NodeHdlCount=1);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_ReadList_0.NodeHdls; unsigned char* zzRValue=(unsigned char*)NodeHdls_R; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_ReadList_0.NodeAddInfo; unsigned char* zzRValue=(unsigned char*)NodeAddInfos_R; for(zzIndex=0; zzIndex<2560l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_ReadList_0.Timeout=10000);;UA_ReadList_0.Variables=&Variables_Rd0;UA_ReadList(&UA_ReadList_0);

if((((unsigned long)(unsigned char)UA_ReadList_0.Busy==(unsigned long)(unsigned char)0))){

if((((unsigned long)(unsigned char)UA_ReadList_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Read succesful"; for(zzIndex=0; zzIndex<14l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
(steps=12);
}
if((((unsigned long)(unsigned char)UA_ReadList_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Read ERROR"; for(zzIndex=0; zzIndex<10l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_ReadList_0.ErrorID);
(steps=16);
}
}

}break;case 15:{




(UA_NodeReleaseHandleList_W.Execute=((UA_NodeReleaseHandleList_W.Done^1)&(UA_NodeReleaseHandleList_W.Error^1)));;(UA_NodeReleaseHandleList_W.ConnectionHdl=ConnectionHdl);;(UA_NodeReleaseHandleList_W.NodeHdlCount=NodeCount_W);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_NodeReleaseHandleList_W.NodeHdls; unsigned char* zzRValue=(unsigned char*)NodeHdls_W; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_NodeReleaseHandleList_W.Timeout=10000);;UA_NodeReleaseHandleList(&UA_NodeReleaseHandleList_W);

if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_W.Busy==(unsigned long)(unsigned char)0))){
if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_W.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_W released"; for(zzIndex=0; zzIndex<15l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
for((I=0);I<=NodeCount_W;I+=1){
(NodeHdls_W[NodeCount_W]=0);
}imp1_endfor35_0:;
(steps=10);

}
if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_W.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_W release ERROR"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_NodeReleaseHandleList_W.ErrorID);
for((I=0);I<=NodeCount_W;I+=1){
(NodeHdls_W[I]=0);
}imp1_endfor37_0:;
(steps=16);
}
}






(UA_NodeReleaseHandleList_R.Execute=((UA_NodeReleaseHandleList_R.Done^1)&(UA_NodeReleaseHandleList_0.Error^1)));;(UA_NodeReleaseHandleList_R.ConnectionHdl=ConnectionHdl);;(UA_NodeReleaseHandleList_R.NodeHdlCount=NodeCount_R);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_NodeReleaseHandleList_R.NodeHdls; unsigned char* zzRValue=(unsigned char*)NodeHdls_R; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_NodeReleaseHandleList_R.Timeout=10000);;UA_NodeReleaseHandleList(&UA_NodeReleaseHandleList_R);
if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_R.Busy==(unsigned long)(unsigned char)0))){
if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_R.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_R released"; for(zzIndex=0; zzIndex<15l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
for((I=0);I<=NodeCount_R;I+=1){
(NodeHdls_R[I]=0);
}imp1_endfor40_0:;
if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_W.Done==(unsigned long)(unsigned char)1))){
(steps=5);
}
}

if((((unsigned long)(unsigned char)UA_NodeReleaseHandleList_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Node_R release ERROR"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_NodeReleaseHandleList_0.ErrorID);
for((I=0);I<=NodeCount_R;I+=1){
(NodeHdls_R[I]=0);
}imp1_endfor43_0:;
(steps=16);
}
}

}break;case 10:{




(UA_MonitoredItemRemoveList_0.Execute=((UA_MonitoredItemRemoveList_0.Done^1)&(UA_MonitoredItemRemoveList_0.Error^1)));;(UA_MonitoredItemRemoveList_0.SubscriptionHdl=SubscriptionHdl);;(UA_MonitoredItemRemoveList_0.MonitoredItemHdlCount=NodeCount_R);;{int zzIndex; unsigned char* zzLValue=(unsigned char*)UA_MonitoredItemRemoveList_0.MonitoredItemHdls; unsigned char* zzRValue=(unsigned char*)MonitoredItemHdls; for(zzIndex=0; zzIndex<256l; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex];};;(UA_MonitoredItemRemoveList_0.Timeout=10000);;UA_MonitoredItemRemoveList(&UA_MonitoredItemRemoveList_0);

if((((unsigned long)(unsigned char)UA_MonitoredItemRemoveList_0.Busy==(unsigned long)(unsigned char)0))){
(ExecuteMonitoredItemRemove_0=0);
if((((unsigned long)(unsigned char)UA_MonitoredItemRemoveList_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"MonitoredItemRemoveList removed"; for(zzIndex=0; zzIndex<31l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(MonitoredItemHdls[NodeCount_R]=0);
(steps=11);
}
if((((unsigned long)(unsigned char)UA_MonitoredItemRemoveList_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"MonitoredItemRemoveList ERROR"; for(zzIndex=0; zzIndex<29l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_MonitoredItemRemoveList_0.ErrorID);
(MonitoredItemHdls[NodeCount_R]=0);
(steps=16);
}
}

}break;case 11:{


(UA_SubscriptionDelete_0.Execute=((UA_SubscriptionDelete_0.Done^1)&(UA_SubscriptionDelete_0.Error^1)));;(UA_SubscriptionDelete_0.SubscriptionHdl=SubscriptionHdl);;(UA_SubscriptionDelete_0.Timeout=10000);;UA_SubscriptionDelete(&UA_SubscriptionDelete_0);
if((((unsigned long)(unsigned char)UA_SubscriptionDelete_0.Busy==(unsigned long)(unsigned char)0))){
(ExecuteSubscriptionDelete_0=0);
if((((unsigned long)(unsigned char)UA_SubscriptionDelete_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"SubscriptionDelete done"; for(zzIndex=0; zzIndex<23l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SubscriptionHdl=0);
(steps=17);
}
if((((unsigned long)(unsigned char)UA_SubscriptionDelete_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"SubscriptionDelete ERROR"; for(zzIndex=0; zzIndex<24l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_SubscriptionDelete_0.ErrorID);
(SubscriptionHdl=0);
(steps=16);
}
}

}break;case 17:{


(UA_Disconnect_0.Execute=((UA_Disconnect_0.Done^1)&(UA_Disconnect_0.Error^1)));;(UA_Disconnect_0.ConnectionHdl=ConnectionHdl);;(UA_Disconnect_0.Timeout=10000);;UA_Disconnect(&UA_Disconnect_0);
if((((unsigned long)(unsigned char)UA_Disconnect_0.Busy==(unsigned long)(unsigned char)0))){
if((((unsigned long)(unsigned char)UA_Disconnect_0.Done==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Disconnected"; for(zzIndex=0; zzIndex<12l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=0);
(ConnectionHdl=0);
(steps=1);

}
if((((unsigned long)(unsigned char)UA_Disconnect_0.Error==(unsigned long)(unsigned char)1))){
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"Disconnect ERROR"; for(zzIndex=0; zzIndex<16l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ErrorID=(unsigned long)UA_Disconnect_0.ErrorID);
(ConnectionHdl=0);
(steps=16);
}
}

}break;case 16:{
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"ERROR - being resolved"; for(zzIndex=0; zzIndex<22l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};

switch(ErrorID){
case -2146828288:{
(steps=2);
}break;case -2136145920:{
(steps=2);
}break;case -1610088448:{
(steps=1);
}break;case -2141847552:{
{int zzIndex; plcstring* zzLValue=(plcstring*)em.description; plcstring* zzRValue=(plcstring*)"The server has reached its maximum number of sessions"; for(zzIndex=0; zzIndex<53l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};

}break;case -2147155968:{

}break;case -1609826304:case -2144141312:{

}break;case -2139881472:{

}break;case -2146500608:{



}break;default: {
(steps=2);
}break;}

}break;}

}imp1_case0_13:imp1_endcase0_0:;}
#line 462 "C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/OPC_UA/client/client_ignition.nodebug"

void __AS__ImplInitclient_ignition_st(void){}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUac/AsOpcUac.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUac/AsOpcUac.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsOpcUac/AsOpcUac.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/OPC_UA/Variables.var\\\" scope \\\"restricted\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/OPC_UA/Types.typ\\\" scope \\\"restricted\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/OPC_UA/client/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/OPC_UA/client/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/Config1/X20CP0411/client/client_ignition.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Temp/Objects/Config1/X20CP0411/client/client_ignition.st.c\\\" \\\"C:/Users/mafio/Documents/GitHub/OTTO_Introduction/Logical/OPC_UA/client/client_ignition.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'MAX_ELEMENTS_INDEXRANGE'\\n\"");
__asm__(".ascii \"plcdata_const 'MAX_ELEMENTS_NODELIST'\\n\"");
__asm__(".ascii \"plcdata_const 'MAX_ELEMENTS_MONITORLIST'\\n\"");
__asm__(".ascii \"plcdata_const 'MAX_INDEX_INDEXRANGE'\\n\"");
__asm__(".ascii \"plcdata_const 'MAX_INDEX_NODELIST'\\n\"");
__asm__(".ascii \"plcdata_const 'MAX_INDEX_MONITORLIST'\\n\"");
__asm__(".previous");

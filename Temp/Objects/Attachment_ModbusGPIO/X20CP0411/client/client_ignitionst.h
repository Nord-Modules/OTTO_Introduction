#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

#ifndef __AS__TYPE_opc_steps
#define __AS__TYPE_opc_steps
typedef enum opc_steps
{	Retain = 0,
	Connect = 1,
	ConnectionGetStatus = 2,
	GetNamespaceIndex = 3,
	NodeGetHandle = 4,
	NodeGetHandleList = 5,
	SubscriptionCreate = 6,
	MonitoredItemAdd = 7,
	MonitoredItemAddList = 8,
	MonitoredItemOperateList = 9,
	MonitoredItemRemoveList = 10,
	SubscriptionDelete = 11,
	WriteList = 12,
	ReadList = 13,
	NodeReleaseHandle = 14,
	NodeReleaseHandleList = 15,
	ErrorHandling = 16,
	Disconnect = 17,
} opc_steps;
#endif

#ifndef __AS__TYPE_Structure_type
#define __AS__TYPE_Structure_type
typedef struct Structure_type
{	plcstring description[81];
} Structure_type;
#endif

#ifndef __AS__TYPE_UASecurityMsgMode
#define __AS__TYPE_UASecurityMsgMode
typedef enum UASecurityMsgMode
{	UASecurityMsgMode_BestAvailable = 0,
	UASecurityMsgMode_None = 1,
	UASecurityMsgMode_Sign = 2,
	UASecurityMsgMode_SignEncrypt = 3,
} UASecurityMsgMode;
#endif

#ifndef __AS__TYPE_UASecurityPolicy
#define __AS__TYPE_UASecurityPolicy
typedef enum UASecurityPolicy
{	UASecurityPolicy_BestAvailable = 0,
	UASecurityPolicy_None = 1,
	UASecurityPolicy_Basic128Rsa15 = 2,
	UASecurityPolicy_Basic256 = 3,
	UASecurityPolicy_Basic256Sha256 = 4,
} UASecurityPolicy;
#endif

#ifndef __AS__TYPE_UATransportProfile
#define __AS__TYPE_UATransportProfile
typedef enum UATransportProfile
{	UATP_UATcp = 1,
	UATP_WSHttpBinary = 2,
	UATP_WSHttpXmlOrBinary = 3,
	UATP_WSHttpXml = 4,
} UATransportProfile;
#endif

#ifndef __AS__TYPE_UAUserIdentityTokenTtype
#define __AS__TYPE_UAUserIdentityTokenTtype
typedef enum UAUserIdentityTokenTtype
{	UAUITT_Anonymous = 0,
	UAUITT_Username = 1,
	UAUITT_x509 = 2,
} UAUserIdentityTokenTtype;
#endif

#ifndef __AS__TYPE_UAIdentifierType
#define __AS__TYPE_UAIdentifierType
typedef enum UAIdentifierType
{	UAIdentifierType_String = 1,
	UAIdentifierType_Numeric = 2,
	UAIdentifierType_GUID = 3,
	UAIdentifierType_Opaque = 4,
} UAIdentifierType;
#endif

#ifndef __AS__TYPE_UADeadbandType
#define __AS__TYPE_UADeadbandType
typedef enum UADeadbandType
{	UADeadbandType_None = 0,
	UADeadbandType_Absolute = 1,
	UADeadbandType_Percent = 2,
} UADeadbandType;
#endif

#ifndef __AS__TYPE_UAAttributeId
#define __AS__TYPE_UAAttributeId
typedef enum UAAttributeId
{	UAAI_Default = 0,
	UAAI_NodeId = 1,
	UAAI_NodeClass = 2,
	UAAI_BrowseName = 3,
	UAAI_DisplayName = 4,
	UAAI_Description = 5,
	UAAI_WriteMask = 6,
	UAAI_UserWriteMask = 7,
	UAAI_IsAbstract = 8,
	UAAI_Symmetric = 9,
	UAAI_InverseName = 10,
	UAAI_ContainsNoLoops = 11,
	UAAI_EventNotifier = 12,
	UAAI_Value = 13,
	UAAI_DataType = 14,
	UAAI_ValueRank = 15,
	UAAI_ArrayDimensions = 16,
	UAAI_AccessLevel = 17,
	UAAI_UserAccessLevel = 18,
	UAAI_MinimumSamplingInterval = 19,
	UAAI_Historizing = 20,
	UAAI_Executable = 21,
	UAAI_UserExecutable = 22,
} UAAttributeId;
#endif

#ifndef __AS__TYPE_UAConnectionStatus
#define __AS__TYPE_UAConnectionStatus
typedef enum UAConnectionStatus
{	UACS_Connected = 0,
	UACS_ConnectionError = 1,
	UACS_Shutdown = 2,
} UAConnectionStatus;
#endif

#ifndef __AS__TYPE_UAServerState
#define __AS__TYPE_UAServerState
typedef enum UAServerState
{	UASS_Running = 0,
	UASS_Failed = 1,
	UASS_NoConfiguration = 2,
	UASS_Suspended = 3,
	UASS_Shutdown = 4,
	UASS_Test = 5,
	UASS_CommunicationFault = 6,
	UASS_Unknown = 7,
} UAServerState;
#endif

#ifndef __AS__TYPE_UAUserIdentityToken
#define __AS__TYPE_UAUserIdentityToken
typedef struct UAUserIdentityToken
{	UAUserIdentityTokenTtype UserIdentityTokenType;
	plcstring TokenParam1[256];
	plcstring TokenParam2[256];
} UAUserIdentityToken;
#endif

#ifndef __AS__TYPE_UASessionConnectInfo
#define __AS__TYPE_UASessionConnectInfo
typedef struct UASessionConnectInfo
{	plcstring SessionName[256];
	plcstring ApplicationName[256];
	UASecurityMsgMode SecurityMsgMode;
	UASecurityPolicy SecurityPolicy;
	plcstring CertificateStore[256];
	plcstring ClientCertificateName[256];
	plcstring ServerUri[256];
	plcbit CheckServerCertificate;
	UATransportProfile TransportProfile;
	UAUserIdentityToken UserIdentityToken;
	plcstring VendorSpecificParameter[256];
	plctime SessionTimeout;
	plctime MonitorConnection;
	plcstring LocaleIDs[5][7];
} UASessionConnectInfo;
#endif

#ifndef __AS__TYPE_UANodeID
#define __AS__TYPE_UANodeID
typedef struct UANodeID
{	unsigned short NamespaceIndex;
	plcstring Identifier[256];
	UAIdentifierType IdentifierType;
} UANodeID;
#endif

#ifndef __AS__TYPE_UAMonitoringParameters
#define __AS__TYPE_UAMonitoringParameters
typedef struct UAMonitoringParameters
{	plctime SamplingInterval;
	unsigned short QueueSize;
	plcbit DiscardOldest;
	UADeadbandType DeadbandType;
	float Deadband;
} UAMonitoringParameters;
#endif

#ifndef __AS__TYPE_UAIndexRange
#define __AS__TYPE_UAIndexRange
typedef struct UAIndexRange
{	unsigned short StartIndex;
	unsigned short EndIndex;
} UAIndexRange;
#endif

#ifndef __AS__TYPE_UANodeAdditionalInfo
#define __AS__TYPE_UANodeAdditionalInfo
typedef struct UANodeAdditionalInfo
{	UAAttributeId AttributeId;
	unsigned short IndexRangeCount;
	struct UAIndexRange IndexRange[8];
} UANodeAdditionalInfo;
#endif

struct UA_Connect
{	plcstring ServerEndpointUrl[256];
	UASessionConnectInfo SessionConnectInfo;
	plctime Timeout;
	plcdword ConnectionHdl;
	plcdword ErrorID;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_Connect(struct UA_Connect* inst);
struct UA_Disconnect
{	plcdword ConnectionHdl;
	plctime Timeout;
	plcdword ErrorID;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_Disconnect(struct UA_Disconnect* inst);
struct UA_GetNamespaceIndex
{	plcdword ConnectionHdl;
	plcstring NamespaceUri[256];
	plctime Timeout;
	unsigned short NamespaceIndex;
	plcdword ErrorID;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_GetNamespaceIndex(struct UA_GetNamespaceIndex* inst);
struct UA_NodeGetHandleList
{	plcdword ConnectionHdl;
	unsigned short NodeIDCount;
	struct UANodeID NodeIDs[64];
	plctime Timeout;
	plcdword NodeHdls[64];
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_NodeGetHandleList(struct UA_NodeGetHandleList* inst);
struct UA_NodeReleaseHandleList
{	plcdword ConnectionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	plctime Timeout;
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_NodeReleaseHandleList(struct UA_NodeReleaseHandleList* inst);
struct UA_SubscriptionCreate
{	plcdword ConnectionHdl;
	plcbyte Priority;
	plctime Timeout;
	plcdword SubscriptionHdl;
	plcdword ErrorID;
	plctime(* PublishingInterval);
	plcbit Execute;
	plcbit PublishingEnable;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_SubscriptionCreate(struct UA_SubscriptionCreate* inst);
struct UA_SubscriptionDelete
{	plcdword SubscriptionHdl;
	plctime Timeout;
	plcdword ErrorID;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_SubscriptionDelete(struct UA_SubscriptionDelete* inst);
struct UA_MonitoredItemAddList
{	plcdword SubscriptionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	struct UANodeAdditionalInfo NodeAddInfos[64];
	plctime Timeout;
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcdword MonitoredItemHdls[64];
	plcstring(* Variables)[64][256];
	struct UAMonitoringParameters(* MonitoringSettings)[64];
	plcbit(* ValuesChanged)[64];
	unsigned short(* RemainingValueCount)[64];
	plcdt(* TimeStamps)[64];
	plcdword(* NodeQualityIDs)[64];
	unsigned long i_tid;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_MonitoredItemAddList(struct UA_MonitoredItemAddList* inst);
struct UA_MonitoredItemRemoveList
{	plcdword SubscriptionHdl;
	unsigned short MonitoredItemHdlCount;
	plcdword MonitoredItemHdls[64];
	plctime Timeout;
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_MonitoredItemRemoveList(struct UA_MonitoredItemRemoveList* inst);
struct UA_ReadList
{	plcdword ConnectionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	struct UANodeAdditionalInfo NodeAddInfo[64];
	plctime Timeout;
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcdt TimeStamps[64];
	plcstring(* Variables)[64][256];
	unsigned long i_tid;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_ReadList(struct UA_ReadList* inst);
struct UA_WriteList
{	plcdword ConnectionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	struct UANodeAdditionalInfo NodeAddInfo[64];
	plctime Timeout;
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcstring(* Variables)[64][256];
	unsigned long i_tid;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_WriteList(struct UA_WriteList* inst);
struct UA_ConnectionGetStatus
{	plcdword ConnectionHdl;
	plctime Timeout;
	UAConnectionStatus ConnectionStatus;
	UAServerState ServerState;
	plcbyte ServiceLevel;
	plcdword ErrorID;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit i_busy;
};
_BUR_PUBLIC void UA_ConnectionGetStatus(struct UA_ConnectionGetStatus* inst);
_BUR_LOCAL plcdword ConnectionHdl;
_BUR_LOCAL opc_steps steps;
_BUR_LOCAL Structure_type em;
_BUR_LOCAL plcbit ExecuteConnectionGetStatus_0;
_BUR_LOCAL plcbit ExecuteGetnamespaceindex_0;
_BUR_LOCAL plcbit ExecuteSubscriptionDelete_0;
_BUR_LOCAL plcbit ExecuteMonitoredItemRemove_0;
_BUR_LOCAL unsigned short NamespaceIndex;
_BUR_LOCAL struct UANodeAdditionalInfo NodeAddInfos_W[64];
_BUR_LOCAL struct UANodeAdditionalInfo NodeAddInfos_R[64];
_BUR_LOCAL struct UANodeAdditionalInfo NodeAddInfos_0[64];
_BUR_LOCAL plcdword SubscriptionHdl;
_BUR_LOCAL plcdword MonitoredItemHdls[64];
_BUR_LOCAL unsigned short NodeHdlCount;
_BUR_LOCAL plcdword NodeHdls_W[64];
_BUR_LOCAL plcdword NodeHdls_R[64];
_BUR_LOCAL struct UANodeID NodeIDs_R[64];
_BUR_LOCAL struct UANodeID NodeIDs_W[64];
_BUR_LOCAL unsigned char NodeCount_R;
_BUR_LOCAL unsigned char NodeCount_W;
_BUR_LOCAL unsigned long ErrorID;
_BUR_LOCAL UASessionConnectInfo SessionConnectInfo_0;
_BUR_LOCAL struct UA_Connect UA_Connect_0;
_BUR_LOCAL struct UA_ConnectionGetStatus UA_ConnectionGetStatus_0;
_BUR_LOCAL struct UA_Disconnect UA_Disconnect_0;
_BUR_LOCAL struct UA_GetNamespaceIndex UA_GetNamespaceIndex_0;
_BUR_LOCAL struct UA_NodeGetHandleList UA_NodeGetHandleList_R;
_BUR_LOCAL struct UA_NodeGetHandleList UA_NodeGetHandleList_W;
_BUR_LOCAL struct UA_NodeReleaseHandleList UA_NodeReleaseHandleList_R;
_BUR_LOCAL struct UA_NodeReleaseHandleList UA_NodeReleaseHandleList_W;
_BUR_LOCAL struct UA_NodeReleaseHandleList UA_NodeReleaseHandleList_0;
_BUR_LOCAL struct UA_ReadList UA_ReadList_0;
_BUR_LOCAL struct UA_SubscriptionCreate UA_SubscriptionCreate_0;
_BUR_LOCAL struct UA_MonitoredItemAddList UA_MonitoredItemAddList_0;
_BUR_LOCAL struct UA_MonitoredItemRemoveList UA_MonitoredItemRemoveList_0;
_BUR_LOCAL struct UA_SubscriptionDelete UA_SubscriptionDelete_0;
_BUR_LOCAL struct UAMonitoringParameters MonitoringSettings_0[64];
_BUR_LOCAL struct UA_WriteList UA_WriteList_0;
_BUR_LOCAL plcdt TimeStamps_0[64];
_BUR_LOCAL plcdword NodeQualityIDs_0[64];
_BUR_LOCAL unsigned short RemainingValueCount_0[64];
_BUR_LOCAL plcbit ValuesChanged_0[64];
_BUR_LOCAL plcbit PublishingEnable;
_BUR_LOCAL plctime PublishingInterval;
_BUR_LOCAL UAConnectionStatus ConnectionStatus;
_BUR_LOCAL plcbyte ServiceLevel;
_BUR_LOCAL UAServerState ServerState;
_BUR_LOCAL plcstring Variables_0[64][256];
_BUR_LOCAL plcstring Variables_Rd0[64][256];
_BUR_LOCAL plcstring Variables_Wr0[64][256];
_BUR_LOCAL unsigned char I;
_GLOBAL unsigned short MAX_ELEMENTS_INDEXRANGE;
_GLOBAL unsigned short MAX_ELEMENTS_NODELIST;
_GLOBAL unsigned short MAX_ELEMENTS_MONITORLIST;
_GLOBAL unsigned short MAX_INDEX_INDEXRANGE;
_GLOBAL unsigned short MAX_INDEX_NODELIST;
_GLOBAL unsigned short MAX_INDEX_MONITORLIST;

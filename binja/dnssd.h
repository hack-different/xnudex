typedef enum DNSServiceAAAAPolicy : unsigned int {
    kDNSServiceAAAAPolicyFallback = 1,
    kDNSServiceAAAAPolicyNone = 0
} DNSServiceAAAAPolicy;

typedef struct _DNSServiceRef_t *DNSServiceRef;
typedef struct _DNSRecordRef_t *DNSRecordRef;
typedef int dnssd_sock_t;
typedef int32_t DNSServiceErrorType;
typedef uint32_t DNSServiceFlags;
typedef uint32_t DNSServiceProtocol;
typedef union _TXTRecordRef_t {
    char *ForceNaturalAlignment;
    char PrivateData[16];
} TXTRecordRef;
typedef struct DNSServiceAttribute_s DNSServiceAttribute;
typedef DNSServiceAttribute *DNSServiceAttributeRef;

typedef void (*DNSServiceGetAddrInfoReply)(DNSServiceRef sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceErrorType errorCode, const char *hostname, const struct sockaddr *address, uint32_t ttl, void *context);
typedef void (*DNSServiceRegisterRecordReply)(DNSServiceRef sdRef, DNSRecordRef RecordRef, DNSServiceFlags flags, DNSServiceErrorType errorCode, void *context);
typedef void (*DNSServiceRegisterReply)(DNSServiceRef sdRef, DNSServiceFlags flags, DNSServiceErrorType errorCode, const char *name, const char *regtype, const char *domain, void *context);
typedef void (*DNSServiceBrowseReply)(DNSServiceRef sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceErrorType errorCode, const char *serviceName, const char *regtype, const char *replyDomain, void *context);
typedef void (*DNSServiceResolveReply)(DNSServiceRef sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceErrorType errorCode, const char *fullname, const char *hosttarget, uint16_t port, uint16_t txtLen, const unsigned char *txtRecord, void *context);
typedef void (*DNSServiceQueryRecordReply)(DNSServiceRef sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceErrorType errorCode, const char *fullname, uint16_t rrtype, uint16_t rrclass, uint16_t rdlen, const void *rdata, uint32_t ttl, void *context);
typedef void (*DNSServiceNATPortMappingReply)(DNSServiceRef sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceErrorType errorCode, uint32_t externalAddress, DNSServiceProtocol protocol, uint16_t internalPort, uint16_t externalPort, uint32_t ttl, void *context);
typedef void (*DNSServiceDomainEnumReply)(DNSServiceRef sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceErrorType errorCode, const char *replyDomain, void *context);
typedef void (*DNSServiceSleepKeepaliveReply)(DNSServiceRef sdRef, DNSServiceErrorType errorCode, void *context);

DNSServiceErrorType DNSServiceGetProperty(const char *property, void *result, uint32_t *size);
DNSServiceErrorType DNSServiceProcessResult(DNSServiceRef sdRef);
void DNSServiceRefDeallocate(DNSServiceRef sdRef);
dnssd_sock_t DNSServiceRefSockFD(DNSServiceRef sdRef);

DNSServiceErrorType DNSServiceGetAddrInfo(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceProtocol protocol, const char *hostname, DNSServiceGetAddrInfoReply callBack, void *context);

DNSServiceErrorType DNSServiceCreateDelegateConnection (
   DNSServiceRef *sdRef,
   int32_t pid,
   uuid_t uuid
);
DNSServiceErrorType DNSServiceSetDispatchQueue(DNSServiceRef service, dispatch_queue_t queue);
int TXTRecordContainsKey(uint16_t txtLen, const void *txtRecord, const char *key);
uint16_t TXTRecordGetCount(uint16_t txtLen, const void *txtRecord);
DNSServiceErrorType TXTRecordGetItemAtIndex(uint16_t txtLen, const void *txtRecord, uint16_t itemIndex, uint16_t keyBufLen, char *key, uint8_t *valueLen, const void **value);
const void * TXTRecordGetValuePtr(uint16_t txtLen, const void *txtRecord, const char *key, uint8_t *valueLen);

void TXTRecordCreate(TXTRecordRef *txtRecord, uint16_t bufferLen, void *buffer);
void TXTRecordDeallocate(TXTRecordRef *txtRecord);
const void * TXTRecordGetBytesPtr(const TXTRecordRef *txtRecord);
uint16_t TXTRecordGetLength(const TXTRecordRef *txtRecord);
DNSServiceErrorType TXTRecordRemoveValue(TXTRecordRef *txtRecord, const char *key);
DNSServiceErrorType TXTRecordSetValue(TXTRecordRef *txtRecord, const char *key, uint8_t valueSize, const void *value);

DNSServiceErrorType DNSServiceCreateConnection(DNSServiceRef *sdRef);
DNSServiceErrorType DNSServiceReconfirmRecord(DNSServiceFlags flags, uint32_t interfaceIndex, const char *fullname, uint16_t rrtype, uint16_t rrclass, uint16_t rdlen, const void *rdata);
DNSServiceErrorType DNSServiceRegisterRecord(DNSServiceRef sdRef, DNSRecordRef *RecordRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *fullname, uint16_t rrtype, uint16_t rrclass, uint16_t rdlen, const void *rdata, uint32_t ttl, DNSServiceRegisterRecordReply callBack, void *context);
DNSServiceErrorType PeerConnectionRelease(DNSServiceFlags flags, const char *name, const char *regtype, const char *domain);

DNSServiceErrorType DNSServiceAddRecord(DNSServiceRef sdRef, DNSRecordRef *RecordRef, DNSServiceFlags flags, uint16_t rrtype, uint16_t rdlen, const void *rdata, uint32_t ttl);
DNSServiceErrorType DNSServiceRegister(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *name, const char *regtype, const char *domain, const char *host, uint16_t port, uint16_t txtLen, const void *txtRecord, DNSServiceRegisterReply callBack, void *context);
DNSServiceErrorType DNSServiceRemoveRecord(DNSServiceRef sdRef, DNSRecordRef RecordRef, DNSServiceFlags flags);
DNSServiceErrorType DNSServiceUpdateRecord(DNSServiceRef sdRef, DNSRecordRef recordRef, DNSServiceFlags flags, uint16_t rdlen, const void *rdata, uint32_t ttl);

DNSServiceErrorType DNSServiceBrowse(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *regtype, const char *domain, DNSServiceBrowseReply callBack, void *context);
DNSServiceErrorType DNSServiceResolve(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *name, const char *regtype, const char *domain, DNSServiceResolveReply callBack, void *context);

DNSServiceErrorType DNSServiceQueryRecord(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *fullname, uint16_t rrtype, uint16_t rrclass, DNSServiceQueryRecordReply callBack, void *context);

DNSServiceErrorType DNSServiceNATPortMappingCreate(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceProtocol protocol, uint16_t internalPort, uint16_t externalPort, uint32_t ttl, DNSServiceNATPortMappingReply callBack, void *context);

DNSServiceErrorType DNSServiceConstructFullName(char *const fullName, const char *const service, const char *const regtype, const char *const domain);

DNSServiceErrorType DNSServiceEnumerateDomains(DNSServiceRef *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, DNSServiceDomainEnumReply callBack, void *context);

// dnssd functions

DNSServiceErrorType DNSServiceSleepKeepalive(DNSServiceRef *sdRef, DNSServiceFlags flags, int fd, unsigned int timeout, DNSServiceSleepKeepaliveReply callBack, void *context);
DNSServiceAttributeRef DNSServiceAttributeCreate(void);
void DNSServiceAttributeDeallocate(DNSServiceAttributeRef attr);
DNSServiceErrorType DNSServiceAttributeSetAAAAPolicy(DNSServiceAttributeRef attr, DNSServiceAAAAPolicy policy);
DNSServiceErrorType DNSServiceAttributeSetTimestamp(DNSServiceAttributeRef attr, uint32_t timestamp);
DNSServiceErrorType DNSServiceQueryRecordWithAttribute(DNSServiceRef  _Nonnull *sdRef, DNSServiceFlags flags, uint32_t ifindex, const char *name, uint16_t rrtype, uint16_t rrclass, const DNSServiceAttribute *attr, DNSServiceQueryRecordReply callback, void *context);
DNSServiceErrorType DNSServiceRegisterRecordWithAttribute(DNSServiceRef sdRef, DNSRecordRef  _Nonnull *recordRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *fullname, uint16_t rrtype, uint16_t rrclass, uint16_t rdlen, const void *rdata, uint32_t ttl, DNSServiceAttributeRef attr, DNSServiceRegisterRecordReply callBack, void *context);
DNSServiceErrorType DNSServiceRegisterWithAttribute(DNSServiceRef  _Nonnull *sdRef, DNSServiceFlags flags, uint32_t interfaceIndex, const char *name, const char *regtype, const char *domain, const char *host, uint16_t portInNetworkByteOrder, uint16_t txtLen, const void *txtRecord, DNSServiceAttributeRef attr, DNSServiceRegisterReply callBack, void *context);
DNSServiceErrorType DNSServiceSendQueuedRequests(DNSServiceRef sdRef);
DNSServiceErrorType DNSServiceUpdateRecordWithAttribute(DNSServiceRef sdRef, DNSRecordRef recordRef, DNSServiceFlags flags, uint16_t rdlen, const void *rdata, uint32_t ttl, DNSServiceAttributeRef attr);
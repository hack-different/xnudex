
typedef struct __SCPreferences SCPreferencesRef;
typedef struct __SCDynamicStore SCDynamicStoreRef;
typedef struct __SCNetworkInterface SCNetworkInterfaceRef;
typedef SCNetworkInterfaceRef SCBondInterfaceRef;
typedef struct __SCBondStatus SCBondStatusRef;
typedef SCNetworkInterfaceRef SCVLANInterfaceRef;
typedef struct __SCNetworkProtocol SCNetworkProtocolRef;
typedef struct __SCNetworkService SCNetworkServiceRef;
typedef struct __SCNetworkReachability SCNetworkReachabilityRef;
typedef struct __SCNetworkSet SCNetworkSetRef;
typedef struct __SCNetworkConnection SCNetworkConnectionRef;
typedef const struct AuthorizationOpaqueRef *AuthorizationRef;
typedef struct SCNetworkConnectionContext {
    CFStringRef  _Nonnull (*copyDescription)(const void *info);
    void *info;
    void (*release)(const void *info);
    const void * _Nonnull (*retain)(const void *info);
    CFIndex version;
} SCNetworkConnectionContext;

typedef struct SCPreferencesContext {
    CFStringRef  _Nonnull (*copyDescription)(const void *info);
    void *info;
    void (*release)(const void *info);
    const void * _Nonnull (*retain)(const void *info);
    CFIndex version;
} SCPreferencesContext;

typedef struct SCNetworkReachabilityContext {
    CFStringRef  _Nonnull (*copyDescription)(const void *info);
    void *info;
    void (*release)(const void *info);
    const void * _Nonnull (*retain)(const void *info);
    CFIndex version;
} SCNetworkReachabilityContext;

typedef enum SCNetworkConnectionStatus : int32_t {
    kSCNetworkConnectionInvalid = -1,
    kSCNetworkConnectionDisconnected = 0,
    kSCNetworkConnectionConnecting = 1,
    kSCNetworkConnectionConnected = 2,
    kSCNetworkConnectionDisconnecting = 3
} SCNetworkConnectionStatus;

typedef enum SCPreferencesNotification : uint32_t {
    kSCPreferencesNotificationCommit = 1<<0,
    kSCPreferencesNotificationApply = 1<<1
} SCPreferencesNotification;

typedef enum : uint32_t {
    kSCNetworkFlagsTransientConnection = 1<<0,
    kSCNetworkFlagsReachable = 1<<1,
    kSCNetworkFlagsConnectionRequired = 1<<2,
    kSCNetworkFlagsConnectionAutomatic = 1<<3,
    kSCNetworkFlagsInterventionRequired = 1<<4,
    kSCNetworkFlagsIsLocalAddress = 1<<16,
    kSCNetworkFlagsIsDirect = 1<<17
} SCNetworkConnectionFlags;

typedef enum SCNetworkReachabilityFlags : uint32_t {
    kSCNetworkReachabilityFlagsTransientConnection = 1<<0,
    kSCNetworkReachabilityFlagsReachable = 1<<1,
    kSCNetworkReachabilityFlagsConnectionRequired = 1<<2,
    kSCNetworkReachabilityFlagsConnectionOnTraffic = 1<<3,
    kSCNetworkReachabilityFlagsInterventionRequired = 1<<4,
    kSCNetworkReachabilityFlagsConnectionOnDemand = 1<<5,
    kSCNetworkReachabilityFlagsIsLocalAddress = 1<<16,
    kSCNetworkReachabilityFlagsIsDirect = 1<<17,
    kSCNetworkReachabilityFlagsIsWWAN = 1<<18,
    kSCNetworkReachabilityFlagsConnectionAutomatic = kSCNetworkReachabilityFlagsConnectionOnTraffic
} SCNetworkReachabilityFlags;

typedef void (*SCDynamicStoreCallBack)(SCDynamicStoreRef store, CFArrayRef changedKeys, void *info);
typedef void (*SCNetworkConnectionCallBack)(SCNetworkConnectionRef connection, SCNetworkConnectionStatus status, void *info);
typedef void (*SCPreferencesCallBack)(SCPreferencesRef prefs, SCPreferencesNotification notificationType, void *info);
typedef void (*SCNetworkReachabilityCallBack)(SCNetworkReachabilityRef target, SCNetworkReachabilityFlags flags, void *info);

typedef struct SCDynamicStoreContext {
    CFStringRef  _Nonnull (*copyDescription)(const void *info);
    void *info;
    void (*release)(const void *info);
    const void * _Nonnull (*retain)(const void *info);
    CFIndex version;
} SCDynamicStoreContext;

UInt8 * DHCPClientPreferencesCopyApplicationOptions(CFStringRef applicationID, CFIndex *count);
Boolean DHCPClientPreferencesSetApplicationOptions(CFStringRef applicationID, const UInt8 *options, CFIndex count);

SCDynamicStoreRef SCDynamicStoreCreateWithOptions(CFAllocatorRef allocator, CFStringRef name, CFDictionaryRef storeOptions, SCDynamicStoreCallBack callout, SCDynamicStoreContext *context);
SCDynamicStoreRef SCDynamicStoreCreate(CFAllocatorRef allocator, CFStringRef name, SCDynamicStoreCallBack callout, SCDynamicStoreContext *context);

Boolean SCDynamicStoreAddTemporaryValue(SCDynamicStoreRef store, CFStringRef key, CFPropertyListRef value);
Boolean SCDynamicStoreAddValue(SCDynamicStoreRef store, CFStringRef key, CFPropertyListRef value);
Boolean SCDynamicStoreSetMultiple(SCDynamicStoreRef store, CFDictionaryRef keysToSet, CFArrayRef keysToRemove, CFArrayRef keysToNotify);
Boolean SCDynamicStoreSetValue(SCDynamicStoreRef store, CFStringRef key, CFPropertyListRef value);

CFArrayRef SCDynamicStoreCopyKeyList(SCDynamicStoreRef store, CFStringRef pattern);
CFDictionaryRef SCDynamicStoreCopyMultiple(SCDynamicStoreRef store, CFArrayRef keys, CFArrayRef patterns);
CFArrayRef SCDynamicStoreCopyNotifiedKeys(SCDynamicStoreRef store);
CFPropertyListRef SCDynamicStoreCopyValue(SCDynamicStoreRef store, CFStringRef key);

Boolean SCDynamicStoreNotifyValue(SCDynamicStoreRef store, CFStringRef key);
Boolean SCDynamicStoreSetNotificationKeys(SCDynamicStoreRef store, CFArrayRef keys, CFArrayRef patterns);
Boolean SCDynamicStoreSetDispatchQueue(SCDynamicStoreRef store, dispatch_queue_t queue);

Boolean SCDynamicStoreRemoveValue(SCDynamicStoreRef store, CFStringRef key);

CFRunLoopSourceRef SCDynamicStoreCreateRunLoopSource(CFAllocatorRef allocator, SCDynamicStoreRef store, CFIndex order);

CFTypeID SCDynamicStoreGetTypeID(void);

CFDictionaryRef SCDynamicStoreCopyDHCPInfo(SCDynamicStoreRef store, CFStringRef serviceID);
CFDataRef DHCPInfoGetOptionData(CFDictionaryRef info, UInt8 code);
CFDateRef DHCPInfoGetLeaseStartTime(CFDictionaryRef info);

CFStringRef SCDynamicStoreCopyComputerName(SCDynamicStoreRef store, CFStringEncoding *nameEncoding);
CFStringRef SCDynamicStoreCopyConsoleUser(SCDynamicStoreRef store, uid_t *uid, gid_t *gid);
CFStringRef SCDynamicStoreCopyLocalHostName(SCDynamicStoreRef store);
CFStringRef SCDynamicStoreCopyLocation(SCDynamicStoreRef store);
CFDictionaryRef SCDynamicStoreCopyProxies(SCDynamicStoreRef store);

CFStringRef SCDynamicStoreKeyCreate(CFAllocatorRef allocator, CFStringRef fmt, ...);
CFStringRef SCDynamicStoreKeyCreateNetworkGlobalEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef entity);
CFStringRef SCDynamicStoreKeyCreateNetworkInterface(CFAllocatorRef allocator, CFStringRef domain);
CFStringRef SCDynamicStoreKeyCreateNetworkInterfaceEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef ifname, CFStringRef entity);
CFStringRef SCDynamicStoreKeyCreateNetworkServiceEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef serviceID, CFStringRef entity);
CFStringRef SCDynamicStoreKeyCreateComputerName(CFAllocatorRef allocator);
CFStringRef SCDynamicStoreKeyCreateConsoleUser(CFAllocatorRef allocator);
CFStringRef SCDynamicStoreKeyCreateHostNames(CFAllocatorRef allocator);
CFStringRef SCDynamicStoreKeyCreateLocation(CFAllocatorRef allocator);
CFStringRef SCDynamicStoreKeyCreateProxies(CFAllocatorRef allocator);

Boolean SCNetworkCheckReachabilityByAddress(const struct sockaddr *address, socklen_t addrlen, SCNetworkConnectionFlags *flags);
Boolean SCNetworkCheckReachabilityByName(const char *nodename, SCNetworkConnectionFlags *flags);
Boolean SCNetworkInterfaceRefreshConfiguration(CFStringRef ifName);

CFArrayRef SCBondInterfaceCopyAll(SCPreferencesRef prefs);
CFArrayRef SCBondInterfaceCopyAvailableMemberInterfaces(SCPreferencesRef prefs);
SCBondStatusRef SCBondInterfaceCopyStatus(SCBondInterfaceRef bond);
SCBondInterfaceRef SCBondInterfaceCreate(SCPreferencesRef prefs);
CFArrayRef SCBondInterfaceGetMemberInterfaces(SCBondInterfaceRef bond);
CFDictionaryRef SCBondInterfaceGetOptions(SCBondInterfaceRef bond);
Boolean SCBondInterfaceRemove(SCBondInterfaceRef bond);
Boolean SCBondInterfaceSetLocalizedDisplayName(SCBondInterfaceRef bond, CFStringRef newName);
Boolean SCBondInterfaceSetMemberInterfaces(SCBondInterfaceRef bond, CFArrayRef members);
Boolean SCBondInterfaceSetOptions(SCBondInterfaceRef bond, CFDictionaryRef newOptions);
CFDictionaryRef SCBondStatusGetInterfaceStatus(SCBondStatusRef bondStatus, SCNetworkInterfaceRef interface);
CFArrayRef SCBondStatusGetMemberInterfaces(SCBondStatusRef bondStatus);
CFTypeID SCBondStatusGetTypeID(void);

CFArrayRef SCNetworkInterfaceCopyAll(void);
Boolean SCNetworkInterfaceCopyMTU(SCNetworkInterfaceRef interface, int *mtu_cur, int *mtu_min, int *mtu_max);
Boolean SCNetworkInterfaceCopyMediaOptions(SCNetworkInterfaceRef interface, CFDictionaryRef*  _Nullable current, CFDictionaryRef*  _Nullable active, CFArrayRef*  _Nullable available, Boolean filter);
CFArrayRef SCNetworkInterfaceCopyMediaSubTypeOptions(CFArrayRef available, CFStringRef subType);
CFArrayRef SCNetworkInterfaceCopyMediaSubTypes(CFArrayRef available);
SCNetworkInterfaceRef SCNetworkInterfaceCreateWithInterface(SCNetworkInterfaceRef interface, CFStringRef interfaceType);
Boolean SCNetworkInterfaceForceConfigurationRefresh(SCNetworkInterfaceRef interface);
CFStringRef SCNetworkInterfaceGetBSDName(SCNetworkInterfaceRef interface);
CFDictionaryRef SCNetworkInterfaceGetConfiguration(SCNetworkInterfaceRef interface);
CFDictionaryRef SCNetworkInterfaceGetExtendedConfiguration(SCNetworkInterfaceRef interface, CFStringRef extendedType);
CFStringRef SCNetworkInterfaceGetHardwareAddressString(SCNetworkInterfaceRef interface);
SCNetworkInterfaceRef SCNetworkInterfaceGetInterface(SCNetworkInterfaceRef interface);
CFStringRef SCNetworkInterfaceGetInterfaceType(SCNetworkInterfaceRef interface);
CFStringRef SCNetworkInterfaceGetLocalizedDisplayName(SCNetworkInterfaceRef interface);
CFArrayRef SCNetworkInterfaceGetSupportedInterfaceTypes(SCNetworkInterfaceRef interface);
CFArrayRef SCNetworkInterfaceGetSupportedProtocolTypes(SCNetworkInterfaceRef interface);
CFTypeID SCNetworkInterfaceGetTypeID(void);
Boolean SCNetworkInterfaceSetConfiguration(SCNetworkInterfaceRef interface, CFDictionaryRef config);
Boolean SCNetworkInterfaceSetExtendedConfiguration(SCNetworkInterfaceRef interface, CFStringRef extendedType, CFDictionaryRef config);
Boolean SCNetworkInterfaceSetMTU(SCNetworkInterfaceRef interface, int mtu);
Boolean SCNetworkInterfaceSetMediaOptions(SCNetworkInterfaceRef interface, CFStringRef subtype, CFArrayRef options);

CFDictionaryRef SCNetworkProtocolGetConfiguration(SCNetworkProtocolRef protocol);
Boolean SCNetworkProtocolGetEnabled(SCNetworkProtocolRef protocol);
CFStringRef SCNetworkProtocolGetProtocolType(SCNetworkProtocolRef protocol);
CFTypeID SCNetworkProtocolGetTypeID(void);
Boolean SCNetworkProtocolSetConfiguration(SCNetworkProtocolRef protocol, CFDictionaryRef config);
Boolean SCNetworkProtocolSetEnabled(SCNetworkProtocolRef protocol, Boolean enabled);

Boolean SCNetworkServiceAddProtocolType(SCNetworkServiceRef service, CFStringRef protocolType);
SCNetworkServiceRef SCNetworkServiceCopy(SCPreferencesRef prefs, CFStringRef serviceID);
CFArrayRef SCNetworkServiceCopyAll(SCPreferencesRef prefs);
SCNetworkProtocolRef SCNetworkServiceCopyProtocol(SCNetworkServiceRef service, CFStringRef protocolType);
CFArrayRef SCNetworkServiceCopyProtocols(SCNetworkServiceRef service);
SCNetworkServiceRef SCNetworkServiceCreate(SCPreferencesRef prefs, SCNetworkInterfaceRef interface);
Boolean SCNetworkServiceEstablishDefaultConfiguration(SCNetworkServiceRef service);
Boolean SCNetworkServiceGetEnabled(SCNetworkServiceRef service);
SCNetworkInterfaceRef SCNetworkServiceGetInterface(SCNetworkServiceRef service);
CFStringRef SCNetworkServiceGetName(SCNetworkServiceRef service);
CFStringRef SCNetworkServiceGetServiceID(SCNetworkServiceRef service);
CFTypeID SCNetworkServiceGetTypeID(void);
Boolean SCNetworkServiceRemove(SCNetworkServiceRef service);
Boolean SCNetworkServiceRemoveProtocolType(SCNetworkServiceRef service, CFStringRef protocolType);
Boolean SCNetworkServiceSetEnabled(SCNetworkServiceRef service, Boolean enabled);
Boolean SCNetworkServiceSetName(SCNetworkServiceRef service, CFStringRef name);

Boolean SCNetworkSetAddService(SCNetworkSetRef set, SCNetworkServiceRef service);
Boolean SCNetworkSetContainsInterface(SCNetworkSetRef set, SCNetworkInterfaceRef interface);
SCNetworkSetRef SCNetworkSetCopy(SCPreferencesRef prefs, CFStringRef setID);
CFArrayRef SCNetworkSetCopyAll(SCPreferencesRef prefs);
SCNetworkSetRef SCNetworkSetCopyCurrent(SCPreferencesRef prefs);
CFArrayRef SCNetworkSetCopyServices(SCNetworkSetRef set);
SCNetworkSetRef SCNetworkSetCreate(SCPreferencesRef prefs);
CFStringRef SCNetworkSetGetName(SCNetworkSetRef set);
CFArrayRef SCNetworkSetGetServiceOrder(SCNetworkSetRef set);
CFStringRef SCNetworkSetGetSetID(SCNetworkSetRef set);
CFTypeID SCNetworkSetGetTypeID(void);
Boolean SCNetworkSetRemove(SCNetworkSetRef set);
Boolean SCNetworkSetRemoveService(SCNetworkSetRef set, SCNetworkServiceRef service);
Boolean SCNetworkSetSetCurrent(SCNetworkSetRef set);
Boolean SCNetworkSetSetName(SCNetworkSetRef set, CFStringRef name);
Boolean SCNetworkSetSetServiceOrder(SCNetworkSetRef set, CFArrayRef newOrder);

CFArrayRef SCVLANInterfaceCopyAll(SCPreferencesRef prefs);
CFArrayRef SCVLANInterfaceCopyAvailablePhysicalInterfaces(void);
SCVLANInterfaceRef SCVLANInterfaceCreate(SCPreferencesRef prefs, SCNetworkInterfaceRef physical, CFNumberRef tag);
CFDictionaryRef SCVLANInterfaceGetOptions(SCVLANInterfaceRef vlan);
SCNetworkInterfaceRef SCVLANInterfaceGetPhysicalInterface(SCVLANInterfaceRef vlan);
CFNumberRef SCVLANInterfaceGetTag(SCVLANInterfaceRef vlan);
Boolean SCVLANInterfaceRemove(SCVLANInterfaceRef vlan);
Boolean SCVLANInterfaceSetLocalizedDisplayName(SCVLANInterfaceRef vlan, CFStringRef newName);
Boolean SCVLANInterfaceSetOptions(SCVLANInterfaceRef vlan, CFDictionaryRef newOptions);
Boolean SCVLANInterfaceSetPhysicalInterfaceAndTag(SCVLANInterfaceRef vlan, SCNetworkInterfaceRef physical, CFNumberRef tag);

CFTypeID SCNetworkConnectionGetTypeID(void);
Boolean SCNetworkConnectionCopyUserPreferences(CFDictionaryRef selectionOptions, CFStringRef*  _Nonnull serviceID, CFDictionaryRef*  _Nonnull userOptions);
CFStringRef SCNetworkConnectionCopyServiceID(SCNetworkConnectionRef connection);
SCNetworkConnectionStatus SCNetworkConnectionGetStatus(SCNetworkConnectionRef connection);
CFDictionaryRef SCNetworkConnectionCopyExtendedStatus(SCNetworkConnectionRef connection);
CFDictionaryRef SCNetworkConnectionCopyStatistics(SCNetworkConnectionRef connection);
CFDictionaryRef SCNetworkConnectionCopyUserOptions(SCNetworkConnectionRef connection);
Boolean SCNetworkConnectionStart(SCNetworkConnectionRef connection, CFDictionaryRef userOptions, Boolean linger);
Boolean SCNetworkConnectionStop(SCNetworkConnectionRef connection, Boolean forceDisconnect);
Boolean SCNetworkConnectionScheduleWithRunLoop(SCNetworkConnectionRef connection, CFRunLoopRef runLoop, CFStringRef runLoopMode);
Boolean SCNetworkConnectionUnscheduleFromRunLoop(SCNetworkConnectionRef connection, CFRunLoopRef runLoop, CFStringRef runLoopMode);
SCNetworkConnectionRef SCNetworkConnectionCreateWithServiceID(CFAllocatorRef allocator, CFStringRef serviceID, SCNetworkConnectionCallBack callout, SCNetworkConnectionContext *context);
Boolean SCNetworkConnectionSetDispatchQueue(SCNetworkConnectionRef connection, dispatch_queue_t queue);

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator, const struct sockaddr *address);
SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddressPair(CFAllocatorRef allocator, const struct sockaddr *localAddress, const struct sockaddr *remoteAddress);
SCNetworkReachabilityRef SCNetworkReachabilityCreateWithName(CFAllocatorRef allocator, const char *nodename);
Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef target, SCNetworkReachabilityFlags *flags);
CFTypeID SCNetworkReachabilityGetTypeID(void);
Boolean SCNetworkReachabilitySetCallback(SCNetworkReachabilityRef target, SCNetworkReachabilityCallBack callout, SCNetworkReachabilityContext *context);
Boolean SCNetworkReachabilityScheduleWithRunLoop(SCNetworkReachabilityRef target, CFRunLoopRef runLoop, CFStringRef runLoopMode);
Boolean SCNetworkReachabilityUnscheduleFromRunLoop(SCNetworkReachabilityRef target, CFRunLoopRef runLoop, CFStringRef runLoopMode);
Boolean SCNetworkReachabilitySetDispatchQueue(SCNetworkReachabilityRef target, dispatch_queue_t queue);


SCPreferencesRef SCPreferencesCreate(CFAllocatorRef allocator, CFStringRef name, CFStringRef prefsID);
SCPreferencesRef SCPreferencesCreateWithAuthorization(CFAllocatorRef allocator, CFStringRef name, CFStringRef prefsID, AuthorizationRef authorization);
CFTypeID SCPreferencesGetTypeID(void);
CFArrayRef SCPreferencesCopyKeyList(SCPreferencesRef prefs);
CFDataRef SCPreferencesGetSignature(SCPreferencesRef prefs);
Boolean SCPreferencesAddValue(SCPreferencesRef prefs, CFStringRef key, CFPropertyListRef value);
CFPropertyListRef SCPreferencesGetValue(SCPreferencesRef prefs, CFStringRef key);
Boolean SCPreferencesSetValue(SCPreferencesRef prefs, CFStringRef key, CFPropertyListRef value);
Boolean SCPreferencesRemoveValue(SCPreferencesRef prefs, CFStringRef key);
Boolean SCPreferencesApplyChanges(SCPreferencesRef prefs);
Boolean SCPreferencesCommitChanges(SCPreferencesRef prefs);
void SCPreferencesSynchronize(SCPreferencesRef prefs);
Boolean SCPreferencesSetCallback(SCPreferencesRef prefs, SCPreferencesCallBack callout, SCPreferencesContext *context);
Boolean SCPreferencesScheduleWithRunLoop(SCPreferencesRef prefs, CFRunLoopRef runLoop, CFStringRef runLoopMode);
Boolean SCPreferencesUnscheduleFromRunLoop(SCPreferencesRef prefs, CFRunLoopRef runLoop, CFStringRef runLoopMode);
Boolean SCPreferencesSetDispatchQueue(SCPreferencesRef prefs, dispatch_queue_t queue);
Boolean SCPreferencesLock(SCPreferencesRef prefs, Boolean wait);
Boolean SCPreferencesUnlock(SCPreferencesRef prefs);


CFStringRef SCPreferencesPathCreateUniqueChild(SCPreferencesRef prefs, CFStringRef prefix);
Boolean SCPreferencesPathSetValue(SCPreferencesRef prefs, CFStringRef path, CFDictionaryRef value);
Boolean SCPreferencesPathSetLink(SCPreferencesRef prefs, CFStringRef path, CFStringRef link);
CFDictionaryRef SCPreferencesPathGetValue(SCPreferencesRef prefs, CFStringRef path);
CFStringRef SCPreferencesPathGetLink(SCPreferencesRef prefs, CFStringRef path);
Boolean SCPreferencesPathRemoveValue(SCPreferencesRef prefs, CFStringRef path);


Boolean SCPreferencesSetComputerName(SCPreferencesRef prefs, CFStringRef name, CFStringEncoding nameEncoding);
Boolean SCPreferencesSetLocalHostName(SCPreferencesRef prefs, CFStringRef name);


CFErrorRef SCCopyLastError(void);
int SCError(void);
const char * SCErrorString(int status);

CFArrayRef CNCopySupportedInterfaces(void);
Boolean CNMarkPortalOffline(CFStringRef interfaceName);
Boolean CNMarkPortalOnline(CFStringRef interfaceName);
Boolean CNSetSupportedSSIDs(CFArrayRef ssidArray);
CFDateRef DHCPInfoGetLeaseExpirationTime(CFDictionaryRef info);
CFDictionaryRef CNCopyCurrentNetworkInfo(CFStringRef interfaceName);


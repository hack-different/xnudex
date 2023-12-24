#include <unistd.h>
#include <sys/types.h>
typedef struct va_list_t {
   unsigned int gp_offset;
   unsigned int fp_offset;
   void *overflow_arg_area;
   void *reg_save_area;
} va_list[1];

typedef struct {
} FILE;

typedef unsigned int socklen_t;

typedef void (*sig_t) (int);
sig_t signal(int sig, sig_t func);
char * strerror(int errnum);

void* dlopen(const char* path, int mode);
void* dlsym(void* handle, const char* symbol);
const char* dlerror(void);

void * memmove(void *dst, const void *src, size_t len);
int memcmp(const void *s1, const void *s2, size_t n);
void * memcpy(void * dst, const void * src, size_t n);
size_t malloc_good_size(size_t size);
size_t malloc_size(const void *ptr);
void *calloc(size_t count, size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *reallocf(void *ptr, size_t size);
void *valloc(size_t size);
void *aligned_alloc(size_t alignment, size_t size);
int printf(const char * format, ...);
int fprintf(FILE *  stream, const char * format, ...);
int sprintf(char *  str, const char *  format, ...);
int snprintf(char * str, size_t size, const char * format, ...);
int asprintf(char **ret, const char *format, ...);
int dprintf(int fd, const char * format, ...);
int vprintf(const char *  format, va_list ap);
int vfprintf(FILE *  stream, const char *  format, va_list ap);
int vsprintf(char *  str, const char *  format, va_list ap);
int vsnprintf(char *  str, size_t size, const char *  format, va_list ap);
int vasprintf(char **ret, const char *format, va_list ap);
int vdprintf(int fd, const char *  format, va_list ap);
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t recvfrom(int socket, void * buffer, size_t length, int flags, struct sockaddr * address, socklen_t * address_len);
ssize_t recvmsg(int socket, struct msghdr *message, int flags);

typedef __darwin_pthread_mutex_t	pthread_mutex_t;

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

// Audit

typedef	uid_t		au_id_t;
typedef	pid_t		au_asid_t;
typedef	u_int16_t	au_event_t;
typedef	u_int16_t	au_emod_t;
typedef	u_int32_t	au_class_t;
typedef	u_int64_t	au_asflgs_t __attribute__ ((aligned (8)));

// SysCtl

int sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
int sysctlbyname(const char *name, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
int sysctlnametomib(const char *name, int *mibp, size_t *sizep);

// Foundatoin

typedef char* StringPtr;
typedef const char* ConstStringPtr;

typedef bool Boolean;
typedef uint32_t UInt32;
typedef int32_t SInt32;
typedef uint16_t UInt16;
typedef uint8_t UInt8;
typedef signed char SInt8;
typedef unsigned long CFHashCode;
typedef unsigned long CFOptionFlags;

typedef UInt16 UniChar;

typedef enum {
} OSStatus;


typedef long CFIndex;
typedef unsigned long CFOptionFlags;
typedef UInt32 CFStringEncoding;
typedef UInt32 UTF32Char;
typedef bool boolean_t;
typedef unsigned long CFTypeID;
typedef void* CFDictionaryRef;
typedef void* CFTypeRef;
typedef struct __CFAllocator *CFAllocatorRef;
struct CFString
{
    void* isa;
    uint64_t flags;
    void* data;
    uint64_t size;
};

typedef double CFTimeInterval;
typedef struct CFString *CFStringRef;
typedef struct __CFError *CFErrorRef;
typedef struct __CFData *CFDataRef;
typedef struct __CFLocale *CFLocaleRef;
typedef struct __CFURL *CFURLRef;
typedef struct __CFArray *CFArrayRef;
typedef struct __CFDictionary *CFMutableDictionaryRef;
typedef struct __CFUserNotification CFUserNotificationRef;
typedef struct __CFRunLoopSource CFRunLoopSourceRef;
typedef CFTypeRef CFPropertyListRef;

typedef struct CFRange {
CFIndex length;
CFIndex location;
} CFRange;

typedef struct CFStringInlineBuffer {
UniChar buffer[64];
CFIndex bufferedRangeEnd;
CFIndex bufferedRangeStart;
const char *directCStringBuffer;
const UniChar *directUniCharBuffer;
CFRange rangeToBuffer;
CFStringRef theString;
} CFStringInlineBuffer;

typedef enum CFURLBookmarkResolutionOptions : CFOptionFlags {
} CFURLBookmarkResolutionOptions;

typedef enum CFURLPathStyle : CFIndex {
} CFURLPathStyle;

CFIndex CFStringGetLength(CFStringRef theString);
CFDataRef CFStringCreateExternalRepresentation(CFAllocatorRef alloc, CFStringRef theString, CFStringEncoding encoding, UInt8 lossByte);
CFIndex CFStringGetBytes(CFStringRef theString, CFRange range, CFStringEncoding encoding, UInt8 lossByte, Boolean isExternalRepresentation, UInt8 *buffer, CFIndex maxBufLen, CFIndex *usedBufLen);
UniChar CFStringGetCharacterAtIndex(CFStringRef theString, CFIndex idx);
void CFStringGetCharacters(CFStringRef theString, CFRange range, UniChar *buffer);
const UniChar * CFStringGetCharactersPtr(CFStringRef theString);
UniChar CFStringGetCharacterFromInlineBuffer(CFStringInlineBuffer *buf, CFIndex idx);
Boolean CFStringGetCString(CFStringRef theString, char *buffer, CFIndex bufferSize, CFStringEncoding encoding);
const char * CFStringGetCStringPtr(CFStringRef theString, CFStringEncoding encoding);
CFIndex CFStringGetLength(CFStringRef theString);
Boolean CFStringGetPascalString(CFStringRef theString, StringPtr buffer, CFIndex bufferSize, CFStringEncoding encoding);
ConstStringPtr CFStringGetPascalStringPtr(CFStringRef theString, CFStringEncoding encoding);
CFRange CFStringGetRangeOfComposedCharactersAtIndex(CFStringRef theString, CFIndex theIndex);
void CFStringInitInlineBuffer(CFStringRef str, CFStringInlineBuffer *buf, CFRange range);
CFIndex CFStringGetHyphenationLocationBeforeIndex(CFStringRef string, CFIndex location, CFRange limitRange, CFOptionFlags options, CFLocaleRef locale, UTF32Char *character);
Boolean CFStringIsHyphenationAvailableForLocale(CFLocaleRef locale);
CFStringRef CFStringConvertEncodingToIANACharSetName(CFStringEncoding encoding);
unsigned long CFStringConvertEncodingToNSStringEncoding(CFStringEncoding encoding);
UInt32 CFStringConvertEncodingToWindowsCodepage(CFStringEncoding encoding);
CFStringEncoding CFStringConvertIANACharSetNameToEncoding(CFStringRef theString);
CFStringEncoding CFStringConvertNSStringEncodingToEncoding(unsigned long encoding);
CFStringEncoding CFStringConvertWindowsCodepageToEncoding(UInt32 codepage);
CFStringEncoding CFStringGetFastestEncoding(CFStringRef theString);
const CFStringEncoding * CFStringGetListOfAvailableEncodings(void);
CFIndex CFStringGetMaximumSizeForEncoding(CFIndex length, CFStringEncoding encoding);
CFStringEncoding CFStringGetMostCompatibleMacStringEncoding(CFStringEncoding encoding);
CFStringRef CFStringGetNameOfEncoding(CFStringEncoding encoding);
CFStringEncoding CFStringGetSmallestEncoding(CFStringRef theString);
CFStringEncoding CFStringGetSystemEncoding(void);
Boolean CFStringIsEncodingAvailable(CFStringEncoding encoding);
double CFStringGetDoubleValue(CFStringRef str);
SInt32 CFStringGetIntValue(CFStringRef str);
void CFRelease(CFTypeRef cf);
CFTypeRef CFRetain(CFTypeRef cf);
Boolean CFEqual(CFTypeRef cf1, CFTypeRef cf2);
CFHashCode CFHash(CFTypeRef cf);
CFURLRef CFURLCopyAbsoluteURL(CFURLRef relativeURL);
CFURLRef CFURLCreateAbsoluteURLWithBytes(CFAllocatorRef alloc, const UInt8 *relativeURLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL, Boolean useCompatibilityMode);
CFURLRef CFURLCreateByResolvingBookmarkData(CFAllocatorRef allocator, CFDataRef bookmark, CFURLBookmarkResolutionOptions options, CFURLRef relativeToURL, CFArrayRef resourcePropertiesToInclude, Boolean *isStale, CFErrorRef *error);
CFURLRef CFURLCreateCopyAppendingPathComponent(CFAllocatorRef allocator, CFURLRef url, CFStringRef pathComponent, Boolean isDirectory);
CFURLRef CFURLCreateCopyAppendingPathExtension(CFAllocatorRef allocator, CFURLRef url, CFStringRef extension);
CFURLRef CFURLCreateCopyDeletingLastPathComponent(CFAllocatorRef allocator, CFURLRef url);
CFURLRef CFURLCreateCopyDeletingPathExtension(CFAllocatorRef allocator, CFURLRef url);
CFURLRef CFURLCreateFilePathURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef *error);
CFURLRef CFURLCreateFileReferenceURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef *error);
CFURLRef CFURLCreateFromFileSystemRepresentation(CFAllocatorRef allocator, const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory);
CFURLRef CFURLCreateFromFileSystemRepresentationRelativeToBase(CFAllocatorRef allocator, const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory, CFURLRef baseURL);
CFURLRef CFURLCreateFromFSRef(CFAllocatorRef allocator, const struct FSRef *fsRef);
CFURLRef CFURLCreateWithBytes(CFAllocatorRef allocator, const UInt8 *URLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL);
CFURLRef CFURLCreateWithFileSystemPath(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory);
CFURLRef CFURLCreateWithFileSystemPathRelativeToBase(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory, CFURLRef baseURL);
CFURLRef CFURLCreateWithString(CFAllocatorRef allocator, CFStringRef URLString, CFURLRef baseURL);
Boolean CFURLCanBeDecomposed(CFURLRef anURL);
CFStringRef CFURLCopyFileSystemPath(CFURLRef anURL, CFURLPathStyle pathStyle);
CFStringRef CFURLCopyFragment(CFURLRef anURL, CFStringRef charactersToLeaveEscaped);
SInt32 CFUserNotificationCancel(CFUserNotificationRef userNotification);
CFUserNotificationRef CFUserNotificationCreate(CFAllocatorRef allocator, CFTimeInterval timeout, CFOptionFlags flags, SInt32 *error, CFDictionaryRef dictionary);
SInt32 CFUserNotificationReceiveResponse(CFUserNotificationRef userNotification, CFTimeInterval timeout, CFOptionFlags *responseFlags);
void CFRunLoopRun(void);

void NSLog(CFStringRef format, ...);

// Objc

typedef void* id;
typedef struct _objc_class {
} objc_class_t;
typedef objc_class_t* Class;

id objc_autorelease(id value);
void objc_autoreleasePoolPop(void *pool);
void *objc_autoreleasePoolPush(void);
id objc_autoreleaseReturnValue(id value);
void objc_copyWeak(id *dest, id *src);
void objc_destroyWeak(id *object);
id objc_initWeak(id *object, id value);
id objc_loadWeak(id *object);
id objc_loadWeakRetained(id *object);
void objc_moveWeak(id *dest, id *src);
void objc_release(id value);
id objc_retain(id value);
id objc_retainAutorelease(id value);
id objc_retainAutoreleaseReturnValue(id value);
id objc_retainAutoreleasedReturnValue(id value);
id objc_retainBlock(id value);
void objc_storeStrong(id *object, id value);
id objc_storeWeak(id *object, id value);
id objc_unsafeClaimAutoreleasedReturnValue(id value);
id _Nullable objc_alloc_init(Class _Nullable cls);
id _Nullable objc_allocWithZone(Class _Nullable cls);
id _Nullable objc_alloc_init(Class _Nullable cls);
int objc_sync_enter(id obj);
int objc_sync_exit(id obj);
int objc_sync_wait(id obj, long long milliSecondsMaxWait);
int objc_sync_notify(id obj);
int objc_sync_notifyAll(id obj);
enum {
	OBJC_SYNC_SUCCESS                 = 0,
	OBJC_SYNC_NOT_OWNING_THREAD_ERROR = -1,
	OBJC_SYNC_TIMED_OUT               = -2,
	OBJC_SYNC_NOT_INITIALIZED         = -3
};

typedef void* dispatch_queue_t;


// Mach

typedef struct ipc_port *ipc_port_t;
typedef ipc_port_t mach_port_t;
typedef struct task *task_t;
typedef int kern_return_t;
typedef task_t task_port_t;
typedef struct mach_msg_header_t {
} mach_msg_header_t;

void mig_dealloc_reply_port(mach_port_t reply_port);
void mach_msg_destroy_from_kernel_proper(mach_msg_header_t *msg);
void mig_put_reply_port(mach_port_t reply_port);
mach_port_t mig_get_reply_port(void);

// IOKit


typedef mach_port_t io_object_t;
typedef io_object_t io_connect_t;
typedef io_object_t io_service_t;
typedef io_object_t io_iterator_t;
typedef char io_name_t[128];

typedef struct IONotificationPort *IONotificationPortRef;

typedef void (*IOServiceMatchingCallback)(void *refcon, io_iterator_t iterator);
typedef void (*IOServiceInterestCallback)(void *refcon, io_service_t service, uint32_t messageType, void *messageArgument);

kern_return_t IOServiceClose(io_connect_t connect);
kern_return_t IOServiceOpen(io_service_t service, task_port_t owningTask, uint32_t type, io_connect_t *connect);
io_service_t IOServiceGetMatchingService(mach_port_t mainPort, CFDictionaryRef matching);
kern_return_t IOServiceGetMatchingServices(mach_port_t mainPort, CFDictionaryRef matching, io_iterator_t *existing);
CFMutableDictionaryRef IOServiceNameMatching(const char *name);
CFMutableDictionaryRef IOServiceMatching(const char *name);
kern_return_t IOServiceAddMatchingNotification(IONotificationPortRef notifyPort, const io_name_t notificationType, CFDictionaryRef matching, IOServiceMatchingCallback callback, void *refCon, io_iterator_t *notification);
kern_return_t IOServiceAddInterestNotification(IONotificationPortRef notifyPort, io_service_t service, const io_name_t interestType, IOServiceInterestCallback callback, void *refCon, io_object_t *notification);
kern_return_t IOMasterPort(mach_port_t bootstrapPort, mach_port_t *mainPort);
IONotificationPortRef IONotificationPortCreate(mach_port_t mainPort);
void IONotificationPortDestroy(IONotificationPortRef notify);
mach_port_t IONotificationPortGetMachPort(IONotificationPortRef notify);
CFRunLoopSourceRef IONotificationPortGetRunLoopSource(IONotificationPortRef notify);
void IONotificationPortSetDispatchQueue(IONotificationPortRef notify, dispatch_queue_t queue);
boolean_t IOObjectConformsTo(io_object_t object, const io_name_t className);
CFStringRef IOObjectCopyBundleIdentifierForClass(CFStringRef classname);
CFStringRef IOObjectCopyClass(io_object_t object);
CFStringRef IOObjectCopySuperclassForClass(CFStringRef classname);
kern_return_t IOObjectGetClass(io_object_t object, io_name_t className);
uint32_t IOObjectGetKernelRetainCount(io_object_t object);
uint32_t IOObjectGetRetainCount(io_object_t object);
uint32_t IOObjectGetUserRetainCount(io_object_t object);



// OS

#define _OS_OBJECT_HEADER(isa, ref_cnt, xref_cnt) \
        isa; /* must be pointer-sized */ \
        int volatile ref_cnt; \
        int volatile xref_cnt

struct os_transaction_s {
	_OS_OBJECT_HEADER(
		const struct os_transaction_vtable_s* os_obj_isa,
		os_obj_ref_cnt,
		os_obj_xref_cnt
	);
};

typedef struct os_transaction_s* os_transaction_t;
typedef void *os_log_t;
typedef enum os_log_type_t : uint8_t {

} os_log_type_t;

bool os_variant_has_internal_content(const char *subsystem);
bool os_variant_has_internal_diagnostics(const char *subsystem);
bool os_variant_has_internal_ui(const char *subsystem);
bool os_variant_allows_internal_security_policies(const char *subsystem);
bool os_variant_has_factory_content(const char *subsystem);
bool os_variant_is_darwinos(const char *subsystem);
bool os_variant_uses_ephemeral_storage(const char *subsystem);
bool os_variant_is_recovery(const char *subsystem);
bool os_variant_check(const char *subsystem, const char *variant);

os_transaction_t os_transaction_create(const char* name);
bool os_log_type_enabled(os_log_t oslog, os_log_type_t type);

// Security

typedef struct __SecKeychainItem SecKeychainItemRef;
typedef struct __SecKey SecKeyRef;
typedef struct __SecAccessControl SecAccessControlRef;
typedef struct __SecPolicy SecPolicyRef;
typedef struct __SecTrust SecTrustRef;
typedef struct __SecCertificate SecCertificateRef;
typedef struct __SecIdentity SecIdentityRef;
typedef const struct __SecRandom *SecRandomRef;
typedef struct OpaqueSecIdentitySearchRef SecIdentitySearchRef;
typedef enum SecAccessControlCreateFlags : CFOptionFlags {
} SecAccessControlCreateFlags;
typedef enum SecExternalFormat : uint32_t {
} SecExternalFormat;
typedef enum SecItemImportExportFlags : uint32_t {
} SecItemImportExportFlags;
typedef struct SecItemImportExportKeyParameters {
} SecItemImportExportKeyParameters;
OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef  _Nullable *result);
OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef  _Nullable *result);
CFTypeID SecKeychainItemGetTypeID(void);
OSStatus SecItemUpdate(CFDictionaryRef query, CFDictionaryRef attributesToUpdate);
OSStatus SecItemDelete(CFDictionaryRef query);
SecAccessControlRef SecAccessControlCreateWithFlags(CFAllocatorRef allocator, CFTypeRef protection, SecAccessControlCreateFlags flags, CFErrorRef  _Nullable *error);
OSStatus SecItemExport(CFTypeRef secItemOrArray, SecExternalFormat outputFormat, SecItemImportExportFlags flags, const SecItemImportExportKeyParameters *keyParams, CFDataRef  _Nullable *exportedData);
SecKeyRef SecTrustCopyKey(SecTrustRef trust);
int SecRandomCopyBytes(SecRandomRef rnd, size_t count, void *bytes);
SecPolicyRef SecPolicyCreateRevocation(CFOptionFlags revocationFlags);
CFDataRef SecCertificateCopyData(SecCertificateRef certificate);
SecKeyRef SecCertificateCopyKey(SecCertificateRef certificate);
SecCertificateRef SecCertificateCreateWithData(CFAllocatorRef allocator, CFDataRef data);
OSStatus SecIdentityCopyCertificate(SecIdentityRef identityRef, SecCertificateRef*  _Nullable certificateRef);
OSStatus SecIdentityCopyPrivateKey(SecIdentityRef identityRef, SecKeyRef*  _Nullable privateKeyRef);

extern const CFStringRef _kSecUseKeychain;
extern const CFStringRef _kSecAttrModificationDate;

// SSL

typedef struct SSLContext SSLContextRef;
typedef const void *SSLConnectionRef;
typedef uint16_t SSLCipherSuite;

typedef enum SSLProtocolSide : int {
    kSSLServerSide,
    kSSLClientSide
} SSLProtocolSide;
typedef enum SSLClientCertificateState : int {
    kSSLClientCertNone,
    kSSLClientCertRequested,
    kSSLClientCertSent,
    kSSLClientCertRejected
} SSLClientCertificateState;
typedef enum SSLConnectionType : int {
    kSSLStreamType,
    kSSLDatagramType
} SSLConnectionType;
typedef enum SSLSessionOption : int {
    kSSLSessionOptionBreakOnServerAuth = 0,
    kSSLSessionOptionBreakOnCertRequested = 1,
    kSSLSessionOptionBreakOnClientAuth = 2,
    kSSLSessionOptionFalseStart = 3,
    kSSLSessionOptionSendOneByteRecord = 4,
    kSSLSessionOptionAllowServerIdentityChange = 5,
    kSSLSessionOptionFallback = 6,
    kSSLSessionOptionBreakOnClientHello = 7,
    kSSLSessionOptionAllowRenegotiation = 8,
    kSSLSessionOptionEnableSessionTickets = 9
} SSLSessionOption;
typedef enum SSLAuthenticate : int {
    kNeverAuthenticate,
    kAlwaysAuthenticate,
    kTryAuthenticate
} SSLAuthenticate;
typedef enum SSLSessionState : int {
    kSSLIdle,
    kSSLHandshake,
    kSSLConnected,
    kSSLClosed,
    kSSLAborted
} SSLSessionState;
typedef enum tls_protocol_version_t : uint16_t {
    tls_protocol_version_TLSv10 = 0x0301,
    tls_protocol_version_TLSv11 = 0x0302,
    tls_protocol_version_TLSv12 = 0x0303,
    tls_protocol_version_TLSv13 = 0x0304,
    tls_protocol_version_DTLSv10 = 0xfeff,
    tls_protocol_version_DTLSv12 = 0xfefd
} tls_protocol_version_t;
typedef enum SSLProtocol : int {
    kSSLProtocolUnknown = 0,
    kSSLProtocol2 = 1,
    kSSLProtocol3 = 2,
    kSSLProtocol3Only = 3,
    kSSLProtocolAll = 6,
    kTLSProtocol1 = 4,
    kTLSProtocol1Only = 5,
    kTLSProtocol11 = 7,
    kTLSProtocol12 = 8,
    kTLSProtocol13 = 10,
    kTLSProtocolMaxSupported = 999,
    kDTLSProtocol1 = 9,
    kDTLSProtocol12 = 11
} SSLProtocol;
typedef enum tls_ciphersuite_group_t : uint16_t {
    tls_ciphersuite_group_ats,
    tls_ciphersuite_group_ats_compatibility,
    tls_ciphersuite_group_compatibility,
    tls_ciphersuite_group_default,
    tls_ciphersuite_group_legacy,
} tls_ciphersuite_group_t;
typedef enum tls_ciphersuite_t : uint16_t {
    tls_ciphersuite_AES_128_GCM_SHA256 = 0x1301,
    tls_ciphersuite_AES_256_GCM_SHA384 = 0x1302,
    tls_ciphersuite_CHACHA20_POLY1305_SHA256 = 0x1303,
    tls_ciphersuite_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA = 0xC008,
    tls_ciphersuite_ECDHE_ECDSA_WITH_AES_128_CBC_SHA = 0xC009,
    tls_ciphersuite_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 = 0xC023,
    tls_ciphersuite_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 = 0xC02B,
    tls_ciphersuite_ECDHE_ECDSA_WITH_AES_256_CBC_SHA = 0xC00A,
    tls_ciphersuite_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 = 0xC024,
    tls_ciphersuite_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 = 0xC02C,
    tls_ciphersuite_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256 = 0xCCA9,
    tls_ciphersuite_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA = 0xC012,
    tls_ciphersuite_ECDHE_RSA_WITH_AES_128_CBC_SHA = 0xC013,
    tls_ciphersuite_ECDHE_RSA_WITH_AES_128_CBC_SHA256 = 0xC027,
    tls_ciphersuite_ECDHE_RSA_WITH_AES_128_GCM_SHA256 = 0xC02F,
    tls_ciphersuite_ECDHE_RSA_WITH_AES_256_CBC_SHA = 0xC014,
    tls_ciphersuite_ECDHE_RSA_WITH_AES_256_CBC_SHA384 = 0xC028,
    tls_ciphersuite_ECDHE_RSA_WITH_AES_256_GCM_SHA384 = 0xC030,
    tls_ciphersuite_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256 = 0xCCA8,
    tls_ciphersuite_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,
    tls_ciphersuite_RSA_WITH_AES_128_CBC_SHA = 0x002F,
    tls_ciphersuite_RSA_WITH_AES_128_CBC_SHA256 = 0x003C,
    tls_ciphersuite_RSA_WITH_AES_128_GCM_SHA256 = 0x009C,
    tls_ciphersuite_RSA_WITH_AES_256_CBC_SHA = 0x0035,
    tls_ciphersuite_RSA_WITH_AES_256_CBC_SHA256 = 0x003D,
    tls_ciphersuite_RSA_WITH_AES_256_GCM_SHA384 = 0x009D
} tls_ciphersuite_t;
typedef enum SSLCiphersuiteGroup : int {
    kSSLCiphersuiteGroupDefault,
    kSSLCiphersuiteGroupCompatibility,
    kSSLCiphersuiteGroupLegacy,
    kSSLCiphersuiteGroupATS,
    kSSLCiphersuiteGroupATSCompatibility
} SSLCiphersuiteGroup;

typedef OSStatus (*SSLReadFunc)(SSLConnectionRef connection, void *data, size_t *dataLength);

SSLContextRef SSLCreateContext(CFAllocatorRef alloc, SSLProtocolSide protocolSide, SSLConnectionType connectionType);
CFTypeID SSLContextGetTypeID(void);
OSStatus SSLSetClientSideAuthenticate(SSLContextRef context, SSLAuthenticate auth);
OSStatus SSLSetSessionOption(SSLContextRef context, SSLSessionOption option, Boolean value);
OSStatus SSLGetSessionOption(SSLContextRef context, SSLSessionOption option, Boolean *value);
OSStatus SSLSetConnection(SSLContextRef context, SSLConnectionRef connection);
OSStatus SSLGetConnection(SSLContextRef context, SSLConnectionRef  _Nullable *connection);
OSStatus SSLHandshake(SSLContextRef context);
OSStatus SSLReHandshake(SSLContextRef context);
OSStatus SSLClose(SSLContextRef context);
OSStatus SSLSetPeerID(SSLContextRef context, const void *peerID, size_t peerIDLen);
OSStatus SSLGetPeerID(SSLContextRef context, const void * _Nullable *peerID, size_t *peerIDLen);
OSStatus SSLGetSessionState(SSLContextRef context, SSLSessionState *state);
OSStatus SSLRead(SSLContextRef context, void *data, size_t dataLength, size_t *processed);
OSStatus SSLGetBufferedReadSize(SSLContextRef context, size_t *bufferSize);
OSStatus SSLWrite(SSLContextRef context, const void *data, size_t dataLength, size_t *processed);
OSStatus SSLGetDatagramWriteSize(SSLContextRef dtlsContext, size_t *bufSize);
OSStatus SSLGetMaxDatagramRecordSize(SSLContextRef dtlsContext, size_t *maxSize);
OSStatus SSLSetMaxDatagramRecordSize(SSLContextRef dtlsContext, size_t maxSize);
OSStatus SSLSetDatagramHelloCookie(SSLContextRef dtlsContext, const void *cookie, size_t cookieLen);
OSStatus SSLSetPeerDomainName(SSLContextRef context, const char *peerName, size_t peerNameLen);
OSStatus SSLGetPeerDomainNameLength(SSLContextRef context, size_t *peerNameLen);
OSStatus SSLGetPeerDomainName(SSLContextRef context, char *peerName, size_t *peerNameLen);
OSStatus SSLCopyRequestedPeerName(SSLContextRef context, char *peerName, size_t *peerNameLen);
OSStatus SSLCopyRequestedPeerNameLength(SSLContextRef ctx, size_t *peerNameLen);
OSStatus SSLSetProtocolVersionMax(SSLContextRef context, SSLProtocol maxVersion);
OSStatus SSLSetProtocolVersionMin(SSLContextRef context, SSLProtocol minVersion);
OSStatus SSLGetProtocolVersionMax(SSLContextRef context, SSLProtocol *maxVersion);
OSStatus SSLGetProtocolVersionMin(SSLContextRef context, SSLProtocol *minVersion);
OSStatus SSLGetNegotiatedProtocolVersion(SSLContextRef context, SSLProtocol *protocol);
OSStatus SSLCopyALPNProtocols(SSLContextRef context, CFArrayRef  _Nullable *protocols);
OSStatus SSLSetALPNProtocols(SSLContextRef context, CFArrayRef protocols);
OSStatus SSLGetNumberSupportedCiphers(SSLContextRef context, size_t *numCiphers);
OSStatus SSLGetSupportedCiphers(SSLContextRef context, SSLCipherSuite *ciphers, size_t *numCiphers);
OSStatus SSLSetEnabledCiphers(SSLContextRef context, const SSLCipherSuite *ciphers, size_t numCiphers);
OSStatus SSLGetNumberEnabledCiphers(SSLContextRef context, size_t *numCiphers);
OSStatus SSLGetEnabledCiphers(SSLContextRef context, SSLCipherSuite *ciphers, size_t *numCiphers);
OSStatus SSLGetNegotiatedCipher(SSLContextRef context, SSLCipherSuite *cipherSuite);
OSStatus SSLSetDiffieHellmanParams(SSLContextRef context, const void *dhParams, size_t dhParamsLen);
OSStatus SSLGetDiffieHellmanParams(SSLContextRef context, const void * _Nullable *dhParams, size_t *dhParamsLen);
OSStatus SSLSetCertificateAuthorities(SSLContextRef context, CFTypeRef certificateOrArray, Boolean replaceExisting);
OSStatus SSLCopyCertificateAuthorities(SSLContextRef context, CFArrayRef  _Nullable *certificates);
OSStatus SSLAddDistinguishedName(SSLContextRef context, const void *derDN, size_t derDNLen);
OSStatus SSLCopyDistinguishedNames(SSLContextRef context, CFArrayRef  _Nullable *names);
OSStatus SSLSetCertificate(SSLContextRef context, CFArrayRef certRefs);
OSStatus SSLGetClientCertificateState(SSLContextRef context, SSLClientCertificateState *clientState);
OSStatus SSLCopyPeerTrust(SSLContextRef context, SecTrustRef*  _Nullable trust);
OSStatus SSLSetOCSPResponse(SSLContextRef context, CFDataRef response);
OSStatus SSLSetSessionTicketsEnabled(SSLContextRef context, Boolean enabled);
OSStatus SSLNewContext(Boolean isServer, SSLContextRef*  _Nullable contextPtr);



// GrandCentralDispatch

typedef uint64_t dispatch_time_t;
typedef void* dispatch_data_t;
typedef void *dispatch_queue_main_t;
typedef void *dispatch_queue_global_t;
typedef void *dispatch_queue_serial_t;
typedef void *dispatch_queue_concurrent_t;
typedef void *dispatch_queue_attr_t;
typedef void *dispatch_object_t;
typedef void *dispatch_semaphore_t;
typedef void *dispatch_source_t;
typedef void *dispatch_group_t;
typedef intptr_t dispatch_once_t;
typedef const struct dispatch_source_type_s *dispatch_source_type_t;
typedef void (^dispatch_block_t)(void);
typedef void (*dispatch_function_t)(void *);
void dispatch_once(dispatch_once_t *predicate, dispatch_block_t block);
void dispatch_apply(size_t iterations, dispatch_queue_t queue, void (^block)(size_t iteration));
void dispatch_sync(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_sync_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
dispatch_data_t dispatch_data_create(const void *buffer, size_t size, dispatch_queue_t queue, dispatch_block_t destructor);
void dispatch_barrier_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
dispatch_queue_main_t dispatch_get_main_queue(void);
dispatch_queue_global_t dispatch_get_global_queue(intptr_t identifier, uintptr_t flags);
dispatch_queue_t dispatch_queue_create(const char *label, dispatch_queue_attr_t attr);
dispatch_queue_t dispatch_queue_create_with_target(const char *label, dispatch_queue_attr_t attr, dispatch_queue_t target);
void dispatch_resume(dispatch_object_t object);
void dispatch_activate(dispatch_object_t object);
void dispatch_suspend(dispatch_object_t object);
dispatch_time_t dispatch_time(dispatch_time_t when, int64_t delta);
dispatch_time_t dispatch_walltime(const struct timespec *when, int64_t delta);
dispatch_semaphore_t dispatch_semaphore_create(intptr_t value);
intptr_t dispatch_semaphore_signal(dispatch_semaphore_t dsema);
intptr_t dispatch_semaphore_wait(dispatch_semaphore_t dsema, dispatch_time_t timeout);
void dispatch_source_cancel(dispatch_source_t source);
dispatch_source_t dispatch_source_create(dispatch_source_type_t type, uintptr_t handle, uintptr_t mask, dispatch_queue_t queue);
uintptr_t dispatch_source_get_data(dispatch_source_t source);
void dispatch_source_set_cancel_handler(dispatch_source_t source, dispatch_block_t handler);
void dispatch_source_set_event_handler(dispatch_source_t source, dispatch_block_t handler);
void dispatch_source_set_timer(dispatch_source_t source, dispatch_time_t start, uint64_t interval, uint64_t leeway);
void dispatch_after(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block);
size_t dispatch_data_get_size(dispatch_data_t data);
void dispatch_group_async(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block);
dispatch_group_t dispatch_group_create(void);
void dispatch_group_enter(dispatch_group_t group);
void dispatch_group_leave(dispatch_group_t group);
void dispatch_main(void);
intptr_t dispatch_group_wait(dispatch_group_t group, dispatch_time_t timeout);
void dispatch_group_notify(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block);
void dispatch_release(dispatch_object_t object);


// System Configuration

typedef struct __SCPreferences SCPreferencesRef;
typedef struct __SCDynamicStore SCDynamicStoreRef;
typedef struct __SCNetworkInterface SCNetworkInterfaceRef;
typedef const struct AuthorizationOpaqueRef *AuthorizationRef;
typedef void (*SCDynamicStoreCallBack)(SCDynamicStoreRef store, CFArrayRef changedKeys, void *info);
typedef struct SCDynamicStoreContext {
CFStringRef  _Nonnull (*copyDescription)(const void *info);
void *info;
void (*release)(const void *info);
const void * _Nonnull (*retain)(const void *info);
CFIndex version;
} SCDynamicStoreContext;

SCPreferencesRef SCPreferencesCreate(CFAllocatorRef allocator, CFStringRef name, CFStringRef prefsID);
SCPreferencesRef SCPreferencesCreateWithAuthorization(CFAllocatorRef allocator, CFStringRef name, CFStringRef prefsID, AuthorizationRef authorization);
CFTypeID SCPreferencesGetTypeID(void);
CFArrayRef SCPreferencesCopyKeyList(SCPreferencesRef prefs);
CFDataRef SCPreferencesGetSignature(SCPreferencesRef prefs);
CFPropertyListRef SCPreferencesGetValue(SCPreferencesRef prefs, CFStringRef key);
Boolean SCPreferencesAddValue(SCPreferencesRef prefs, CFStringRef key, CFPropertyListRef value);
Boolean SCPreferencesSetValue(SCPreferencesRef prefs, CFStringRef key, CFPropertyListRef value);
Boolean SCPreferencesRemoveValue(SCPreferencesRef prefs, CFStringRef key);
CFStringRef SCDynamicStoreCopyComputerName(SCDynamicStoreRef store, CFStringEncoding *nameEncoding);
CFStringRef SCDynamicStoreCopyConsoleUser(SCDynamicStoreRef store, uid_t *uid, gid_t *gid);
CFStringRef SCDynamicStoreCopyLocalHostName(SCDynamicStoreRef store);
CFStringRef SCDynamicStoreCopyLocation(SCDynamicStoreRef store);
CFDictionaryRef SCDynamicStoreCopyProxies(SCDynamicStoreRef store);
Boolean SCPreferencesSetLocalHostName(SCPreferencesRef prefs, CFStringRef name);
Boolean SCPreferencesSetComputerName(SCPreferencesRef prefs, CFStringRef name, CFStringEncoding nameEncoding);
Boolean SCPreferencesCommitChanges(SCPreferencesRef prefs);
Boolean SCPreferencesApplyChanges(SCPreferencesRef prefs);
Boolean SCPreferencesLock(SCPreferencesRef prefs, Boolean wait);
Boolean SCPreferencesUnlock(SCPreferencesRef prefs);
CFStringRef SCNetworkInterfaceGetInterfaceType(SCNetworkInterfaceRef interface);
CFStringRef SCNetworkInterfaceGetBSDName(SCNetworkInterfaceRef interface);
CFArrayRef SCNetworkInterfaceCopyAll(void);
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

// Network

typedef struct _DNSServiceRef_t *DNSServiceRef;
typedef struct _DNSRecordRef_t *DNSRecordRef;
typedef int dnssd_sock_t;
typedef int32_t DNSServiceErrorType;

void DNSServiceRefDeallocate(DNSServiceRef sdRef);
DNSServiceErrorType DNSServiceGetProperty(const char *property, void *result, uint32_t *size);
DNSServiceErrorType DNSServiceProcessResult(DNSServiceRef sdRef);
void DNSServiceRefDeallocate(DNSServiceRef sdRef);
dnssd_sock_t DNSServiceRefSockFD(DNSServiceRef sdRef);
DNSServiceErrorType DNSServiceCreateDelegateConnection (
   DNSServiceRef *sdRef,
   int32_t pid,
   uuid_t uuid
);



// XPC
typedef const struct _xpc_type_s * xpc_type_t;
typedef void * xpc_object_t;
typedef void * xpc_connection_t;
typedef void * xpc_endpoint_t;
typedef void * xpc_activity_t;
typedef void (^xpc_handler_t)(xpc_object_t object);
typedef void (*xpc_connection_handler_t)(xpc_connection_t connection);

typedef enum : unsigned int {
} xpc_activity_state_t;

typedef void (*xpc_finalizer_t)(void *value);

xpc_connection_t xpc_connection_create(const char *name, dispatch_queue_t targetq);
xpc_connection_t xpc_connection_create_mach_service(const char *name, dispatch_queue_t targetq, uint64_t flags);
xpc_connection_t xpc_connection_create_from_endpoint(xpc_endpoint_t endpoint);
void xpc_connection_set_target_queue(xpc_connection_t connection, dispatch_queue_t targetq);
void xpc_connection_set_event_handler(xpc_connection_t connection, xpc_handler_t handler);
void xpc_connection_suspend(xpc_connection_t connection);
void xpc_connection_resume(xpc_connection_t connection);
void xpc_connection_send_message(xpc_connection_t connection, xpc_object_t message);
void xpc_connection_send_barrier(xpc_connection_t connection, dispatch_block_t barrier);
void xpc_connection_send_message_with_reply(xpc_connection_t connection,	xpc_object_t message, dispatch_queue_t replyq, xpc_handler_t handler);
xpc_object_t xpc_connection_send_message_with_reply_sync(xpc_connection_t connection, xpc_object_t message);
void xpc_connection_cancel(xpc_connection_t connection);
const char * xpc_connection_get_name(xpc_connection_t connection);
uid_t xpc_connection_get_euid(xpc_connection_t connection);
gid_t xpc_connection_get_egid(xpc_connection_t connection);
pid_t xpc_connection_get_pid(xpc_connection_t connection);
au_asid_t xpc_connection_get_asid(xpc_connection_t connection);
void xpc_connection_set_context(xpc_connection_t connection, void *context);
void * xpc_connection_get_context(xpc_connection_t connection);
void xpc_connection_set_finalizer_f(xpc_connection_t connection, xpc_finalizer_t finalizer);

const char *_xpc_event_key_name;
xpc_object_t xpc_retain(xpc_object_t object);
void xpc_release(xpc_object_t object);
xpc_type_t xpc_get_type(xpc_object_t object);
xpc_object_t xpc_copy(xpc_object_t object);
bool xpc_equal(xpc_object_t object1, xpc_object_t object2);
size_t xpc_hash(xpc_object_t object);
char * xpc_copy_description(xpc_object_t object);
xpc_object_t xpc_null_create(void);
xpc_object_t xpc_bool_create(bool value);
bool xpc_bool_get_value(xpc_object_t xbool);
xpc_object_t xpc_int64_create(int64_t value);
int64_t xpc_int64_get_value(xpc_object_t xint);
xpc_object_t xpc_uint64_create(uint64_t value);
uint64_t xpc_uint64_get_value(xpc_object_t xuint);
xpc_object_t xpc_double_create(double value);
double xpc_double_get_value(xpc_object_t xdouble);
xpc_object_t xpc_date_create(int64_t interval);
xpc_object_t xpc_date_create_from_current(void);
int64_t xpc_date_get_value(xpc_object_t xdate);
xpc_object_t xpc_data_create(const void *bytes, size_t length);
xpc_object_t xpc_data_create_with_dispatch_data(dispatch_data_t ddata);
size_t xpc_data_get_length(xpc_object_t xdata);
const void * xpc_data_get_bytes_ptr(xpc_object_t xdata);
size_t xpc_data_get_bytes(xpc_object_t xdata, void *buffer, size_t off, size_t length);
xpc_object_t xpc_string_create(const char *string);
xpc_object_t xpc_string_create_with_format(const char *fmt, ...);
xpc_object_t xpc_string_create_with_format_and_arguments(const char *fmt, va_list ap);
size_t xpc_string_get_length(xpc_object_t xstring);
const char * xpc_string_get_string_ptr(xpc_object_t xstring);
xpc_object_t xpc_uuid_create(const uuid_t uuid);
const uint8_t * xpc_uuid_get_bytes(xpc_object_t xuuid);
xpc_object_t xpc_fd_create(int fd);
int xpc_fd_dup(xpc_object_t xfd);
xpc_object_t xpc_shmem_create(void *region, size_t length);
size_t xpc_shmem_map(xpc_object_t xshmem, void **region);
typedef bool (^xpc_array_applier_t)(size_t index, xpc_object_t value);
xpc_object_t xpc_array_create(const xpc_object_t *objects, size_t count);
void xpc_array_set_value(xpc_object_t xarray, size_t index, xpc_object_t value);
void xpc_array_append_value(xpc_object_t xarray, xpc_object_t value);
size_t xpc_array_get_count(xpc_object_t xarray);
xpc_object_t xpc_array_get_value(xpc_object_t xarray, size_t index);
bool xpc_array_apply(xpc_object_t xarray, xpc_array_applier_t applier);
void xpc_array_set_bool(xpc_object_t xarray, size_t index, bool value);
void xpc_array_set_int64(xpc_object_t xarray, size_t index, int64_t value);
void xpc_array_set_uint64(xpc_object_t xarray, size_t index, uint64_t value);
void xpc_array_set_double(xpc_object_t xarray, size_t index, double value);
void xpc_set_event_stream_handler(const char *stream, dispatch_queue_t targetq, xpc_handler_t handler);
const char * xpc_dictionary_get_string(xpc_object_t xdict, const char *key);
uint64_t xpc_dictionary_get_uint64(xpc_object_t xdict, const char *key);
const uint8_t * xpc_dictionary_get_uuid(xpc_object_t xdict, const char *key);
void xpc_dictionary_set_bool(xpc_object_t xdict, const char *key, bool value);
void xpc_dictionary_set_connection(xpc_object_t xdict, const char *key, xpc_connection_t connection);
void xpc_dictionary_set_data(xpc_object_t xdict, const char *key, const void *bytes, size_t length);
void xpc_dictionary_set_date(xpc_object_t xdict, const char *key, int64_t value);
void xpc_dictionary_set_double(xpc_object_t xdict, const char *key, double value);
void xpc_dictionary_set_fd(xpc_object_t xdict, const char *key, int fd);
void xpc_dictionary_set_int64(xpc_object_t xdict, const char *key, int64_t value);
void xpc_dictionary_set_string(xpc_object_t xdict, const char *key, const char *string);
void xpc_dictionary_set_uint64(xpc_object_t xdict, const char *key, uint64_t value);
void xpc_dictionary_set_uuid(xpc_object_t xdict, const char *key, const unsigned char *uuid);
typedef bool (^xpc_dictionary_applier_t)(const char *key, xpc_object_t value);
xpc_object_t xpc_dictionary_create(const char *const  _Nonnull *keys, xpc_object_t  _Nullable const *values, size_t count);
xpc_object_t xpc_dictionary_create_empty(void);
xpc_connection_t xpc_dictionary_create_connection(xpc_object_t xdict, const char *key);
xpc_object_t xpc_dictionary_create_reply(xpc_object_t original);
void xpc_dictionary_set_value(xpc_object_t xdict, const char *key, xpc_object_t value);
size_t xpc_dictionary_get_count(xpc_object_t xdict);
xpc_object_t xpc_dictionary_get_value(xpc_object_t xdict, const char *key);
bool xpc_dictionary_apply(xpc_object_t xdict, xpc_dictionary_applier_t applier);
int xpc_dictionary_dup_fd(xpc_object_t xdict, const char *key);
xpc_object_t xpc_dictionary_get_array(xpc_object_t xdict, const char *key);
bool xpc_dictionary_get_bool(xpc_object_t xdict, const char *key);
const void * xpc_dictionary_get_data(xpc_object_t xdict, const char *key, size_t *length);
int64_t xpc_dictionary_get_date(xpc_object_t xdict, const char *key);
xpc_object_t xpc_dictionary_get_dictionary(xpc_object_t xdict, const char *key);
double xpc_dictionary_get_double(xpc_object_t xdict, const char *key);
int64_t xpc_dictionary_get_int64(xpc_object_t xdict, const char *key);
xpc_connection_t xpc_dictionary_get_remote_connection(xpc_object_t xdict);
xpc_object_t xpc_string_create(const char *string);
xpc_object_t xpc_string_create_with_format(const char *fmt, ...);
xpc_object_t xpc_string_create_with_format_and_arguments(const char *fmt, va_list ap);
size_t xpc_string_get_length(xpc_object_t xstring);
const char * xpc_string_get_string_ptr(xpc_object_t xstring);
xpc_object_t xpc_fd_create(int fd);
int xpc_fd_dup(xpc_object_t xfd);
xpc_object_t xpc_date_create(int64_t interval);
xpc_object_t xpc_date_create_from_current(void);
int64_t xpc_date_get_value(xpc_object_t xdate);
xpc_object_t xpc_uuid_create(const unsigned char *uuid);
const uint8_t * xpc_uuid_get_bytes(xpc_object_t xuuid);
xpc_endpoint_t xpc_endpoint_create(xpc_connection_t connection);

typedef void (^xpc_activity_handler_t)(xpc_activity_t activity);

void xpc_activity_register(const char *identifier, xpc_object_t criteria, xpc_activity_handler_t handler);
void xpc_activity_unregister(const char *identifier);
xpc_activity_state_t xpc_activity_get_state(xpc_activity_t activity);
bool xpc_activity_set_state(xpc_activity_t activity, xpc_activity_state_t state);
bool xpc_activity_should_defer(xpc_activity_t activity);
void xpc_set_event(const char* stream, const char* event_name, xpc_object_t xdict);



// Swift


struct OpaqueValue;
struct swift_once_t;
enum class MetadataState : size_t {
  Complete = 0x00,
  NonTransitiveComplete = 0x01,
  LayoutComplete = 0x3F,
  Abstract = 0xFF,
};

typedef struct HeapMetadata HeapMetadata;
typedef struct HeapObject HeapObject;
struct InProcess {

};
struct TargetMetadata {};
struct TargetForeignTypeMetadata {
};
typedef struct TargetMetadata Metadata;
class MetadataRequest {
};
struct MetadataResponse {
  const Metadata *Value;
  MetadataState State;
};
struct BoxPair {
  HeapObject *object;
  OpaqueValue *buffer;
};

typedef struct ForeignTypeMetadata{} ForeignTypeMetadata;

void * _Nonnull swift_errorRetain(void *_Nonnull swiftError) noexcept;
void swift_errorRelease(void *_Nonnull swiftError) noexcept;
const void *_Nullable swift_getTypeByMangledNameInContext(
    const char *_Nullable typeNameStart, size_t typeNameLength,
    const void *_Nullable context,
    const void *_Nullable const *_Nullable genericArgs);
bool swift_dynamicCast(void *_Nullable dest, void *_Nullable src,
                                  const void *_Nullable srcType,
                                  const void *_Nullable targetType,
                                  uint32_t flags);
const void *_Nullable getErrorMetadata();

MetadataResponse
swift_getForeignTypeMetadata(MetadataRequest request,
                             ForeignTypeMetadata *nonUnique);
const Metadata *swift_getObjectType(HeapObject *object);
HeapObject *swift_initStaticObject(HeapMetadata const *metadata,
                                   HeapObject *object);
HeapObject *swift_initStackObject(HeapMetadata const *metadata,
                                  HeapObject *object);
HeapObject *swift_allocObject(HeapMetadata const *metadata,
                              size_t requiredSize,
                              size_t requiredAlignmentMask);
void swift_verifyEndOfLifetime(HeapObject *object);
BoxPair swift_allocBox(Metadata const *type);
BoxPair swift_makeBoxUnique(OpaqueValue *buffer, Metadata const *type,
                                    size_t alignMask);
HeapObject* swift_allocEmptyBox();
HeapObject *swift_retain(HeapObject *object);
HeapObject *swift_retain_n(HeapObject *object, uint32_t n);
HeapObject *swift_nonatomic_retain(HeapObject *object);
HeapObject* swift_nonatomic_retain_n(HeapObject *object, uint32_t n);
HeapObject *swift_tryRetain(HeapObject *object);
bool swift_isDeallocating(HeapObject *object);
void swift_release(HeapObject *object);
void swift_nonatomic_release(HeapObject *object);
void swift_release_n(HeapObject *object, uint32_t n);
void swift_setDeallocating(HeapObject *object);
void swift_nonatomic_release_n(HeapObject *object, uint32_t n);
size_t swift_retainCount(HeapObject *object);
size_t swift_unownedRetainCount(HeapObject *object);
size_t swift_weakRetainCount(HeapObject *object);
bool swift_isUniquelyReferenced(const void *);
bool swift_isUniquelyReferenced_nonNull(const void *);
bool swift_isUniquelyReferenced_nonNull_bridgeObject(uintptr_t bits);
bool swift_isUniquelyReferencedNonObjC(const void *);
bool swift_isUniquelyReferencedNonObjC_nonNull(const void *);
bool swift_isUniquelyReferencedNonObjC_nonNull_bridgeObject(
  uintptr_t bits);
bool swift_isUniquelyReferenced_native(const struct HeapObject *);
bool swift_isUniquelyReferenced_nonNull_native(const struct HeapObject *);
bool swift_isEscapingClosureAtFileLocation(const struct HeapObject *object,
                                           const unsigned char *filename,
                                           int32_t filenameLength,
                                           int32_t line,
                                           int32_t column,
                                           unsigned type);
void swift_deallocObject(HeapObject *object, size_t allocatedSize,
                         size_t allocatedAlignMask);
void swift_deallocUninitializedObject(HeapObject *object, size_t allocatedSize,
                                      size_t allocatedAlignMask);
void swift_deallocClassInstance(HeapObject *object,
                                 size_t allocatedSize,
                                 size_t allocatedAlignMask);
void swift_once(swift_once_t *predicate, void (*fn)(void *), void *context);
OpaqueValue *swift_projectBox(HeapObject *object);
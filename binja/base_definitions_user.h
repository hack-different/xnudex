#include <unistd.h>
#include <sys/types.h>
typedef struct va_list_t {
   unsigned int gp_offset;
   unsigned int fp_offset;
   void *overflow_arg_area;
   void *reg_save_area;
} va_list[1];


typedef void (*sig_t) (int);
sig_t signal(int sig, sig_t func);
char * strerror(int errnum);


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


typedef struct CFString *CFStringRef;
typedef struct __CFError *CFErrorRef;
typedef struct __CFData *CFDataRef;
typedef struct __CFLocale *CFLocaleRef;
typedef struct __CFURL *CFURLRef;
typedef struct __CFArray *CFArrayRef;
typedef struct __CFDictionary *CFMutableDictionaryRef;
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

void NSLog(CFStringRef format, ...);

// IOKit

typedef struct ipc_port *ipc_port_t;
typedef ipc_port_t mach_port_t;
typedef struct task *task_t;
typedef int kern_return_t;
typedef task_t task_port_t;
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

// Security

typedef struct __SecKeychainItem SecKeychainItemRef;
typedef struct __SecKey SecKeyRef;
typedef struct __SecAccessControl SecAccessControlRef;
typedef struct __SecPolicy SecPolicyRef;
typedef struct __SecTrust SecTrustRef;
typedef const struct __SecRandom *SecRandomRef;
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

// System Configuration

typedef struct __SCPreferences SCPreferencesRef;
typedef struct __SCDynamicStore SCDynamicStoreRef;
typedef const struct AuthorizationOpaqueRef *AuthorizationRef;

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

// GrandCentralDispatch

typedef void* dispatch_queue_t;
typedef void* dispatch_data_t;
typedef void (^dispatch_block_t)(void);


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

typedef void (^xpc_activity_handler_t)(xpc_activity_t activity);

void xpc_activity_register(const char *identifier, xpc_object_t criteria, xpc_activity_handler_t handler);
void xpc_activity_unregister(const char *identifier);
xpc_activity_state_t xpc_activity_get_state(xpc_activity_t activity);
bool xpc_activity_set_state(xpc_activity_t activity, xpc_activity_state_t state);
bool xpc_activity_should_defer(xpc_activity_t activity);

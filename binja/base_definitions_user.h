#include <unistd.h>
#include <sys/types.h>

typedef struct ipc_port *ipc_port_t;
typedef ipc_port_t mach_port_t;

typedef struct va_list_t {
   unsigned int gp_offset;
   unsigned int fp_offset;
   void *overflow_arg_area;
   void *reg_save_area;
} va_list[1];

#include "posix.h"

#include "asl.h"

// Blocks

extern void *__single _Block_copy(const void *__single aBlock);
extern void _Block_release(const void *__single aBlock);
extern void _Block_object_assign(void *, const void *, const int);
extern void _Block_object_dispose(const void *, const int);
extern void * _NSConcreteGlobalBlock[32];
extern void * _NSConcreteStackBlock[32];

#include "core_foundation.h"
#include "objc.h"

#include "grand_central_dispatch.h"

#include "mach.h"

#include "iokit.h"


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




// Mobile Gestalt

#import "mobile_gestalt.h"

// System Configuration

#include "system_configuration.h"


// Network

#include "dnssd.h"

#include "xpc.h"

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
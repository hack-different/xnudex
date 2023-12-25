
// Core Foundation
#define CF_EXPORT extern


// Forward Declaring these for Toll-Free Bridge Reasons
typedef struct objc_class_t* Class;
typedef struct objc_object_t* id;

typedef char* StringPtr;
typedef const char* ConstStringPtr;

typedef bool Boolean;
typedef uint32_t UInt32;
typedef int32_t SInt32;
typedef uint16_t UInt16;
typedef uint8_t UInt8;
typedef int16_t SInt16;
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
typedef void* CFTypeRef;
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
typedef struct __CFData *CFMutableDataRef;
typedef struct __CFSet CFSetRef;
typedef struct __CFSet *CFMutableSetRef;
typedef struct __CFLocale *CFLocaleRef;
typedef struct __CFURL *CFURLRef;
typedef struct __CFDate CFDateRef;
typedef struct __CFArray *CFArrayRef;
typedef struct __CFArray *CFMutableArrayRef;
typedef struct __CFDictionary CFDictionaryRef;
typedef struct __CFDictionary *CFMutableDictionaryRef;
typedef struct __CFUserNotification CFUserNotificationRef;
typedef struct __CFRunLoopSource CFRunLoopSourceRef;
typedef struct __CFNumber CFNumberRef;
typedef CFTypeRef CFPropertyListRef;
typedef struct __CFReadStream CFReadStreamRef;
typedef struct __CFWriteStream CFWriteStreamRef;
typedef struct __CFRunLoop CFRunLoopRef;
typedef double CFTimeInterval;
typedef CFTimeInterval CFAbsoluteTime;
typedef struct CFString *CFMutableStringRef;
typedef struct __CFAllocator CFAllocatorRef;

typedef struct CFRange {
    CFIndex length;
    CFIndex location;
} CFRange;

typedef enum CFComparisonResult : CFIndex {
    kCFCompareLessThan = -1L,
    kCFCompareEqualTo = 0,
    kCFCompareGreaterThan = 1
} CFComparisonResult;

typedef CFStringRef (*CFArrayCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFArrayEqualCallBack)(const void *value1, const void *value2);
typedef void (*CFArrayReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef const void *(*CFArrayRetainCallBack)(CFAllocatorRef allocator, const void *value);

typedef struct CFArrayCallBacks {
    CFArrayCopyDescriptionCallBack copyDescription;
    CFArrayEqualCallBack equal;
    CFArrayReleaseCallBack release;
    CFArrayRetainCallBack retain;
    CFIndex version;
} CFArrayCallBacks;
typedef CFComparisonResult (*CFComparatorFunction)(const void *val1, const void *val2, void *context);



typedef enum CFURLBookmarkResolutionOptions : CFOptionFlags {
} CFURLBookmarkResolutionOptions;

typedef enum CFURLPathStyle : CFIndex {
} CFURLPathStyle;

typedef enum CFDataSearchFlags : CFOptionFlags {
    kCFDataSearchBackwards = 1UL << 0,
    kCFDataSearchAnchored = 1UL << 1
} CFDataSearchFlags;

// Core Foundation : Core
void CFRelease(CFTypeRef cf);
CFTypeRef CFRetain(CFTypeRef cf);
Boolean CFEqual(CFTypeRef cf1, CFTypeRef cf2);
CFHashCode CFHash(CFTypeRef cf);
CFTypeID CFGetTypeID(CFTypeRef cf);
CFStringRef CFCopyDescription(CFTypeRef cf);
CFStringRef CFCopyTypeIDDescription(CFTypeID type_id);
void CFShow(CFTypeRef obj);

// Core Foundation : CFAllocator

extern const CFAllocatorRef kCFAllocatorNull;
extern const CFAllocatorRef kCFAllocatorDefault;
extern const CFAllocatorRef kCFAllocatorSystemDefault;
extern const CFAllocatorRef kCFAllocatorMalloc;
extern const CFAllocatorRef kCFAllocatorMallocZone;
extern const CFAllocatorRef kCFAllocatorUseContext;
typedef void *(*CFAllocatorAllocateCallBack)(CFIndex allocSize, CFOptionFlags hint, void *info);
typedef CFStringRef (*CFAllocatorCopyDescriptionCallBack)(const void *info);
typedef void (*CFAllocatorDeallocateCallBack)(void *ptr, void *info);
typedef CFIndex (*CFAllocatorPreferredSizeCallBack)(CFIndex size, CFOptionFlags hint, void *info);
typedef void *(*CFAllocatorReallocateCallBack)(void *ptr, CFIndex newsize, CFOptionFlags hint, void *info);
typedef void (*CFAllocatorReleaseCallBack)(const void *info);
typedef const void *(*CFAllocatorRetainCallBack)(const void *info);
typedef struct CFAllocatorContext {
    CFAllocatorAllocateCallBack allocate;
    CFAllocatorCopyDescriptionCallBack copyDescription;
    CFAllocatorDeallocateCallBack deallocate;
    void *info;
    CFAllocatorPreferredSizeCallBack preferredSize;
    CFAllocatorReallocateCallBack reallocate;
    CFAllocatorReleaseCallBack release;
    CFAllocatorRetainCallBack retain;
    CFIndex version;
} CFAllocatorContext;


CFAllocatorRef CFAllocatorCreate(CFAllocatorRef allocator, CFAllocatorContext *context);
void * CFAllocatorAllocate(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);
void CFAllocatorDeallocate(CFAllocatorRef allocator, void *ptr);
CFIndex CFAllocatorGetPreferredSizeForSize(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);
void * CFAllocatorReallocate(CFAllocatorRef allocator, void *ptr, CFIndex newsize, CFOptionFlags hint);
CFAllocatorRef CFAllocatorGetDefault(void);
void CFAllocatorSetDefault(CFAllocatorRef allocator);
void CFAllocatorGetContext(CFAllocatorRef allocator, CFAllocatorContext *context);
CFTypeID CFAllocatorGetTypeID(void);


// Core Foundation : CFRuntime

enum
{
  _kCFRuntimeNotATypeID = 0
};

enum
{
  _kCFRuntimeScannedObject =     (1UL<<0),
  _kCFRuntimeResourcefulObject = (1UL<<2),
  _kCFRuntimeCustomRefCount =    (1UL<<3)
};
typedef struct __CFRuntimeClass CFRuntimeClass;
struct __CFRuntimeClass
{
  CFIndex version;
  const char *className;
  void (*init)(CFTypeRef cf);
  CFTypeRef (*copy)(CFAllocatorRef allocator, CFTypeRef cf);
  void (*finalize)(CFTypeRef cf);
  Boolean (*equal)(CFTypeRef cf1, CFTypeRef cf2);
  CFHashCode (*hash)(CFTypeRef cf);
  CFStringRef (*copyFormattingDesc)(CFTypeRef cf, CFDictionaryRef formatOptions);
  CFStringRef (*copyDebugDesc)(CFTypeRef cf);
  void (*reclaim)(CFTypeRef cf); /* _kCFRuntimeResourcefulObject */
  UInt32 (*refcount)(intptr_t op, CFTypeRef cf); /* _kCFRuntimeCustomRefCount */
};
typedef struct __CFRuntimeBase CFRuntimeBase;
struct __CFRuntimeBase
{
  void *_isa;
  SInt16 _typeID;
  struct
    {
      SInt16 ro:       1;
      SInt16 reserved: 7;
      SInt16 info:     8;
    } _flags;
};
CFTypeID _CFRuntimeRegisterClass (const CFRuntimeClass * const cls);
const CFRuntimeClass * _CFRuntimeGetClassWithTypeID (CFTypeID typeID);
void _CFRuntimeUnregisterClassWithTypeID (CFTypeID typeID);
CFTypeRef _CFRuntimeCreateInstance (CFAllocatorRef allocator, CFTypeID typeID, CFIndex extraBytes, unsigned char *category);
void _CFRuntimeSetInstanceTypeID (CFTypeRef cf, CFTypeID typeID);
void _CFRuntimeInitStaticInstance (void *memory, CFTypeID typeID);


// Core Foundation : CFStringRef / NSString
typedef UInt32 CFStringEncoding;
typedef struct __CFCharacterSet CFCharacterSetRef;
typedef unsigned char           Str255[256];
typedef const unsigned char *   ConstStr255Param;
typedef enum CFStringEncodings : CFIndex {
    kCFStringEncodingANSEL = 0x0601,
    kCFStringEncodingBig5 = 0x0A03,
    kCFStringEncodingBig5_E = 0x0A09,
    kCFStringEncodingBig5_HKSCS_1999 = 0x0A06,
    kCFStringEncodingCNS_11643_92_P1 = 0x0651,
    kCFStringEncodingCNS_11643_92_P2 = 0x0652,
    kCFStringEncodingCNS_11643_92_P3 = 0x0653,
    kCFStringEncodingDOSArabic = 0x0419,
    kCFStringEncodingDOSBalticRim = 0x0406,
    kCFStringEncodingDOSCanadianFrench = 0x0418,
    kCFStringEncodingDOSChineseSimplif = 0x0421,
    kCFStringEncodingDOSChineseTrad = 0x0423,
    kCFStringEncodingDOSCyrillic = 0x0413,
    kCFStringEncodingDOSGreek = 0x0405,
    kCFStringEncodingDOSGreek1 = 0x0411,
    kCFStringEncodingDOSGreek2 = 0x041C,
    kCFStringEncodingDOSHebrew = 0x0417,
    kCFStringEncodingDOSIcelandic = 0x0416,
    kCFStringEncodingDOSJapanese = 0x0420,
    kCFStringEncodingDOSKorean = 0x0422,
    kCFStringEncodingDOSLatin1 = 0x0410,
    kCFStringEncodingDOSLatin2 = 0x0412,
    kCFStringEncodingDOSLatinUS = 0x0400,
    kCFStringEncodingDOSNordic = 0x041A,
    kCFStringEncodingDOSPortuguese = 0x0415,
    kCFStringEncodingDOSRussian = 0x041B,
    kCFStringEncodingDOSThai = 0x041D,
    kCFStringEncodingDOSTurkish = 0x0414,
    kCFStringEncodingEBCDIC_CP037 = 0x0C02,
    kCFStringEncodingEBCDIC_US = 0x0C01,
    kCFStringEncodingEUC_CN = 0x0930,
    kCFStringEncodingEUC_JP = 0x0920,
    kCFStringEncodingEUC_KR = 0x0940,
    kCFStringEncodingEUC_TW = 0x0931,
    kCFStringEncodingGBK_95 = 0x0631,
    kCFStringEncodingGB_18030_2000 = 0x0632,
    kCFStringEncodingGB_2312_80 = 0x0630,
    kCFStringEncodingHZ_GB_2312 = 0x0A05,
    kCFStringEncodingISOLatin10 = 0x0210,
    kCFStringEncodingISOLatin2 = 0x0202,
    kCFStringEncodingISOLatin3 = 0x0203,
    kCFStringEncodingISOLatin4 = 0x0204,
    kCFStringEncodingISOLatin5 = 0x0209,
    kCFStringEncodingISOLatin6 = 0x020A,
    kCFStringEncodingISOLatin7 = 0x020D,
    kCFStringEncodingISOLatin8 = 0x020E,
    kCFStringEncodingISOLatin9 = 0x020F,
    kCFStringEncodingISOLatinArabic = 0x0206,
    kCFStringEncodingISOLatinCyrillic = 0x0205,
    kCFStringEncodingISOLatinGreek = 0x0207,
    kCFStringEncodingISOLatinHebrew = 0x0208,
    kCFStringEncodingISOLatinThai = 0x020B,
    kCFStringEncodingISO_2022_CN = 0x0830,
    kCFStringEncodingISO_2022_CN_EXT = 0x0831,
    kCFStringEncodingISO_2022_JP = 0x0820,
    kCFStringEncodingISO_2022_JP_1 = 0x0822,
    kCFStringEncodingISO_2022_JP_2 = 0x0821,
    kCFStringEncodingISO_2022_JP_3 = 0x0823,
    kCFStringEncodingISO_2022_KR = 0x0840,
    kCFStringEncodingJIS_C6226_78 = 0x0624,
    kCFStringEncodingJIS_X0201_76 = 0x0620,
    kCFStringEncodingJIS_X0208_83 = 0x0621,
    kCFStringEncodingJIS_X0208_90 = 0x0622,
    kCFStringEncodingJIS_X0212_90 = 0x0623,
    kCFStringEncodingKOI8_R = 0x0A02,
    kCFStringEncodingKOI8_U = 0x0A08,
    kCFStringEncodingKSC_5601_87 = 0x0640,
    kCFStringEncodingKSC_5601_92_Johab = 0x0641,
    kCFStringEncodingMacArabic = 4,
    kCFStringEncodingMacArmenian = 24,
    kCFStringEncodingMacBengali = 13,
    kCFStringEncodingMacBurmese = 19,
    kCFStringEncodingMacCeltic = 39,
    kCFStringEncodingMacCentralEurRoman = 29,
    kCFStringEncodingMacChineseSimp = 25,
    kCFStringEncodingMacChineseTrad = 2,
    kCFStringEncodingMacCroatian = 36,
    kCFStringEncodingMacCyrillic = 7,
    kCFStringEncodingMacDevanagari = 9,
    kCFStringEncodingMacDingbats = 34,
    kCFStringEncodingMacEthiopic = 28,
    kCFStringEncodingMacExtArabic = 31,
    kCFStringEncodingMacFarsi = 0x8C,
    kCFStringEncodingMacGaelic = 40,
    kCFStringEncodingMacGeorgian = 23,
    kCFStringEncodingMacGreek = 6,
    kCFStringEncodingMacGujarati = 11,
    kCFStringEncodingMacGurmukhi = 10,
    kCFStringEncodingMacHFS = 0xFF,
    kCFStringEncodingMacHebrew = 5,
    kCFStringEncodingMacIcelandic = 37,
    kCFStringEncodingMacInuit = 0xEC,
    kCFStringEncodingMacJapanese = 1,
    kCFStringEncodingMacKannada = 16,
    kCFStringEncodingMacKhmer = 20,
    kCFStringEncodingMacKorean = 3,
    kCFStringEncodingMacLaotian = 22,
    kCFStringEncodingMacMalayalam = 17,
    kCFStringEncodingMacMongolian = 27,
    kCFStringEncodingMacOriya = 12,
    kCFStringEncodingMacRomanLatin1 = 0x0A04,
    kCFStringEncodingMacRomanian = 38,
    kCFStringEncodingMacSinhalese = 18,
    kCFStringEncodingMacSymbol = 33,
    kCFStringEncodingMacTamil = 14,
    kCFStringEncodingMacTelugu = 15,
    kCFStringEncodingMacThai = 21,
    kCFStringEncodingMacTibetan = 26,
    kCFStringEncodingMacTurkish = 35,
    kCFStringEncodingMacUkrainian = 0x98,
    kCFStringEncodingMacVT100 = 0xFC,
    kCFStringEncodingMacVietnamese = 30,
    kCFStringEncodingNextStepJapanese = 0x0B02,
    kCFStringEncodingShiftJIS = 0x0A01,
    kCFStringEncodingShiftJIS_X0213 = 0x0628,
    kCFStringEncodingShiftJIS_X0213_MenKuTen = 0x0629,
    kCFStringEncodingUTF7 = 0x04000100,
    kCFStringEncodingUTF7_IMAP = 0x0A10,
    kCFStringEncodingVISCII = 0x0A07,
    kCFStringEncodingWindowsArabic = 0x0506,
    kCFStringEncodingWindowsBalticRim = 0x0507,
    kCFStringEncodingWindowsCyrillic = 0x0502,
    kCFStringEncodingWindowsGreek = 0x0503,
    kCFStringEncodingWindowsHebrew = 0x0505,
    kCFStringEncodingWindowsKoreanJohab = 0x0510,
    kCFStringEncodingWindowsLatin2 = 0x0501,
    kCFStringEncodingWindowsLatin5 = 0x0504,
    kCFStringEncodingWindowsVietnamese = 0x0508,
    kCFStringEncodingShiftJIS_X0213_00 = 0x0628
} CFStringEncodings;
typedef enum {
   kCFCharacterSetControl = 1,
   kCFCharacterSetWhitespace,
   kCFCharacterSetWhitespaceAndNewline,
   kCFCharacterSetDecimalDigit,
   kCFCharacterSetLetter,
   kCFCharacterSetLowercaseLetter,
   kCFCharacterSetUppercaseLetter,
   kCFCharacterSetNonBase,
   kCFCharacterSetDecomposable,
   kCFCharacterSetAlphaNumeric,
   kCFCharacterSetPunctuation,
   kCFCharacterSetCapitalizedLetter = 13,
   kCFCharacterSetSymbol = 14,
   kCFCharacterSetNewline = 15,
   kCFCharacterSetIllegal = 12
} CFCharacterSet;
typedef enum CFStringCompareFlags : CFOptionFlags {
    kCFCompareAnchored = 8,
    kCFCompareBackwards = 4,
    kCFCompareCaseInsensitive = 1,
    kCFCompareDiacriticInsensitive = 128,
    kCFCompareForcedOrdering = 512,
    kCFCompareLocalized = 32,
    kCFCompareNonliteral = 16,
    kCFCompareNumerically = 64,
    kCFCompareWidthInsensitive = 256
} CFStringCompareFlags;
typedef struct CFStringInlineBuffer {
    UniChar buffer[64];
    CFIndex bufferedRangeEnd;
    CFIndex bufferedRangeStart;
    const char *directCStringBuffer;
    const UniChar *directUniCharBuffer;
    CFRange rangeToBuffer;
    CFStringRef theString;
} CFStringInlineBuffer;
typedef enum CFStringNormalizationForm : CFIndex {
    kCFStringNormalizationFormD = 0,
    kCFStringNormalizationFormKD,
    kCFStringNormalizationFormC,
    kCFStringNormalizationFormKC
} CFStringNormalizationForm;
extern const CFStringRef kCFStringTransformStripCombiningMarks;
extern const CFStringRef kCFStringTransformToLatin;
extern const CFStringRef kCFStringTransformFullwidthHalfwidth;
extern const CFStringRef kCFStringTransformLatinKatakana;
extern const CFStringRef kCFStringTransformLatinHiragana;
extern const CFStringRef kCFStringTransformHiraganaKatakana;
extern const CFStringRef kCFStringTransformMandarinLatin;
extern const CFStringRef kCFStringTransformLatinHangul;
extern const CFStringRef kCFStringTransformLatinArabic;
extern const CFStringRef kCFStringTransformLatinHebrew;
extern const CFStringRef kCFStringTransformLatinThai;
extern const CFStringRef kCFStringTransformLatinCyrillic;
extern const CFStringRef kCFStringTransformLatinGreek;
extern const CFStringRef kCFStringTransformToXMLHex;
extern const CFStringRef kCFStringTransformToUnicodeName;
extern const CFStringRef kCFStringTransformStripDiacritics;
CFArrayRef CFStringCreateArrayBySeparatingStrings(CFAllocatorRef alloc, CFStringRef theString, CFStringRef separatorString);
CFStringRef CFStringCreateByCombiningStrings(CFAllocatorRef alloc, CFArrayRef theArray, CFStringRef separatorString);
CFStringRef CFStringCreateCopy(CFAllocatorRef alloc, CFStringRef theString);
CFStringRef CFStringCreateFromExternalRepresentation(CFAllocatorRef alloc, CFDataRef data, CFStringEncoding encoding);
CFStringRef CFStringCreateWithBytes(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex numBytes, CFStringEncoding encoding, Boolean isExternalRepresentation);
CFStringRef CFStringCreateWithBytesNoCopy(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex numBytes, CFStringEncoding encoding, Boolean isExternalRepresentation, CFAllocatorRef contentsDeallocator);
CFStringRef CFStringCreateWithCharacters(CFAllocatorRef alloc, const UniChar *chars, CFIndex numChars);
CFStringRef CFStringCreateWithCharactersNoCopy(CFAllocatorRef alloc, const UniChar *chars, CFIndex numChars, CFAllocatorRef contentsDeallocator);
CFStringRef CFStringCreateWithCString(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding);
CFStringRef CFStringCreateWithCStringNoCopy(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding, CFAllocatorRef contentsDeallocator);
CFStringRef CFStringCreateWithFormat(CFAllocatorRef alloc, CFDictionaryRef formatOptions, CFStringRef format, ...);
CFStringRef CFStringCreateWithFormatAndArguments(CFAllocatorRef alloc, CFDictionaryRef formatOptions, CFStringRef format, va_list arguments);
CFStringRef CFStringCreateWithPascalString(CFAllocatorRef alloc, ConstStr255Param pStr, CFStringEncoding encoding);
CFStringRef CFStringCreateWithPascalStringNoCopy(CFAllocatorRef alloc, ConstStr255Param pStr, CFStringEncoding encoding, CFAllocatorRef contentsDeallocator);
CFStringRef CFStringCreateWithSubstring(CFAllocatorRef alloc, CFStringRef str, CFRange range);
CFArrayRef CFStringCreateArrayWithFindResults(CFAllocatorRef alloc, CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags compareOptions);
CFRange CFStringFind(CFStringRef theString, CFStringRef stringToFind, CFStringCompareFlags compareOptions);
Boolean CFStringFindCharacterFromSet(CFStringRef theString, CFCharacterSetRef theSet, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFRange *result);
Boolean CFStringFindWithOptions(CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFRange *result);
Boolean CFStringFindWithOptionsAndLocale(CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFLocaleRef locale, CFRange *result);
void CFStringGetLineBounds(CFStringRef theString, CFRange range, CFIndex *lineBeginIndex, CFIndex *lineEndIndex, CFIndex *contentsEndIndex);
CFComparisonResult CFStringCompare(CFStringRef theString1, CFStringRef theString2, CFStringCompareFlags compareOptions);
CFComparisonResult CFStringCompareWithOptions(CFStringRef theString1, CFStringRef theString2, CFRange rangeToCompare, CFStringCompareFlags compareOptions);
CFComparisonResult CFStringCompareWithOptionsAndLocale(CFStringRef theString1, CFStringRef theString2, CFRange rangeToCompare, CFStringCompareFlags compareOptions, CFLocaleRef locale);
Boolean CFStringHasPrefix(CFStringRef theString, CFStringRef prefix);
Boolean CFStringHasSuffix(CFStringRef theString, CFStringRef suffix);
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
void CFShowStr(CFStringRef str);
CFTypeID CFStringGetTypeID(void);
CFStringRef CFStringCreateWithFileSystemRepresentation(CFAllocatorRef alloc, const char *buffer);
Boolean CFStringGetFileSystemRepresentation(CFStringRef string, char *buffer, CFIndex maxBufLen);
CFIndex CFStringGetMaximumSizeOfFileSystemRepresentation(CFStringRef string);
void CFStringGetParagraphBounds(CFStringRef string, CFRange range, CFIndex *parBeginIndex, CFIndex *parEndIndex, CFIndex *contentsEndIndex);
UTF32Char CFStringGetLongCharacterForSurrogatePair(UniChar surrogateHigh, UniChar surrogateLow);
Boolean CFStringGetSurrogatePairForLongCharacter(UTF32Char character, UniChar *surrogates);
Boolean CFStringIsSurrogateHighCharacter(UniChar character);
Boolean CFStringIsSurrogateLowCharacter(UniChar character);

void CFStringAppend(CFMutableStringRef theString, CFStringRef appendedString);
void CFStringAppendCharacters(CFMutableStringRef theString, const UniChar *chars, CFIndex numChars);
void CFStringAppendCString(CFMutableStringRef theString, const char *cStr, CFStringEncoding encoding);
void CFStringAppendFormat(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, ...);
void CFStringAppendFormatAndArguments(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, va_list arguments);
void CFStringAppendPascalString(CFMutableStringRef theString, ConstStr255Param pStr, CFStringEncoding encoding);
void CFStringCapitalize(CFMutableStringRef theString, CFLocaleRef locale);
CFMutableStringRef CFStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength);
CFMutableStringRef CFStringCreateMutableCopy(CFAllocatorRef alloc, CFIndex maxLength, CFStringRef theString);
CFMutableStringRef CFStringCreateMutableWithExternalCharactersNoCopy(CFAllocatorRef alloc, UniChar *chars, CFIndex numChars, CFIndex capacity, CFAllocatorRef externalCharactersAllocator);
void CFStringDelete(CFMutableStringRef theString, CFRange range);
CFIndex CFStringFindAndReplace(CFMutableStringRef theString, CFStringRef stringToFind, CFStringRef replacementString, CFRange rangeToSearch, CFStringCompareFlags compareOptions);
void CFStringFold(CFMutableStringRef theString, CFStringCompareFlags theFlags, CFLocaleRef theLocale);
void CFStringInsert(CFMutableStringRef str, CFIndex idx, CFStringRef insertedStr);
void CFStringLowercase(CFMutableStringRef theString, CFLocaleRef locale);
void CFStringNormalize(CFMutableStringRef theString, CFStringNormalizationForm theForm);
void CFStringPad(CFMutableStringRef theString, CFStringRef padString, CFIndex length, CFIndex indexIntoPad);
void CFStringReplace(CFMutableStringRef theString, CFRange range, CFStringRef replacement);
void CFStringReplaceAll(CFMutableStringRef theString, CFStringRef replacement);
void CFStringSetExternalCharactersNoCopy(CFMutableStringRef theString, UniChar *chars, CFIndex length, CFIndex capacity);
Boolean CFStringTransform(CFMutableStringRef string, CFRange *range, CFStringRef transform, Boolean reverse);
void CFStringTrim(CFMutableStringRef theString, CFStringRef trimString);
void CFStringTrimWhitespace(CFMutableStringRef theString);
void CFStringUppercase(CFMutableStringRef theString, CFLocaleRef locale);


// Core Foundation : CFArrayRef / NSArray
void CFArrayAppendValue(CFMutableArrayRef theArray, const void *value);
CFMutableArrayRef CFArrayCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFArrayCallBacks *callBacks);
CFMutableArrayRef CFArrayCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFArrayRef theArray);
void CFArrayExchangeValuesAtIndices(CFMutableArrayRef theArray, CFIndex idx1, CFIndex idx2);
void CFArrayInsertValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);
void CFArrayRemoveAllValues(CFMutableArrayRef theArray);
void CFArrayRemoveValueAtIndex(CFMutableArrayRef theArray, CFIndex idx);
void CFArrayReplaceValues(CFMutableArrayRef theArray, CFRange range, const void **newValues, CFIndex newCount);
void CFArraySetValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);
void CFArraySortValues(CFMutableArrayRef theArray, CFRange range, CFComparatorFunction comparator, void *context);
CFIndex CFArrayGetCount(CFArrayRef theArray);
CFIndex CFArrayBSearchValues(CFArrayRef theArray, CFRange range, const void *value, CFComparatorFunction comparator, void *context);
Boolean CFArrayContainsValue(CFArrayRef theArray, CFRange range, const void *value);
CFIndex CFArrayGetCountOfValue(CFArrayRef theArray, CFRange range, const void *value);
CFIndex CFArrayGetFirstIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);
CFIndex CFArrayGetLastIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);
void CFArrayGetValues(CFArrayRef theArray, CFRange range, const void **values);
const void * CFArrayGetValueAtIndex(CFArrayRef theArray, CFIndex idx);

// Core Foundation : CFDataRef / NSData
CFDataRef CFDataCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length);
CFDataRef CFDataCreateCopy(CFAllocatorRef allocator, CFDataRef theData);
CFDataRef CFDataCreateWithBytesNoCopy(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length, CFAllocatorRef bytesDeallocator);
const UInt8 * CFDataGetBytePtr(CFDataRef theData);
void CFDataGetBytes(CFDataRef theData, CFRange range, UInt8 *buffer);
CFIndex CFDataGetLength(CFDataRef theData);
CFRange CFDataFind(CFDataRef theData, CFDataRef dataToFind, CFRange searchRange, CFDataSearchFlags compareOptions);
CFTypeID CFDataGetTypeID(void);

CFMutableDataRef CFDataCreateMutable(CFAllocatorRef allocator, CFIndex capacity);
CFMutableDataRef CFDataCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDataRef theData);
UInt8 * CFDataGetMutableBytePtr(CFMutableDataRef theData);
void CFDataAppendBytes(CFMutableDataRef theData, const UInt8 *bytes, CFIndex length);
void CFDataDeleteBytes(CFMutableDataRef theData, CFRange range);
void CFDataReplaceBytes(CFMutableDataRef theData, CFRange range, const UInt8 *newBytes, CFIndex newLength);
void CFDataIncreaseLength(CFMutableDataRef theData, CFIndex extraLength);
void CFDataSetLength(CFMutableDataRef theData, CFIndex length);

// Core Foundation : CFDictionaryRef / NSDictionary
typedef void (*CFDictionaryApplierFunction)(const void *key, const void *value, void *context);
typedef CFStringRef (*CFDictionaryCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFDictionaryEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode (*CFDictionaryHashCallBack)(const void *value);
typedef void (*CFDictionaryReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef const void *(*CFDictionaryRetainCallBack)(CFAllocatorRef allocator, const void *value);

typedef struct CFDictionaryKeyCallBacks {
    CFDictionaryCopyDescriptionCallBack copyDescription;
    CFDictionaryEqualCallBack equal;
    CFDictionaryHashCallBack hash;
    CFDictionaryReleaseCallBack release;
    CFDictionaryRetainCallBack retain;
    CFIndex version;
} CFDictionaryKeyCallBacks;
typedef struct CFDictionaryValueCallBacks {
    CFDictionaryCopyDescriptionCallBack copyDescription;
    CFDictionaryEqualCallBack equal;
    CFDictionaryReleaseCallBack release;
    CFDictionaryRetainCallBack retain;
    CFIndex version;
} CFDictionaryValueCallBacks;

CFDictionaryRef CFDictionaryCreate(CFAllocatorRef allocator, const void **keys, const void **values, CFIndex numValues, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
CFDictionaryRef CFDictionaryCreateCopy(CFAllocatorRef allocator, CFDictionaryRef theDict);
Boolean CFDictionaryContainsKey(CFDictionaryRef theDict, const void *key);
Boolean CFDictionaryContainsValue(CFDictionaryRef theDict, const void *value);
CFIndex CFDictionaryGetCount(CFDictionaryRef theDict);
CFIndex CFDictionaryGetCountOfKey(CFDictionaryRef theDict, const void *key);
CFIndex CFDictionaryGetCountOfValue(CFDictionaryRef theDict, const void *value);
void CFDictionaryGetKeysAndValues(CFDictionaryRef theDict, const void **keys, const void **values);
const void * CFDictionaryGetValue(CFDictionaryRef theDict, const void *key);
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef theDict, const void *key, const void **value);
void CFDictionaryApplyFunction(CFDictionaryRef theDict, CFDictionaryApplierFunction applier, void *context);
CFTypeID CFDictionaryGetTypeID(void);
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
CFMutableDictionaryRef CFDictionaryCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDictionaryRef theDict);
void CFDictionaryAddValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef theDict);
void CFDictionaryRemoveValue(CFMutableDictionaryRef theDict, const void *key);
void CFDictionaryReplaceValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
void CFDictionarySetValue(CFMutableDictionaryRef theDict, const void *key, const void *value);

// Core Foundation : CFNumberRef / NSNumber
typedef enum CFNumberType : CFIndex {
    kCFNumberSInt8Type = 1,
    kCFNumberSInt16Type = 2,
    kCFNumberSInt32Type = 3,
    kCFNumberSInt64Type = 4,
    kCFNumberFloat32Type = 5,
    kCFNumberFloat64Type = 6,
    kCFNumberCharType = 7,
    kCFNumberShortType = 8,
    kCFNumberIntType = 9,
    kCFNumberLongType = 10,
    kCFNumberLongLongType = 11,
    kCFNumberFloatType = 12,
    kCFNumberDoubleType = 13,
    kCFNumberCFIndexType = 14,
    kCFNumberNSIntegerType = 15,
    kCFNumberCGFloatType = 16,
    kCFNumberMaxType = 16
} CFNumberType;
CFNumberRef CFNumberCreate(CFAllocatorRef allocator, CFNumberType theType, const void *valuePtr);
CFIndex CFNumberGetByteSize(CFNumberRef number);
CFNumberType CFNumberGetType(CFNumberRef number);
Boolean CFNumberGetValue(CFNumberRef number, CFNumberType theType, void *valuePtr);
Boolean CFNumberIsFloatType(CFNumberRef number);
CFComparisonResult CFNumberCompare(CFNumberRef number, CFNumberRef otherNumber, void *context);
CFTypeID CFNumberGetTypeID(void);


// Core Foundation : CFURLRef / NSURL
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

// Core Foundation : CFRunLoop
typedef void (*CFRunLoopCancelCallBack) (void *info, CFRunLoopRef rl,
                                         CFStringRef mode);
typedef Boolean (*CFRunLoopEqualCallBack) (const void *info1,
                                           const void *info2);
typedef CFHashCode (*CFRunLoopHashCallBack) (const void *info);

typedef mach_port_t (*CFRunLoopGetPortCallBack) (void *info);
typedef void *(*CFRunLoopMachPerformCallBack) (void *msg, CFIndex size,
                                               CFAllocatorRef alloc,
                                               void *info);

typedef void (*CFRunLoopPerformCallBack) (void *info);
typedef void (*CFRunLoopScheduleCallBack) (void *info, CFRunLoopRef rl,
                                           CFStringRef mode);

CF_EXPORT const CFStringRef kCFRunLoopCommonModes;
CF_EXPORT const CFStringRef kCFRunLoopDefaultMode;
typedef enum
{
  kCFRunLoopEntry = (1 << 0),
  kCFRunLoopBeforeTimers = (1 << 1),
  kCFRunLoopBeforeSources = (1 << 2),
  kCFRunLoopBeforeWaiting = (1 << 5),
  kCFRunLoopAfterWaiting = (1 << 6),
  kCFRunLoopExit = (1 << 7),
  kCFRunLoopAllActivities = 0x0FFFFFFFU
} CFRunLoopActivity;

typedef CFStringRef CFRunLoopMode;
typedef struct __CFRunLoopObserver CFRunLoopObserverRef;
typedef struct __CFRunLoopTimer CFRunLoopTimerRef;
typedef enum CFRunLoopRunResult : SInt32 {
    kCFRunLoopRunFinished = 1,
    kCFRunLoopRunStopped = 2,
    kCFRunLoopRunTimedOut = 3,
    kCFRunLoopRunHandledSource = 4
} CFRunLoopRunResult;
typedef struct CFRunLoopSourceContext CFRunLoopSourceContext;
struct CFRunLoopSourceContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFRunLoopEqualCallBack equal;
  CFRunLoopHashCallBack hash;
  CFRunLoopScheduleCallBack schedule;
  CFRunLoopCancelCallBack cancel;
  CFRunLoopPerformCallBack perform;
};
typedef struct CFRunLoopSourceContext1 CFRunLoopSourceContext1;
struct CFRunLoopSourceContext1
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFRunLoopEqualCallBack equal;
  CFRunLoopHashCallBack hash;
  CFRunLoopGetPortCallBack getPort;
  CFRunLoopMachPerformCallBack perform;
};
typedef struct CFRunLoopObserverContext CFRunLoopObserverContext;
struct CFRunLoopObserverContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};
typedef struct CFRunLoopTimerContext CFRunLoopTimerContext;
struct CFRunLoopTimerContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};
void CFRunLoopPerformBlock(CFRunLoopRef rl, CFTypeRef mode, void (^block)(void));
CFRunLoopRef CFRunLoopGetCurrent(void);
CFRunLoopRef CFRunLoopGetMain(void);
void CFRunLoopRun(void);
CFRunLoopRunResult CFRunLoopRunInMode(CFRunLoopMode mode, CFTimeInterval seconds, Boolean returnAfterSourceHandled);
void CFRunLoopWakeUp(CFRunLoopRef rl);
void CFRunLoopStop(CFRunLoopRef rl);
Boolean CFRunLoopIsWaiting(CFRunLoopRef rl);
void CFRunLoopAddSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFRunLoopMode mode);
Boolean CFRunLoopContainsSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFRunLoopMode mode);
void CFRunLoopRemoveSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFRunLoopMode mode);
void CFRunLoopAddObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFRunLoopMode mode);
Boolean CFRunLoopContainsObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFRunLoopMode mode);
void CFRunLoopRemoveObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFRunLoopMode mode);
void CFRunLoopAddCommonMode(CFRunLoopRef rl, CFRunLoopMode mode);
CFArrayRef CFRunLoopCopyAllModes(CFRunLoopRef rl);
CFRunLoopMode CFRunLoopCopyCurrentMode(CFRunLoopRef rl);
void CFRunLoopAddTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFRunLoopMode mode);
CFAbsoluteTime CFRunLoopGetNextTimerFireDate(CFRunLoopRef rl, CFRunLoopMode mode);
void CFRunLoopRemoveTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFRunLoopMode mode);
Boolean CFRunLoopContainsTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFRunLoopMode mode);
CFTypeID CFRunLoopGetTypeID(void);

// Core Foundation : CFSet
typedef void (*CFSetApplierFunction)(const void *value, void *context);
typedef CFStringRef (*CFSetCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFSetEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode (*CFSetHashCallBack)(const void *value);
typedef void (*CFSetReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef const void *(*CFSetRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef struct CFSetCallBacks {
    CFSetCopyDescriptionCallBack copyDescription;
    CFSetEqualCallBack equal;
    CFSetHashCallBack hash;
    CFSetReleaseCallBack release;
    CFSetRetainCallBack retain;
    CFIndex version;
} CFSetCallBacks;
CFSetRef CFSetCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFSetCallBacks *callBacks);
CFSetRef CFSetCreateCopy(CFAllocatorRef allocator, CFSetRef theSet);
Boolean CFSetContainsValue(CFSetRef theSet, const void *value);
CFIndex CFSetGetCount(CFSetRef theSet);
CFIndex CFSetGetCountOfValue(CFSetRef theSet, const void *value);
const void * CFSetGetValue(CFSetRef theSet, const void *value);
Boolean CFSetGetValueIfPresent(CFSetRef theSet, const void *candidate, const void **value);
void CFSetGetValues(CFSetRef theSet, const void **values);
void CFSetApplyFunction(CFSetRef theSet, CFSetApplierFunction applier, void *context);
CFTypeID CFSetGetTypeID(void);
void CFSetAddValue(CFMutableSetRef theSet, const void *value);
CFMutableSetRef CFSetCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFSetCallBacks *callBacks);
CFMutableSetRef CFSetCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFSetRef theSet);
void CFSetRemoveAllValues(CFMutableSetRef theSet);
void CFSetRemoveValue(CFMutableSetRef theSet, const void *value);
void CFSetReplaceValue(CFMutableSetRef theSet, const void *value);
void CFSetSetValue(CFMutableSetRef theSet, const void *value);

// Core Foundation : CFStream
typedef enum CFStreamEventType : CFOptionFlags {
    kCFStreamEventNone = 0,
    kCFStreamEventOpenCompleted = 1,
    kCFStreamEventHasBytesAvailable = 2,
    kCFStreamEventCanAcceptBytes = 4,
    kCFStreamEventErrorOccurred = 8,
    kCFStreamEventEndEncountered = 16
} CFStreamEventType;
typedef enum CFStreamStatus : CFIndex {
    kCFStreamStatusNotOpen = 0,
    kCFStreamStatusOpening,
    kCFStreamStatusOpen,
    kCFStreamStatusReading,
    kCFStreamStatusWriting,
    kCFStreamStatusAtEnd,
    kCFStreamStatusClosed,
    kCFStreamStatusError
} CFStreamStatus;
typedef struct CFStreamError {
    CFIndex domain;
    SInt32 error;
} CFStreamError;
typedef void (*CFReadStreamClientCallBack)(CFReadStreamRef stream, CFStreamEventType type, void *clientCallBackInfo);
typedef void (*CFWriteStreamClientCallBack)(CFWriteStreamRef stream, CFStreamEventType type, void *clientCallBackInfo);
typedef struct CFStreamClientContext {
    CFStringRef  _Null_unspecified (*copyDescription)(void *info);
    void *info;
    void (*release)(void *info);
    void * _Null_unspecified (*retain)(void *info);
    CFIndex version;
} CFStreamClientContext;
typedef CFStringRef CFStreamPropertyKey;
CFReadStreamRef CFReadStreamCreateWithBytesNoCopy(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex length, CFAllocatorRef bytesDeallocator);
CFReadStreamRef CFReadStreamCreateWithFile(CFAllocatorRef alloc, CFURLRef fileURL);
void CFReadStreamClose(CFReadStreamRef stream);
Boolean CFReadStreamOpen(CFReadStreamRef stream);
CFIndex CFReadStreamRead(CFReadStreamRef stream, UInt8 *buffer, CFIndex bufferLength);
void CFReadStreamScheduleWithRunLoop(CFReadStreamRef stream, CFRunLoopRef runLoop, CFRunLoopMode runLoopMode);
void CFReadStreamUnscheduleFromRunLoop(CFReadStreamRef stream, CFRunLoopRef runLoop, CFRunLoopMode runLoopMode);
CFTypeRef CFReadStreamCopyProperty(CFReadStreamRef stream, CFStreamPropertyKey propertyName);
const UInt8 * CFReadStreamGetBuffer(CFReadStreamRef stream, CFIndex maxBytesToRead, CFIndex *numBytesRead);
CFErrorRef CFReadStreamCopyError(CFReadStreamRef stream);
CFStreamError CFReadStreamGetError(CFReadStreamRef stream);
CFStreamStatus CFReadStreamGetStatus(CFReadStreamRef stream);
Boolean CFReadStreamHasBytesAvailable(CFReadStreamRef stream);
Boolean CFReadStreamSetClient(CFReadStreamRef stream, CFOptionFlags streamEvents, CFReadStreamClientCallBack clientCB, CFStreamClientContext *clientContext);
Boolean CFReadStreamSetProperty(CFReadStreamRef stream, CFStreamPropertyKey propertyName, CFTypeRef propertyValue);
CFTypeID CFReadStreamGetTypeID(void);

void NSLog(CFStringRef format, ...);

// Core Foundation : CFPropertyList
typedef enum CFPropertyListFormat : CFIndex {
    kCFPropertyListOpenStepFormat = 1,
    kCFPropertyListXMLFormat_v1_0 = 100,
    kCFPropertyListBinaryFormat_v1_0 = 200
} CFPropertyListFormat;
typedef enum CFPropertyListMutabilityOptions : CFOptionFlags {
    kCFPropertyListMutableContainers = 1 << 0,
    kCFPropertyListMutableContainersAndLeaves = 1 << 1,
    kCFPropertyListImmutable = 0
} CFPropertyListMutabilityOptions;
CFPropertyListRef CFPropertyListCreateWithData(CFAllocatorRef allocator, CFDataRef data, CFOptionFlags options, CFPropertyListFormat *format, CFErrorRef *error);
CFPropertyListRef CFPropertyListCreateWithStream(CFAllocatorRef allocator, CFReadStreamRef stream, CFIndex streamLength, CFOptionFlags options, CFPropertyListFormat *format, CFErrorRef *error);
CFPropertyListRef CFPropertyListCreateDeepCopy(CFAllocatorRef allocator, CFPropertyListRef propertyList, CFOptionFlags mutabilityOption);
CFPropertyListRef CFPropertyListCreateFromXMLData(CFAllocatorRef allocator, CFDataRef xmlData, CFOptionFlags mutabilityOption, CFStringRef *errorString);
CFPropertyListRef CFPropertyListCreateFromStream(CFAllocatorRef allocator, CFReadStreamRef stream, CFIndex streamLength, CFOptionFlags mutabilityOption, CFPropertyListFormat *format, CFStringRef *errorString);
CFDataRef CFPropertyListCreateData(CFAllocatorRef allocator, CFPropertyListRef propertyList, CFPropertyListFormat format, CFOptionFlags options, CFErrorRef *error);
CFIndex CFPropertyListWrite(CFPropertyListRef propertyList, CFWriteStreamRef stream, CFPropertyListFormat format, CFOptionFlags options, CFErrorRef *error);
CFDataRef CFPropertyListCreateXMLData(CFAllocatorRef allocator, CFPropertyListRef propertyList);
CFIndex CFPropertyListWriteToStream(CFPropertyListRef propertyList, CFWriteStreamRef stream, CFPropertyListFormat format, CFStringRef *errorString);
Boolean CFPropertyListIsValid(CFPropertyListRef plist, CFPropertyListFormat format);
struct CFWriteStreamImpl
{
    void (*close)(CFWriteStreamRef);
    void (*finalize)(CFWriteStreamRef);
    Boolean (*open)(CFWriteStreamRef);
    CFIndex (*write)(CFWriteStreamRef, const UInt8 *, CFIndex);
    CFTypeRef (*copyProperty)(CFWriteStreamRef, CFStringRef);
    Boolean (*setProperty)(CFWriteStreamRef, CFStringRef, CFTypeRef);
    Boolean (*acceptBytes)(CFWriteStreamRef);
};
struct __CFWriteStream
{
    CFRuntimeBase               parent;
    struct CFWriteStreamImpl    impl;

    Boolean                     open, closed, failed;
    CFErrorRef                  error;

    /* callbacks when used with a runloop */
    CFOptionFlags               streamEvents;
    CFWriteStreamClientCallBack clientCB;
};
struct CFReadStreamImpl
{
    void (*close)(CFReadStreamRef);
    void (*finalize)(CFReadStreamRef);
    Boolean (*open)(CFReadStreamRef);
    CFIndex (*read)(CFReadStreamRef, UInt8 *, CFIndex);
    CFTypeRef (*copyProperty)(CFReadStreamRef, CFStringRef);
    Boolean (*setProperty)(CFReadStreamRef, CFStringRef, CFTypeRef);
    const UInt8* (*getBuffer)(CFReadStreamRef, CFIndex, CFIndex*);
    Boolean (*hasBytes)(CFReadStreamRef);
};

struct __CFReadStream
{
    CFRuntimeBase              parent;
    struct CFReadStreamImpl    impl;

    Boolean                    open, closed, failed;
    CFErrorRef                 error;

    /* callbacks when used with a runloop */
    CFOptionFlags              streamEvents;
    CFReadStreamClientCallBack clientCB;
};

// Core Foundation : CFPreferences

CFPropertyListRef CFPreferencesCopyAppValue(CFStringRef key, CFStringRef applicationID);
CFArrayRef CFPreferencesCopyKeyList(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);
CFDictionaryRef CFPreferencesCopyMultiple(CFArrayRef keysToFetch, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);
CFPropertyListRef CFPreferencesCopyValue(CFStringRef key, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);
Boolean CFPreferencesGetAppBooleanValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat);
CFIndex CFPreferencesGetAppIntegerValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat);
void CFPreferencesSetAppValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID);
void CFPreferencesSetMultiple(CFDictionaryRef keysToSet, CFArrayRef keysToRemove, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);
void CFPreferencesSetValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);
Boolean CFPreferencesAppSynchronize(CFStringRef applicationID);
Boolean CFPreferencesSynchronize(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);
void CFPreferencesAddSuitePreferencesToApp(CFStringRef applicationID, CFStringRef suiteID);
void CFPreferencesRemoveSuitePreferencesFromApp(CFStringRef applicationID, CFStringRef suiteID);
Boolean CFPreferencesAppValueIsForced(CFStringRef key, CFStringRef applicationID);
CFArrayRef CFPreferencesCopyApplicationList(CFStringRef userName, CFStringRef hostName);

// Core Foundation : Other

CFDictionaryRef CFCopySystemVersionDictionary();


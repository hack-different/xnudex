
CFPropertyListRef MGCopyAnswer(CFStringRef property);
Boolean MGGetBoolAnswer(CFStringRef property);
CFPropertyListRef MGCopyMultipleAnswers(CFArrayRef questions, int __unknown0);
CFPropertyListRef MGCopyAnswerWithError(CFStringRef question, int *error, ...);
int MGSetAnswer(CFStringRef question, CFTypeRef answer);

extern const CFStringRef kMGDiskUsage;
extern const CFStringRef kMGModelNumber;

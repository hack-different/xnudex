
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

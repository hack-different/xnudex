
// Objc

struct objc_class_t {
    Class isa;
    Class super;
    void* cache;
    void* vtable;
    void* data;
};

struct objc_object_t {
    Class isa;
};

struct objc_class_ro_t
{
    uint32_t flags;
    uint32_t start;
    uint32_t size;
    uint32_t reserved;
    void* ivar_layout;
    const char* name;
    void* methods;
    void* protocols;
    void* ivars;
    void* weak_ivar_layout;
    void* properties;
};

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

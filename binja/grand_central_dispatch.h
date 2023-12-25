
// GrandCentralDispatch

typedef uint64_t dispatch_time_t;
typedef intptr_t dispatch_once_t;
typedef long dispatch_queue_priority_t;
typedef int dispatch_fd_t;

typedef enum dispatch_autorelease_frequency_t : unsigned long {
    DISPATCH_AUTORELEASE_FREQUENCY_INHERIT,
    DISPATCH_AUTORELEASE_FREQUENCY_WORK_ITEM,
    DISPATCH_AUTORELEASE_FREQUENCY_NEVER
} dispatch_autorelease_frequency_t;

typedef enum dispatch_block_flags_t : unsigned long {
    DISPATCH_BLOCK_ASSIGN_CURRENT,
    DISPATCH_BLOCK_BARRIER,
    DISPATCH_BLOCK_DETACHED,
    DISPATCH_BLOCK_ENFORCE_QOS_CLASS,
    DISPATCH_BLOCK_INHERIT_QOS_CLASS,
    DISPATCH_BLOCK_NO_QOS_CLASS
} dispatch_block_flags_t;

typedef enum : unsigned long {
    DISPATCH_PROC_EXEC,
    DISPATCH_PROC_EXIT,
    DISPATCH_PROC_FORK,
    DISPATCH_PROC_SIGNAL
} dispatch_source_proc_flags_t;

typedef enum : unsigned long {
    DISPATCH_IO_STOP
} dispatch_io_close_flags_t;

typedef enum : unsigned long {
    DISPATCH_IO_STREAM,
    DISPATCH_IO_RANDOM
} dispatch_io_type_t;

typedef enum : unsigned long {
    DISPATCH_IO_STRICT_INTERVAL
} dispatch_io_interval_flags_t;

typedef enum  {
    QOS_CLASS_USER_INTERACTIVE,
    QOS_CLASS_USER_INITIATED,
    QOS_CLASS_DEFAULT,
    QOS_CLASS_UTILITY,
    QOS_CLASS_BACKGROUND,
    QOS_CLASS_UNSPECIFIED,
} qos_class_t;


typedef qos_class_t dispatch_qos_class_t;

typedef struct OS_dispatch_object {
    Class isa;
} *dispatch_object_t;

typedef struct OS_dispatch_queue : OS_dispatch_object {
} *dispatch_queue_t;

typedef struct OS_dispatch_queue_concurrent : OS_dispatch_queue {
} *dispatch_queue_concurrent_t;

typedef struct OS_dispatch_queue_global : OS_dispatch_queue {
} *dispatch_queue_global_t;

typedef struct OS_dispatch_queue_serial : OS_dispatch_queue {
} *dispatch_queue_serial_t;

typedef struct OS_dispatch_queue_serial_executor : OS_dispatch_queue {
} *dispatch_queue_serial_executor_t;

typedef struct OS_dispatch_queue_main : OS_dispatch_queue {
} *dispatch_queue_main_t;

typedef struct OS_dispatch_workloop : OS_dispatch_queue {
} *dispatch_workloop_t;

typedef struct OS_dispatch_data : OS_dispatch_object {} *dispatch_data_t;

typedef struct OS_dispatch_group : OS_dispatch_object {} *dispatch_group_t;

typedef struct OS_dispatch_source : OS_dispatch_object {} *dispatch_source_t;

typedef struct OS_dispatch_io : OS_dispatch_object {} *dispatch_io_t;

typedef struct OS_dispatch_semaphore : OS_dispatch_object {} *dispatch_semaphore_t;

typedef void *dispatch_queue_attr_t;

typedef const struct dispatch_source_type_s *dispatch_source_type_t;

typedef void (^dispatch_block_t)(void);
typedef void (*dispatch_function_t)(void *);
typedef void (^dispatch_io_handler_t)(bool done, dispatch_data_t data, int error);
typedef bool (^dispatch_data_applier_t)(dispatch_data_t region, size_t offset, const void *buffer, size_t size);

dispatch_queue_main_t dispatch_get_main_queue(void);
dispatch_queue_global_t dispatch_get_global_queue(intptr_t identifier, uintptr_t flags);

dispatch_queue_main_t dispatch_get_main_queue(void);
dispatch_queue_global_t dispatch_get_global_queue(intptr_t identifier, uintptr_t flags);
dispatch_queue_t dispatch_queue_create(const char *label, dispatch_queue_attr_t attr);
dispatch_queue_t dispatch_queue_create_with_target(const char *label, dispatch_queue_attr_t attr, dispatch_queue_t target);

dispatch_queue_attr_t dispatch_queue_attr_make_with_qos_class(dispatch_queue_attr_t attr, dispatch_qos_class_t qos_class, int relative_priority);
dispatch_qos_class_t dispatch_queue_get_qos_class(dispatch_queue_t queue, int *relative_priority_ptr);
dispatch_queue_attr_t dispatch_queue_attr_make_initially_inactive(dispatch_queue_attr_t attr);
dispatch_queue_attr_t dispatch_queue_attr_make_with_autorelease_frequency(dispatch_queue_attr_t attr, dispatch_autorelease_frequency_t frequency);

void dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_after(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block);
void dispatch_after_f(dispatch_time_t when, dispatch_queue_t queue, void *context, dispatch_function_t work);

void dispatch_sync(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_sync_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);

void dispatch_once(dispatch_once_t *predicate, dispatch_block_t block);
void dispatch_once_f(dispatch_once_t *predicate, void *context, dispatch_function_t function);

void dispatch_apply(size_t iterations, dispatch_queue_t queue, void (^block)(size_t iteration));
void dispatch_apply_f(size_t iterations, dispatch_queue_t queue, void *context, void (*work)(void *context, size_t iteration));

void dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_sync_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);

const char * dispatch_queue_get_label(dispatch_queue_t queue);
void dispatch_set_target_queue(dispatch_object_t object, dispatch_queue_t queue);

void * dispatch_get_specific(const void *key);
void dispatch_queue_set_specific(dispatch_queue_t queue, const void *key, void *context, dispatch_function_t destructor);
void * dispatch_queue_get_specific(dispatch_queue_t queue, const void *key);

void dispatch_main(void);

void dispatch_assert_queue(dispatch_queue_t queue);
void dispatch_assert_queue_barrier(dispatch_queue_t queue);
void dispatch_assert_queue_not(dispatch_queue_t queue);

dispatch_block_t dispatch_block_create(dispatch_block_flags_t flags, dispatch_block_t block);
dispatch_block_t dispatch_block_create_with_qos_class(dispatch_block_flags_t flags, dispatch_qos_class_t qos_class, int relative_priority, dispatch_block_t block);

void dispatch_block_perform(dispatch_block_flags_t flags, dispatch_block_t block);
void dispatch_block_notify(dispatch_block_t block, dispatch_queue_t queue, dispatch_block_t notification_block);
intptr_t dispatch_block_wait(dispatch_block_t block, dispatch_time_t timeout);
void dispatch_block_cancel(dispatch_block_t block);
intptr_t dispatch_block_testcancel(dispatch_block_t block);

dispatch_group_t dispatch_group_create(void);
void dispatch_group_async(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block);
void dispatch_group_async_f(dispatch_group_t group, dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_group_notify(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block);
void dispatch_group_notify_f(dispatch_group_t group, dispatch_queue_t queue, void *context, dispatch_function_t work);
intptr_t dispatch_group_wait(dispatch_group_t group, dispatch_time_t timeout);
void dispatch_group_enter(dispatch_group_t group);
void dispatch_group_leave(dispatch_group_t group);

dispatch_workloop_t dispatch_workloop_create(const char *label);
dispatch_workloop_t dispatch_workloop_create_inactive(const char *label);
void dispatch_workloop_set_autorelease_frequency(dispatch_workloop_t workloop, dispatch_autorelease_frequency_t frequency);
void dispatch_set_qos_class_floor(dispatch_object_t object, dispatch_qos_class_t qos_class, int relative_priority);
dispatch_qos_class_t dispatch_queue_get_qos_class(dispatch_queue_t queue, int *relative_priority_ptr);
void dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_after(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block);
void dispatch_after_f(dispatch_time_t when, dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_sync(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_sync_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_sync_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);

const char * dispatch_queue_get_label(dispatch_queue_t queue);
void dispatch_set_target_queue(dispatch_object_t object, dispatch_queue_t queue);

void dispatch_set_qos_class_floor(dispatch_object_t object, dispatch_qos_class_t qos_class, int relative_priority);

dispatch_source_t dispatch_source_create(dispatch_source_type_t type, uintptr_t handle, uintptr_t mask, dispatch_queue_t queue);

void dispatch_source_set_registration_handler_f(dispatch_source_t source, dispatch_function_t handler);
void dispatch_source_set_registration_handler(dispatch_source_t source, dispatch_block_t handler);
void dispatch_source_set_event_handler_f(dispatch_source_t source, dispatch_function_t handler);
void dispatch_source_set_event_handler(dispatch_source_t source, dispatch_block_t handler);
void dispatch_source_set_cancel_handler_f(dispatch_source_t source, dispatch_function_t handler);
void dispatch_source_set_cancel_handler(dispatch_source_t source, dispatch_block_t handler);

uintptr_t dispatch_source_get_data(dispatch_source_t source);
uintptr_t dispatch_source_get_mask(dispatch_source_t source);
uintptr_t dispatch_source_get_handle(dispatch_source_t source);
void dispatch_source_merge_data(dispatch_source_t source, uintptr_t value);
void dispatch_source_set_timer(dispatch_source_t source, dispatch_time_t start, uint64_t interval, uint64_t leeway);
void dispatch_source_cancel(dispatch_source_t source);
intptr_t dispatch_source_testcancel(dispatch_source_t source);


dispatch_io_t dispatch_io_create(dispatch_io_type_t type, dispatch_fd_t fd, dispatch_queue_t queue, void (^cleanup_handler)(int error));
dispatch_io_t dispatch_io_create_with_io(dispatch_io_type_t type, dispatch_io_t io, dispatch_queue_t queue, void (^cleanup_handler)(int error));
dispatch_io_t dispatch_io_create_with_path(dispatch_io_type_t type, const char *path, int oflag, mode_t mode, dispatch_queue_t queue, void (^cleanup_handler)(int error));

void dispatch_read(dispatch_fd_t fd, size_t length, dispatch_queue_t queue, void (^handler)(dispatch_data_t data, int error));
void dispatch_io_read(dispatch_io_t channel, off_t offset, size_t length, dispatch_queue_t queue, dispatch_io_handler_t io_handler);

void dispatch_write(dispatch_fd_t fd, dispatch_data_t data, dispatch_queue_t queue, void (^handler)(dispatch_data_t data, int error));
void dispatch_io_write(dispatch_io_t channel, off_t offset, dispatch_data_t data, dispatch_queue_t queue, dispatch_io_handler_t io_handler);

void dispatch_io_close(dispatch_io_t channel, dispatch_io_close_flags_t flags);

dispatch_fd_t dispatch_io_get_descriptor(dispatch_io_t channel);
void dispatch_io_set_interval(dispatch_io_t channel, uint64_t interval, dispatch_io_interval_flags_t flags);
void dispatch_io_set_low_water(dispatch_io_t channel, size_t low_water);
void dispatch_io_set_high_water(dispatch_io_t channel, size_t high_water);
void dispatch_io_barrier(dispatch_io_t channel, dispatch_block_t barrier);

dispatch_data_t dispatch_data_create(const void *buffer, size_t size, dispatch_queue_t queue, dispatch_block_t destructor);
dispatch_data_t dispatch_data_create_map(dispatch_data_t data, const void * _Nullable *buffer_ptr, size_t *size_ptr);
dispatch_data_t dispatch_data_create_concat(dispatch_data_t data1, dispatch_data_t data2);
dispatch_data_t dispatch_data_create_subrange(dispatch_data_t data, size_t offset, size_t length);
dispatch_data_t dispatch_data_copy_region(dispatch_data_t data, size_t location, size_t *offset_ptr);

size_t dispatch_data_get_size(dispatch_data_t data);
bool dispatch_data_apply(dispatch_data_t data, dispatch_data_applier_t applier);

dispatch_semaphore_t dispatch_semaphore_create(intptr_t value);
intptr_t dispatch_semaphore_signal(dispatch_semaphore_t dsema);
intptr_t dispatch_semaphore_wait(dispatch_semaphore_t dsema, dispatch_time_t timeout);

void dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_sync_f(dispatch_queue_t queue, void *context, dispatch_function_t work);
void dispatch_barrier_async_and_wait(dispatch_queue_t queue, dispatch_block_t block);
void dispatch_barrier_async_and_wait_f(dispatch_queue_t queue, void *context, dispatch_function_t work);

dispatch_time_t dispatch_time(dispatch_time_t when, int64_t delta);
dispatch_time_t dispatch_walltime(const struct timespec *when, int64_t delta);

void dispatch_activate(dispatch_object_t object);
void dispatch_suspend(dispatch_object_t object);
void dispatch_resume(dispatch_object_t object);

void dispatch_set_target_queue(dispatch_object_t object, dispatch_queue_t queue);
void * dispatch_get_context(dispatch_object_t object);
void dispatch_set_context(dispatch_object_t object, void *context);

void dispatch_retain(dispatch_object_t object);
void dispatch_release(dispatch_object_t object);
void dispatch_set_finalizer_f(dispatch_object_t object, dispatch_function_t finalizer);
void dispatch_introspection_hook_queue_create(dispatch_queue_t queue);
void dispatch_introspection_hook_queue_destroy(dispatch_queue_t queue);
void dispatch_introspection_hook_queue_item_enqueue(dispatch_queue_t queue, dispatch_object_t item);
void dispatch_introspection_hook_queue_item_dequeue(dispatch_queue_t queue, dispatch_object_t item);
void dispatch_introspection_hook_queue_callout_begin(dispatch_queue_t queue, void *context, dispatch_function_t function);
void dispatch_introspection_hook_queue_callout_end(dispatch_queue_t queue, void *context, dispatch_function_t function);
void dispatch_introspection_hook_queue_item_complete(dispatch_object_t item);

void dispatch_debug(dispatch_object_t object, const char *message, ...);
dispatch_queue_t dispatch_get_current_queue(void);
void dispatch_debugv(dispatch_object_t object, const char *message, va_list ap);
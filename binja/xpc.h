// XPC

typedef const struct _xpc_type_s * xpc_type_t;
typedef struct _launch_data *launch_data_t;
typedef struct OS_xpc_object {
    Class isa;
} *xpc_object_t;
typedef xpc_object_t xpc_connection_t;
typedef xpc_object_t xpc_endpoint_t;
typedef xpc_object_t xpc_activity_t;
typedef xpc_object_t xpc_rich_error_t;
typedef xpc_object_t xpc_session_t;
typedef struct OS_xpc_listener {} *xpc_listener_t;

typedef void (^xpc_handler_t)(xpc_object_t object);
typedef void (^xpc_activity_handler_t)(xpc_activity_t activity);
typedef void (^xpc_listener_incoming_session_handler_t)(xpc_session_t peer);
typedef void (^xpc_session_incoming_message_handler_t)(xpc_object_t message);
typedef void (^xpc_session_cancel_handler_t)(xpc_rich_error_t error);
typedef void (^xpc_session_reply_handler_t)(xpc_object_t reply, xpc_rich_error_t error);
typedef void (*xpc_connection_handler_t)(xpc_connection_t connection);
typedef void (*launch_data_dict_iterator_t)(const launch_data_t lval, const char *key, void *ctx);
typedef void (*xpc_finalizer_t)(void *value);

typedef enum : unsigned int {
} xpc_activity_state_t;

typedef enum launch_data_type_t : unsigned int {
    LAUNCH_DATA_ARRAY,
    LAUNCH_DATA_BOOL,
    LAUNCH_DATA_DICTIONARY = 1,
    LAUNCH_DATA_ERRNO,
    LAUNCH_DATA_FD,
    LAUNCH_DATA_INTEGER,
    LAUNCH_DATA_MACHPORT,
    LAUNCH_DATA_OPAQUE,
    LAUNCH_DATA_REAL,
    LAUNCH_DATA_STRING
} launch_data_type_t;

typedef enum xpc_listener_create_flags_t : uint64_t {
    XPC_LISTENER_CREATE_INACTIVE,
    XPC_LISTENER_CREATE_NONE
} xpc_listener_create_flags_t;

typedef enum xpc_session_create_flags_t : uint64_t {
    XPC_SESSION_CREATE_NONE,
    XPC_SESSION_CREATE_INACTIVE,
    XPC_SESSION_CREATE_MACH_PRIVILEGED
} xpc_session_create_flags_t;

// XPC Listener
xpc_listener_t xpc_listener_create(const char *service, dispatch_queue_t target_queue, xpc_listener_create_flags_t flags, xpc_listener_incoming_session_handler_t incoming_session_handler, xpc_rich_error_t  _Nullable *error_out);
char * xpc_listener_copy_description(xpc_listener_t listener);
bool xpc_listener_activate(xpc_listener_t listener, xpc_rich_error_t  _Nullable *error_out);
void xpc_listener_cancel(xpc_listener_t listener);
void xpc_listener_reject_peer(xpc_session_t peer, const char *reason);

// XPC Session

xpc_session_t xpc_session_create_xpc_service(const char *name, dispatch_queue_t target_queue, xpc_session_create_flags_t flags, xpc_rich_error_t  _Nullable *error_out);
xpc_session_t xpc_session_create_mach_service(const char *mach_service, dispatch_queue_t target_queue, xpc_session_create_flags_t flags, xpc_rich_error_t  _Nullable *error_out);
void xpc_session_set_target_queue(xpc_session_t session, dispatch_queue_t target_queue);
char * xpc_session_copy_description(xpc_session_t session);
bool xpc_session_activate(xpc_session_t session, xpc_rich_error_t  _Nullable *error_out);
void xpc_session_set_incoming_message_handler(xpc_session_t session, xpc_session_incoming_message_handler_t handler);
void xpc_session_cancel(xpc_session_t session);
void xpc_session_set_cancel_handler(xpc_session_t session, xpc_session_cancel_handler_t cancel_handler);
xpc_rich_error_t xpc_session_send_message(xpc_session_t session, xpc_object_t message);
void xpc_session_send_message_with_reply_async(xpc_session_t session, xpc_object_t message, xpc_session_reply_handler_t reply_handler);
xpc_object_t xpc_session_send_message_with_reply_sync(xpc_session_t session, xpc_object_t message, xpc_rich_error_t  _Nullable *error_out);
bool xpc_rich_error_can_retry(xpc_rich_error_t error);
char * xpc_rich_error_copy_description(xpc_rich_error_t error);

// XPC Connection
xpc_connection_t xpc_connection_create(const char *name, dispatch_queue_t targetq);
xpc_connection_t xpc_connection_create_from_endpoint(xpc_endpoint_t endpoint);
xpc_connection_t xpc_connection_create_mach_service(const char *name, dispatch_queue_t targetq, uint64_t flags);
void xpc_connection_set_target_queue(xpc_connection_t connection, dispatch_queue_t targetq);
void xpc_connection_set_event_handler(xpc_connection_t connection, xpc_handler_t handler);
void xpc_main(xpc_connection_handler_t handler);
void xpc_connection_activate(xpc_connection_t connection);
void xpc_connection_suspend(xpc_connection_t connection);
void xpc_connection_resume(xpc_connection_t connection);
void xpc_connection_cancel(xpc_connection_t connection);
void xpc_transaction_begin(void);
void xpc_transaction_end(void);
void xpc_connection_send_message(xpc_connection_t connection, xpc_object_t message);
void xpc_connection_send_barrier(xpc_connection_t connection, dispatch_block_t barrier);
void xpc_connection_send_message_with_reply(xpc_connection_t connection, xpc_object_t message, dispatch_queue_t replyq, xpc_handler_t handler);
xpc_object_t xpc_connection_send_message_with_reply_sync(xpc_connection_t connection, xpc_object_t message);
void xpc_main(xpc_connection_handler_t handler);

const char * xpc_connection_get_name(xpc_connection_t connection);
uid_t xpc_connection_get_euid(xpc_connection_t connection);
gid_t xpc_connection_get_egid(xpc_connection_t connection);
pid_t xpc_connection_get_pid(xpc_connection_t connection);
au_asid_t xpc_connection_get_asid(xpc_connection_t connection);
int xpc_connection_set_peer_code_signing_requirement(xpc_connection_t connection, const char *requirement);

void xpc_connection_set_context(xpc_connection_t connection, void *context);
void * xpc_connection_get_context(xpc_connection_t connection);
void xpc_connection_set_finalizer_f(xpc_connection_t connection, xpc_finalizer_t finalizer);

xpc_endpoint_t xpc_endpoint_create(xpc_connection_t connection);

// XPC Object

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


// XPC Activity
void xpc_activity_register(const char *identifier, xpc_object_t criteria, xpc_activity_handler_t handler);
void xpc_activity_unregister(const char *identifier);
xpc_activity_state_t xpc_activity_get_state(xpc_activity_t activity);
bool xpc_activity_set_state(xpc_activity_t activity, xpc_activity_state_t state);
bool xpc_activity_should_defer(xpc_activity_t activity);
xpc_object_t xpc_activity_copy_criteria(xpc_activity_t activity);
void xpc_activity_set_criteria(xpc_activity_t activity, xpc_object_t criteria);

// XPC Events

const char *_xpc_event_key_name;
void xpc_set_event(const char* stream, const char* event_name, xpc_object_t xdict);
void xpc_set_event_stream_handler(const char *stream, dispatch_queue_t targetq, xpc_handler_t handler);

// LaunchD

int launch_activate_socket(const char *name, int * _Nonnull *fds, size_t *cnt);

launch_data_t launch_data_alloc(launch_data_type_t type);
size_t launch_data_array_get_count(const launch_data_t larray);
launch_data_t launch_data_array_get_index(const launch_data_t larray, size_t idx);
bool launch_data_array_set_index(launch_data_t larray, const launch_data_t lval, size_t idx);
launch_data_t launch_data_copy(launch_data_t ld);
size_t launch_data_dict_get_count(const launch_data_t ldict);
bool launch_data_dict_insert(launch_data_t ldict, const launch_data_t lval, const char *key);
void launch_data_dict_iterate(const launch_data_t ldict, launch_data_dict_iterator_t iterator, void *ctx);
launch_data_t launch_data_dict_lookup(const launch_data_t ldict, const char *key);
bool launch_data_dict_remove(launch_data_t ldict, const char *key);
void launch_data_free(launch_data_t ld);
bool launch_data_get_bool(const launch_data_t ld);
int launch_data_get_errno(const launch_data_t ld);
int launch_data_get_fd(const launch_data_t ld);
long long launch_data_get_integer(const launch_data_t ld);
mach_port_t launch_data_get_machport(const launch_data_t ld);
void * launch_data_get_opaque(const launch_data_t ld);
size_t launch_data_get_opaque_size(const launch_data_t ld);
double launch_data_get_real(const launch_data_t ld);
const char * launch_data_get_string(const launch_data_t ld);
launch_data_type_t launch_data_get_type(const launch_data_t ld);
launch_data_t launch_data_new_bool(bool val);
launch_data_t launch_data_new_fd(int fd);
launch_data_t launch_data_new_integer(long long val);
launch_data_t launch_data_new_machport(mach_port_t val);
launch_data_t launch_data_new_opaque(const void *bytes, size_t sz);
launch_data_t launch_data_new_real(double val);
launch_data_t launch_data_new_string(const char *val);
bool launch_data_set_bool(launch_data_t ld, bool val);
bool launch_data_set_fd(launch_data_t ld, int fd);
bool launch_data_set_integer(launch_data_t ld, long long val);
bool launch_data_set_machport(launch_data_t ld, mach_port_t mp);
bool launch_data_set_opaque(launch_data_t ld, const void *bytes, size_t sz);
bool launch_data_set_real(launch_data_t ld, double val);
bool launch_data_set_string(launch_data_t ld, const char *val);
int launch_get_fd(void);
launch_data_t launch_msg(const launch_data_t request);


const char * xpc_debugger_api_misuse_info(void);




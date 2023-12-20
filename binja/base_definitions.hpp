
#include <sys/types.h>


// SysCtl

int sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
int sysctlbyname(const char *name, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
int sysctlnametomib(const char *name, int *mibp, size_t *sizep);


// XPC

typedef struct xpc_object {} xpc_object_t;
typedef enum {
} xpc_session_create_flags_t;

void xpc_activity_register(const char *identifier, xpc_object_t criteria, xpc_activity_handler_t handler);
xpc_listener_t xpc_listener_create(const char *service, dispatch_queue_t target_queue, xpc_listener_create_flags_t flags,  xpc_listener_incoming_session_handler_t incoming_session_handler, xpc_rich_error_t  _Nullable *error_out);
void xpc_session_set_target_queue(xpc_session_t session, dispatch_queue_t target_queue);
xpc_session_t xpc_session_create_xpc_service(const char *name, dispatch_queue_t target_queue, xpc_session_create_flags_t flags, xpc_rich_error_t  _Nullable *error_out);
xpc_session_t xpc_session_create_mach_service(const char *mach_service, dispatch_queue_t target_queue, xpc_session_create_flags_t flags, xpc_rich_error_t  _Nullable *error_out);
void xpc_session_set_target_queue(xpc_session_t session, dispatch_queue_t target_queue);
xpc_remote_connection_create_remote_service_listener(const char *service_name, dispatch_queue_t target_queue, xpc_session_create_flags_t flags)

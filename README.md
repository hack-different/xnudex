

Vertex

* Device
* OS
* IPSW (Edge to Device and Edge to OS, Child Vertex to many disk images)
* Disk Image
* Executable
* Kernel
* Mach Port
* Entitlement
* Entitlement Known Value
* Device Tree
* Device Node

# IOKit

## Code Markers

### Client Code (Userland)

* C
  * 

* Shared Library

# Symbols

Symbols are attached by reading in dSYM/DWARF or from the DYLD opcode binding format.  These come in various forms, but only 4 primary types:

* Classic C Symbols
* C++ (Common in IOKit)
* ObjectiveC (Metadata stored elsewhere in ObjC data structures)
* Swift


# XPC Services

## Code Markers

There are two primary elements of note when it comes to XPC services, the identity of the service as well as the identity of the event.  These can be indexed by the analysis of related metadata (like the launch services database) as well as from static analysis of code paths that create the services.  Event names are not declarative and require either log analysis or static analysis of the event name types.

### Server Side

* C
  * `void xpc_activity_register(const char *identifier, xpc_object_t criteria, xpc_activity_handler_t handler)`
  * `xpc_listener_t xpc_listener_create(const char *service, dispatch_queue_t target_queue, xpc_listener_create_flags_t flags,  xpc_listener_incoming_session_handler_t incoming_session_handler, xpc_rich_error_t  _Nullable *error_out)`
  * `void xpc_session_set_target_queue(xpc_session_t session, dispatch_queue_t target_queue)`


* Swift
  * `class XPCListener`

### Client Side

* C
  * `xpc_session_t xpc_session_create_xpc_service(const char *name, dispatch_queue_t target_queue, xpc_session_create_flags_t flags, xpc_rich_error_t  _Nullable *error_out)`
  * `xpc_session_t xpc_session_create_mach_service(const char *mach_service, dispatch_queue_t target_queue, xpc_session_create_flags_t flags, xpc_rich_error_t  _Nullable *error_out)`
  * `void xpc_session_set_target_queue(xpc_session_t session, dispatch_queue_t target_queue)`
  * `xpc_remote_connection_create_remote_service_listener(const char *service_name, dispatch_queue_t target_queue, xpc_session_create_flags_t flags)`
  * `xpc_remote_connection_create_with_remote_service`
* Swift
  * 


* LaunchD Service
* ObjectiveC Class
* SysCtl

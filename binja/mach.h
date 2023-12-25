// Mach

typedef struct task *task_t;
typedef int kern_return_t;
typedef task_t task_port_t;
typedef struct mach_msg_header_t {
} mach_msg_header_t;

typedef struct audit_token_t {
} audit_token_t;

void mig_dealloc_reply_port(mach_port_t reply_port);
void mach_msg_destroy_from_kernel_proper(mach_msg_header_t *msg);
void mig_put_reply_port(mach_port_t reply_port);
mach_port_t mig_get_reply_port(void);

typedef void (^notify_handler_t)(int token);

uint32_t notify_cancel(int token);
uint32_t notify_check(int token, int *check);
uint32_t notify_get_state(int token, uint64_t *state64);
uint32_t notify_post(const char *name);
uint32_t notify_register_check(const char *name, int *out_token);
uint32_t notify_register_dispatch(const char *name, int *out_token, dispatch_queue_t queue, notify_handler_t handler);
uint32_t notify_register_mach_port(const char *name, mach_port_t *notify_port, int flags, int *out_token);
uint32_t notify_register_signal(const char *name, int sig, int *out_token);
uint32_t notify_resume(int token);
uint32_t notify_set_state(int token, uint64_t state64);
uint32_t notify_suspend(int token);

bool notify_is_valid_token(int val);
uint32_t notify_register_file_descriptor(const char *name, int *notify_fd, int flags, int *out_token);




size_t os_proc_available_memory(void);

typedef void (^os_block_t)(void);
typedef void (*os_function_t)(void *);

void os_release(void *object);
void * os_retain(void *object);


// Code Sign

int csops(pid_t pid, unsigned int  ops, void * useraddr, size_t usersize);
int csops_audittoken(pid_t pid, unsigned int  ops, void * useraddr, size_t usersize, audit_token_t * token);
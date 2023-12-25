
typedef struct {
} FILE;

typedef unsigned int socklen_t;

typedef void (*sig_t) (int);
sig_t signal(int sig, sig_t func);
char * strerror(int errnum);

void* dlopen(const char* path, int mode);
void* dlsym(void* handle, const char* symbol);
const char* dlerror(void);

int uuid_is_null(uuid_t uu);

// Memory
void * memmove(void *dst, const void *src, size_t len);
int memcmp(const void *s1, const void *s2, size_t n);
void * memcpy(void * dst, const void * src, size_t n);
size_t malloc_good_size(size_t size);
size_t malloc_size(const void *ptr);
void *calloc(size_t count, size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *reallocf(void *ptr, size_t size);
void *valloc(size_t size);
void *aligned_alloc(size_t alignment, size_t size);
void bzero(void *s, size_t n);

size_t strlen(const char *s);
size_t strnlen(const char *s, size_t maxlen);
char * strstr(const char *haystack, const char *needle);
char * strcasestr(const char *haystack, const char *needle);
char * strnstr(const char *haystack, const char *needle, size_t len);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char * strdup(const char *s1);
char * strndup(const char *s1, size_t n);


// Printf and Friends
int printf(const char * format, ...);
int fprintf(FILE *  stream, const char * format, ...);
int sprintf(char *  str, const char *  format, ...);
int snprintf(char * str, size_t size, const char * format, ...);
int asprintf(char **ret, const char *format, ...);
int dprintf(int fd, const char * format, ...);
int vprintf(const char *  format, va_list ap);
int vfprintf(FILE *  stream, const char *  format, va_list ap);
int vsprintf(char *  str, const char *  format, va_list ap);
int vsnprintf(char *  str, size_t size, const char *  format, va_list ap);
int vasprintf(char **ret, const char *format, va_list ap);
int vdprintf(int fd, const char *  format, va_list ap);
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t recvfrom(int socket, void * buffer, size_t length, int flags, struct sockaddr * address, socklen_t * address_len);
ssize_t recvmsg(int socket, struct msghdr *message, int flags);

int kqueue(void);
int kevent(int kq, const struct kevent *changelist, int nchanges, struct kevent *eventlist, int nevents, const struct timespec *timeout);
int kevent64(int kq, const struct kevent64_s *changelist, int nchanges, struct kevent64_s *eventlist, int nevents, unsigned int flags, const struct timespec *timeout);
int kevent_qos(int kq, const struct kevent_qos_s *changelist, int nchanges, struct kevent_qos_s *eventlist, int nevents, void *data_out, size_t *data_available, unsigned int flags);

// POSIX Threads

typedef __darwin_pthread_mutex_t	pthread_mutex_t;

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int pthread_cond_broadcast(pthread_cond_t *cond);

// Audit

typedef	uid_t		au_id_t;
typedef	pid_t		au_asid_t;
typedef	u_int16_t	au_event_t;
typedef	u_int16_t	au_emod_t;
typedef	u_int32_t	au_class_t;
typedef	u_int64_t	au_asflgs_t __attribute__ ((aligned (8)));

// SysCtl

int sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
int sysctlbyname(const char *name, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
int sysctlnametomib(const char *name, int *mibp, size_t *sizep);

// Processes

pid_t _getpid();
pid_t _getppid();
const char * getprogname();
void setprogname(const char *progname);

// File

int _close(int fildes);
FILE* fopen(const char * path, const char * mode);
FILE* fdopen(int fildes, const char *mode);
FILE* freopen(const char *path, const char *mode, FILE *stream);
FILE* fmemopen(void **buf, size_t size, const char * mode);
int fputs(const char * s, FILE * stream);
int puts(const char *s);
ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset);
ssize_t _write(int fildes, const void *buf, size_t nbyte);
ssize_t writev(int fildes, const struct iovec *iov, int iovcnt);
ssize_t pwritev(int fildes, const struct iovec *iov, int iovcnt, off_t offset);
ssize_t pread(int d, void *buf, size_t nbyte, off_t offset);
ssize_t _read(int fildes, void *buf, size_t nbyte);
ssize_t preadv(int d, const struct iovec *iov, int iovcnt, off_t offset);
ssize_t readv(int d, const struct iovec *iov, int iovcnt);

// TTY

char * ttyname(int fd);
int ttyname_r(int fd, char *buf, size_t len);
int _isatty(int fd);

// Network

int socket(int domain, int type, int protocol);
int listen(int socket, int backlog);
int bind(int socket, const struct sockaddr *address, socklen_t address_len);
int accept(int socket, struct sockaddr * address, socklen_t * address_len);
int getpeername(int socket, struct sockaddr *address, socklen_t *address_len);
int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host, socklen_t hostlen, char *serv, socklen_t servlen, int flags);
int getsockname(int socket, struct sockaddr * address, socklen_t * address_len);
int getsockopt(int socket, int level, int option_name, void * option_value, socklen_t * option_len);
int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);

//  Time

char * asctime(const struct tm *timeptr);
char * asctime_r(const struct tm * timeptr, char * buf);
char * ctime(const time_t *clock);
char * ctime_r(const time_t *clock, char *buf);
double difftime(time_t time1, time_t time0);
struct tm * gmtime(const time_t *clock);
struct tm * gmtime_r(const time_t *clock, struct tm *result);
struct tm * localtime(const time_t *clock);
struct tm * localtime_r(const time_t *clock, struct tm *result);
time_t mktime(struct tm *timeptr);
time_t timegm(struct tm *timeptr);
time_t timelocal(struct tm *timeptr);
time_t time(time_t *tloc);
int _usleep(useconds_t microseconds);
size_t strftime(char * s, size_t maxsize, const char * format, const struct tm * timeptr);
int gettimeofday(struct timeval * tp, void * tzp);
int settimeofday(const struct timeval *tp, const struct timezone *tzp);


// Random

char * initstate(unsigned seed, char *state, size_t size);
long _random(void);
char * setstate(const char *state);
void srandom(unsigned seed);
void srandomdev(void);


// Error

char *strerror(int errnum);
int strerror_r(int errnum, char *strerrbuf, size_t buflen);
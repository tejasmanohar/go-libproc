#include <sys/proc_info.h>
#include <sys/resource.h>
#include <dlfcn.h>
#include <errno.h>


int FUNCTION_UNAVAILABLE_ERROR = -1;

int (*_proc_listpidspath) (uint32_t type, uint32_t typeinfo, const char *path,
  uint32_t pathflags, void *buffer, int buffersize);

int (*_proc_listpids) (uint32_t type, uint32_t typeinfo, void *buffer, int buffersize);
int (*_proc_listallpids) (void * buffer, int buffersize);
int (*_proc_listpgrppids) (pid_t pgrpid, void * buffer, int buffersize);
int (*_proc_listchildpids) (pid_t ppid, void * buffer, int buffersize);
int (*_proc_pidinfo) (int pid, int flavor, uint64_t arg,  void *buffer, int buffersize);
int (*_proc_pidfdinfo) (int pid, int fd, int flavor, void * buffer, int buffersize);
int (*_proc_pidfileportinfo) (int pid, uint32_t fileport, int flavor, void *buffer, int buffersize);
int (*_proc_name) (int pid, void * buffer, uint32_t buffersize);
int (*_proc_regionfilename) (int pid, uint64_t address, void * buffer, uint32_t buffersize);
int (*_proc_kmsgbuf) (void * buffer, uint32_t buffersize);
int (*_proc_pidpath) (int pid, void * buffer, uint32_t buffersize);
int (*_proc_libversion) (int *major, int * minor);

int (*_proc_pid_rusage) (int pid, int flavor, rusage_info_t *buffer);

int (*_proc_setpcontrol) (const int control);

int (*_proc_track_dirty) (pid_t pid, uint32_t flags);
int (*_proc_set_dirty) (pid_t pid, bool dirty);
int (*_proc_get_dirty) (pid_t pid, uint32_t *flags);
int (*_proc_clear_dirty) (pid_t pid, uint32_t flags);

int (*_proc_terminate) (pid_t pid, int *sig);

void init(int argc, char **argv, char **envp) {
  void* dl = dlopen("/usr/lib/libproc.dylib", RTLD_NOW);

  _proc_listpidspath = dlsym(dl, "proc_listpidspath");

  _proc_listpids = dlsym(dl, "proc_listpids");
  _proc_listallpids = dlsym(dl, "proc_listallpids");
  _proc_listpgrppids = dlsym(dl, "proc_listpgrppids");
  _proc_listchildpids = dlsym(dl, "proc_listchildpids");
  _proc_pidinfo = dlsym(dl, "proc_pidinfo");
  _proc_pidfdinfo = dlsym(dl, "proc_pidfdinfo");
  _proc_pidfileportinfo = dlsym(dl, "proc_pidfileportinfo");
  _proc_name = dlsym(dl, "proc_name");
  _proc_regionfilename = dlsym(dl, "proc_regionfilename");
  _proc_kmsgbuf = dlsym(dl, "proc_kmsgbuf");
  _proc_pidpath = dlsym(dl, "proc_pidpath");
  _proc_libversion = dlsym(dl, "proc_libversion");

  _proc_pid_rusage = dlsym(dl, "proc_pid_rusage");

  _proc_setpcontrol = dlsym(dl, "proc_setpcontrol");
  _proc_track_dirty = dlsym(dl, "proc_track_dirty");
  _proc_set_dirty = dlsym(dl, "proc_set_dirty");
  _proc_get_dirty = dlsym(dl, "proc_get_dirty");
  _proc_clear_dirty = dlsym(dl, "proc_clear_dirty");

  _proc_terminate = dlsym(dl, "proc_terminate");
}
__attribute__((section("__DATA,__mod_init_func"))) typeof(init) *__init = init;


int listpidspath(uint32_t type, uint32_t typeinfo, const char *path, uint32_t pathflags,
  void *buffer, int buffersize)
{
  if (!_proc_listpidspath) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_listpidspath)(type, typeinfo, path, pathflags, buffer, buffersize);
}

int listpids(uint32_t type, uint32_t typeinfo, void * buffer, int buffersize)
{
  if (!_proc_listpids) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_listpids)(type, typeinfo, buffer, buffersize);
}

int listallpids(void * buffer, int buffersize)
{
  if (!_proc_listallpids) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_listallpids)(buffer, buffersize);
}

int listpgrppids(pid_t pgrpid, void * buffer, int buffersize)
{
  if (!_proc_listpgrppids) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_listpgrppids)(pgrpid, buffer, buffersize);
}

int listchildpids(pid_t ppid, void * buffer, int buffersize)
{
  if (!_proc_listchildpids) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_listchildpids)(ppid, buffer, buffersize);
}

int pidinfo(int pid, int flavor, uint64_t arg,  void *buffer, int buffersize)
{
  if (!_proc_pidinfo) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_pidinfo)(pid, flavor, arg, buffer, buffersize);
}

int pidfdinfo(int pid, int fd, int flavor, void * buffer, int buffersize)
{
  if (!_proc_pidfdinfo) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_pidfdinfo)(pid, fd, flavor, buffer, buffersize);
}

int pidfileportinfo(int pid, uint32_t fileport, int flavor, void *buffer, int buffersize)
{
  if (!_proc_pidfileportinfo) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_pidfileportinfo)(pid, fileport, flavor, buffer, buffersize);
}

int name(int pid, void * buffer, uint32_t buffersize)
{
  if (!_proc_name) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_name)(pid, buffer, buffersize);
}

int regionfilename(int pid, uint64_t address, void * buffer, uint32_t buffersize)
{
  if (!_proc_regionfilename) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_regionfilename)(pid, address, buffer, buffersize);
}

int kmsgbuf(void * buffer, uint32_t buffersize)
{
  if (!_proc_kmsgbuf) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_kmsgbuf)(buffer, buffersize);
}

int pidpath(int pid, void * buffer, uint32_t buffersize)
{
  if (!_proc_pidpath) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_pidpath)(pid, buffer, buffersize);
}

int libversion(int *major, int * minor)
{
  if (!_proc_libversion) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_libversion)(major, minor);
}

int pid_rusage(int pid, int flavor, rusage_info_t *buffer)
{
  if (!_proc_pid_rusage) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_pid_rusage)(pid, flavor, buffer);
}

int setpcontrol(const int control)
{
  if (!_proc_setpcontrol) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_setpcontrol)(control);
}

int track_dirty(pid_t pid, uint32_t flags)
{
  if (!_proc_track_dirty) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_track_dirty)(pid, flags);
}

int set_dirty(pid_t pid, bool dirty)
{
  if (!_proc_set_dirty) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_set_dirty)(pid, dirty);
}

int get_dirty(pid_t pid, uint32_t *flags)
{
  if (!_proc_get_dirty) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_get_dirty)(pid, flags);
}

int clear_dirty(pid_t pid, uint32_t flags)
{
  if (!_proc_clear_dirty) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_clear_dirty)(pid, flags);
}

int terminate(pid_t pid, int *sig)
{
  if (!_proc_terminate) {
    errno = FUNCTION_UNAVAILABLE_ERROR;
    return 0;
  }

  return (*_proc_terminate)(pid, sig);
}

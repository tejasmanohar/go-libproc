#include <sys/proc_info.h>
#include <dlfcn.h>
#include <errno.h>


int NOT_IMPLEMENTED_ERROR = -1;


int (*proc_listpids) (uint32_t type, uint32_t typeinfo, void *buffer, int buffersize);

void init(int argc, char **argv, char **envp) {
  void* dl = dlopen("/usr/lib/libproc.dylib", RTLD_NOW);

  proc_listpids = dlsym(dl, "proc_listpids");
}
__attribute__((section("__DATA,__mod_init_func"))) typeof(init) *__init = init;


int listpids(uint32_t type, uint32_t typeinfo, void *buffer, int buffersize)
{
  if (!proc_listpids) {
    errno = NOT_IMPLEMENTED_ERROR;
    return 0;
  }

  return (*proc_listpids)(type, typeinfo, buffer, buffersize);
}

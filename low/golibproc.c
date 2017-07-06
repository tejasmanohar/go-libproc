#include <sys/proc_info.h>
#include <libproc.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

const int unimplemented = -1;

// #pragma weak proc_listpids
// int proc_listpids(uint32_t type, uint32_t typeinfo, void *buffer, int buffersize)
// {
//   return unimplemented;
// }

int listpids(uint32_t type, uint32_t typeinfo, void *buffer, int buffersize)
{
  return proc_listpids(type, typeinfo, buffer, buffersize);
}

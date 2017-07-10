int	listpidspath(uint32_t type, uint32_t typeinfo, const char *path, uint32_t pathflags,
  void *buffer, int buffersize);

int listpids(uint32_t type, uint32_t typeinfo, void *buffer, int buffersize);
int listallpids(void * buffer, int buffersize);
int listpgrppids(pid_t pgrpid, void * buffer, int buffersize);
int listchildpids(pid_t ppid, void * buffer, int buffersize);
int pidinfo(int pid, int flavor, uint64_t arg,  void *buffer, int buffersize);
int pidfdinfo(int pid, int fd, int flavor, void * buffer, int buffersize);
int pidfileportinfo(int pid, uint32_t fileport, int flavor, void *buffer, int buffersize);
int name(int pid, void * buffer, uint32_t buffersize);
int regionfilename(int pid, uint64_t address, void * buffer, uint32_t buffersize);
int kmsgbuf(void * buffer, uint32_t buffersize);
int pidpath(int pid, void * buffer, uint32_t buffersize);
int libversion(int *major, int * minor);

int pid_rusage(int pid, int flavor, rusage_info_t *buffer);

int setpcontrol(const int control);

int track_dirty(pid_t pid, uint32_t flags);
int set_dirty(pid_t pid, bool dirty);
int get_dirty(pid_t pid, uint32_t *flags);
int clear_dirty(pid_t pid, uint32_t flags);

int terminate(pid_t pid, int *sig);

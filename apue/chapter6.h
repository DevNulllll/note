#include<pwd.h>


struct passwd *getpwuid(uid_t uid);
struct passwd *getpwnam(const char *name);

#include "syscalldb.h"
#include <stdarg.h>
#include <errno.h>

int __attribute__((weak)) register_library (const char * name, unsigned long load_address)
{
	return 0;
}

long int __attribute__((weak)) glibc_option (const char * opt)
{
	return -EINVAL;
}

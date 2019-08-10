#include <errno.h>
#include <libos.h>

#ifdef ENABLE_LIBOS
int __attribute__((weak)) __libos_register_library (
			const char * name, unsigned long load_address)
{
  return 0;
}

void __attribute__((weak)) __libos_check_glibc_version (const char * relase, const char * version, const char* libos_target)
{
}

long int __attribute__((weak)) __libos_glibc_option (const char * opt)
{
  return -EINVAL;
}
#endif

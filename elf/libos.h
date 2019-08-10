#ifdef ENABLE_LIBOS
extern int __libos_register_library (const char * name, unsigned long load_address) __attribute__((weak));
extern void __libos_check_glibc_version (const char * relase, const char * version, const char* libos_target) __attribute__((weak));
extern long int __libos_glibc_option (const char * opt) __attribute__((weak));
#else
# define __libos_register_library(name, addr) do { } while (0)
# define __libos_check_glibc_version(release, version, libos_target)  do { } while (0)
# define __libos_glibc_option(opt)  (-EINVAL)
#endif

#ifndef _SYSCALLDB_H_
#define _SYSCALLDB_H_

#ifdef __ASSEMBLER__

#else /* !__ASSEMBLER__ */

int register_library (const char * name, unsigned long load_address) __attribute__((weak));
long int glibc_option (const char * opt) __attribute__((weak));

#endif /* __ASSEMBLER__ */

#endif /* _SYSCALLDB_H */

#ifndef _SYSCALLDB_H_
#define _SYSCALLDB_H_

#ifdef __ASSEMBLER__
.weak syscalldb
.type syscalldb, @function

# if defined(PSEUDO) && defined(SYSCALL_NAME) && defined(SYSCALL_SYMBOL)
#  define SYSCALLDB                     \
    subq $128, %rsp;                    \
    callq *syscalldb@GOTPCREL(%rip);    \
    addq $128, %rsp
# else
#  define SYSCALLDB                             \
    callq *syscalldb@GOTPCREL(%rip)
# endif

#else /* !__ASSEMBLER__ */
asm (
".weak syscalldb\r\n"
".type syscalldb, @function\r\n");

#define SYSCALLDB                           \
    "subq $128, %%rsp\n\t"                  \
    "callq *syscalldb@GOTPCREL(%%rip)\n\t"  \
    "addq $128, %%rsp\n\t"

#define SYSCALLDB_ASM                       \
    "callq *syscalldb@GOTPCREL(%rip)\n\t"

int register_library (const char * name, unsigned long load_address) __attribute__((weak));
long int glibc_option (const char * opt) __attribute__((weak));

#endif /* __ASSEMBLER__ */

#endif /* _SYSCALLDB_H */

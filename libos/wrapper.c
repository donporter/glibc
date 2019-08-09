#include <errno.h>
#include <kernel-features.h>
#include <shim_unistd.h>
#include <sysdep.h>
#include <sysdep-cancel.h>
#include <sys/syscall.h>

#ifdef __NR_checkpoint
int checkpoint (const char *filename)
{
	return INLINE_SYSCALL (checkpoint, 1, filename);
}
#endif

#ifdef __NR_msgpersist
int msgpersist (int msqid, int cmd)
{
	return INLINE_SYSCALL (msgpersist, 2, msqid, cmd);
}
#endif

#ifdef __NR_benchmark_rpc
int benchmark_rpc(pid_t pid, int times, const void *buf, size_t size)
{
	return INLINE_SYSCALL (benchmark_rpc, 4, pid, times, buf, size);
}
#endif

#ifdef __NR_send_rpc
size_t send_rpc (pid_t pid, const void *buf, size_t size)
{
	return INLINE_SYSCALL (send_rpc, 3, pid, buf, size);
}
#endif

#ifdef __NR_recv_rpc
size_t recv_rpc (pid_t * pid, void *buf, size_t size)
{
	return INLINE_SYSCALL (recv_rpc, 3, pid, buf, size);
}
#endif

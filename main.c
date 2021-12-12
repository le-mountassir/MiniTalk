#include <string.h>
#include <stdio.h>
#include "minitalk.h"

void ptr_f(int sig, siginfo_t *info, void *p)
{
    int pid = info->si_pid;
    printf("hi%d\n", pid);
}
int main()
{
    printf("----%d----\n", getpid());
    struct sigaction sigs;
    sigs.sa_sigaction = ptr_f;
    sigs.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigs, NULL);
    while (1)
    {
        sleep(1);
    }
}
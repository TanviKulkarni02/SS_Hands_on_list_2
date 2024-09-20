#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void handle_sigalrm()
{
    printf("SIGALRM caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2; // Set an alarm for 2 second
    timer.it_value.tv_usec = 0;
    int timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");
    status = signal(SIGALRM, (void *)handle_sigalrm);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        while (1)
            ; // waiting for alarm
    }
}

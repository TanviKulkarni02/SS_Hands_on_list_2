#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_fpe()
{
printf("caught SIGFPE signal\n");
exit(0);
}

void main()
{

__sighandler_t status;
status = signal(SIGFPE , (void*)signal_fpe);

if(status == SIG_ERR){
perror("error while assigning signal handler\n");
}

else{
raise(SIGFPE);
}

}

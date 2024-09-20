#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_alrm()
{
printf("caught signal alarm\n");
}

void main()
{

__sighandler_t status;
status = signal(SIGALRM , (void*)sig_alrm);

if(status == SIG_ERR){
printf("error in assigning signal handler\n");
}

else{
raise(SIGALRM);
}
}

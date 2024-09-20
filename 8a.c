#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigsegv(int sig)
{

printf("caught SIGSEGV signal using signal system call\n");
exit(1);

}



void main()
{
__sighandler_t status;

status = signal( SIGSEGV, (void*)handle_sigsegv );

if( status == SIG_ERR){
printf("error while assigning signal handler\n");
}

else{
raise(SIGSEGV);
}



}

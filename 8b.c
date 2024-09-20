#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void handle_sigint() 
{
printf("caught SIGINT signal\n" );
exit(0);
}


void  main()
{

__sighandler_t status;

status =  signal(SIGINT , (void*)handle_sigint);

if(status == SIG_ERR)
{
perror("error while assigning signal handler!\n");

}
else{

raise(SIGINT);

}

}

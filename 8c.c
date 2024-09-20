/*
============================================================================
Name : 8c.c
Author : Tanvi Kulkarni
Description : 8. Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 20th Sept, 2024.
============================================================================
*/






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

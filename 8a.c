/*
============================================================================
Name : 8a.c
Author : Tanvi Kulkarni
Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 20th Sept, 2024.
============================================================================
*/





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

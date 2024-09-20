/*
============================================================================
Name : 8b.c
Author : Tanvi Kulkarni
Description : 8. Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 20th Sept, 2024.
============================================================================
*/







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

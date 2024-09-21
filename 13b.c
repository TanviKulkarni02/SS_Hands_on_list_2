/*
============================================================================
Name : 13b.c
Author : Tanvi Kulkarni
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {

int pid;

printf("Enter the PID of the process to send SIGSTOP: ");
scanf("%d", &pid);

if (kill(pid, SIGSTOP) == 0) {
printf("SIGSTOP signal sent to the process  %d\n", pid);
}
else
{
perror("Failed to send the SIGSTOP signal");
exit(EXIT_FAILURE);
}

return 0;
}

/* Enter the PID of the process to send SIGSTOP: 15421
SIGSTOP signal sent to process 15421
*/

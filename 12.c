
/*
============================================================================
Name : 12.c
Author : Tanvi Kulkarni
Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date : 20th Sept , 2024
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {

        printf("Child process %d\n", getpid());
        printf("Sending SIGKILL to parent %d \n", getppid());
        kill(getppid(), SIGKILL);

       sleep(5);

        printf("Child process %d is now orphan, parent pid is %d\n", getpid(),getppid());

    } else {
        printf("Parent  %d is alive. Waiting for signal from child...\n", getpid());
        sleep(10);
    }

    return 0;
}



/*
============================================================================
Output:

Parent  14780 is alive. Waiting for signal from child...
Child process 14781
Sending SIGKILL to parent 14780 
Killed
Child process 14781 is now orphan, parent pid is 1609

============================================================================
*/


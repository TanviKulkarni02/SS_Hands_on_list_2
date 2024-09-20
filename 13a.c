/*
============================================================================
Name : 13.c
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


void handleSigstop(int signum) {
    printf(" catch SIGSTOP\n");
}

int main() {
    

    
  
    if (signal(SIGSTOP, handleSigstop) == SIG_ERR) {
        printf("Can't catch SIGSTOP.\n");
    }

    printf("Process PID: %d is running..\n", getpid());
    
    
    while (1) {
        printf("Running...%d\n",getpid());
        sleep(3);
    }

    return 0;
}


/*
============================================================================
Output:

Can't catch SIGSTOP.
Process PID: 15421 is running..
Running...15421
Running...15421

[1]+  Stopped                 ./a.out

============================================================================
*/

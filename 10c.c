/*
============================================================================
Name : 10c.c
Author : Tanvi Kulkarni
Description : 10. Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 20th Sept, 2024.
============================================================================
*/







#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf("Caught Floating Point Exception\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;

    sigaction(SIGFPE, &sa, NULL);

    int x = 5;
    int y = 0;
    int z = x / y;

   
    return 0;
}

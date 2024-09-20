/*
============================================================================
Name : 10a.c
Author : Tanvi Kulkarni
Description : 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 20th Sept, 2024.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf("Caught signal Segmentation Fault\n");
    exit(1);
}

int main() {
    
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    sigaction(SIGSEGV, &sa, NULL);
    int *ptr = NULL;
    *ptr = 42;

    return 0;

}

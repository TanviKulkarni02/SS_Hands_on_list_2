/*
============================================================================
Name : 1a.c
Author : Tanvi Kulkarni
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date: 12th Sept, 2024.
============================================================================
*/






#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void handleSignal(int sig) {
    printf("Timer expired in 10 seconds and 10 microsecond interval and signal number is %d\n",sig);
}

int main(){
signal(SIGALRM, handleSignal);
struct timeval interval;
interval.tv_sec =10;
interval.tv_usec = 10;

struct timeval value;
value.tv_sec = 10;
value.tv_usec = 10;

struct itimerval newValue;
newValue.it_interval = interval;
newValue.it_value = value;

int timer = setitimer(ITIMER_REAL, &newValue, NULL);

while (1) {}

}


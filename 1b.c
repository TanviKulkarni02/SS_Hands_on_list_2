/*
============================================================================
Name : 1b.c
Author : Tanvi Kulkarni
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
b.ITIMER_VIRTUAL
Date: 12th Sept, 2024.
============================================================================
*/








#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void signalhandle(int sig){
printf("The timer  expired in 10 seconds and 10 microseconds interval and signal number is : %d\n",sig);
} 

int main()
{
signal(SIGVTALRM,signalhandle);


struct timeval interval;
interval.tv_sec = 10;
interval.tv_usec=10;

struct timeval value;
value.tv_sec = 10;
value.tv_usec=10;

struct itimerval final;
final.it_interval =  interval;
final.it_value = value;


int sigtimer =  setitimer(ITIMER_VIRTUAL,&final,NULL);
sleep(20);
while(1)
{}

}

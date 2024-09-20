/*
============================================================================
Name : 2.c
Author : Tanvi Kulkarni
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 12th Sept, 2024.
============================================================================
*/





#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

//int getrlimit(int resource, struct rlimit *rlim);

//struct rlimit {
//             rlim_t rlim_cur;  /* Soft limit */
//               rlim_t rlim_max;  /* Hard limit (ceiling for rlim_cur) */
//         };

int main() 
{
struct rlimit r0;

if(getrlimit(RLIMIT_CPU,&r0) == 0 )
{
printf("The limit for CPU resources is : soft limit =  %ld , hard limit =  %ld \n", r0.rlim_cur , r0.rlim_max);
}
else{
perror("Resource limit couldn't be retrieved");
}


if(getrlimit(RLIMIT_CORE,&r0) == 0 )
{
printf("The limit for core resources is : soft limit =  %ld , hard limit =  %ld \n", r0.rlim_cur , r0.rlim_max);
}
else{
perror("Resource limit couldn't be retrieved");
}


if(getrlimit(RLIMIT_DATA,&r0) == 0 )
{
printf("The limit for data resources is : soft limit =  %ld ,hard limit =  %ld \n", r0.rlim_cur , r0.rlim_max);
}
else{
perror("Resource limit couldn't be retrieved");
}


if(getrlimit(RLIMIT_AS,&r0) == 0 )
{
printf("The limit for maximum size of the process's virtual memory  is : soft limit = %ld ,hard limit =  %ld \n", r0.rlim_cur , r0.rlim_max);
}
else{
perror("Resource limit couldn't be retrieved");
}

return 0;
}

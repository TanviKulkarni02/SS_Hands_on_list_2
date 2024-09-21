/*
============================================================================
Name : 30c.c
Author : Tanvi Kulkarni
Description : 30. Write a program to create a shared memory.
c. detach the shared memory
Date: 21st Sept, 2024.
============================================================================
*/




#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main(void){
int key,shmid;
char *data;
key = ftok(".",'c');
shmid=shmget(key,1024,IPC_CREAT|0744);
data =shmat(shmid,0,0);
printf("shared memory attached\n");
printf("press enter to detach shared memory\n");
getchar();
shmdt(data);
printf("pointer detach from shared memory\n");
}

/*output -
tanvikulkarni@tanvikulkarni-Vostro-14-5401:~/ss/hands-on-list-2$ ./a.out
shared memory attached
press enter to detach shared memory

pointer detach from shared memory
*/

/*
============================================================================
Name : 30b.c
Author : Tanvi Kulkarni
Description : 30. Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
data =shmat(shmid,0,SHM_RDONLY);
printf("enter text:");
scanf("%[^\n]",data);
printf("data from shared memory : %s\n", data);
}

/*output
cc 30b.c
tanvikulkarni@tanvikulkarni-Vostro-14-5401:~/ss/hands-on-list-2$ ./a.out
enter text: I currently live in bangalore
Segmentation fault (core dumped)
*/

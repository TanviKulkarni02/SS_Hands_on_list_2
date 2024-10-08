/*
============================================================================
Name : 32d.c
Author : Tanvi Kulkarni
Description : 32. Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 21st Sept, 2024.
============================================================================
*/






#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
union semun {
int val;
struct semid_ds *buff;
unsigned short int *array;
};

int main(void)
{union semun arg;
int key , semid;
key = ftok(".",'a');
semid=semget(key,1,0);
semctl(semid, 0, IPC_RMID);
}

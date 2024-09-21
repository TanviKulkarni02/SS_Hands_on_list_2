/*
============================================================================
Name : 32b.c
Author : Tanvi Kulkarni
Description : 32. Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
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
int main(void){
union semun arg;
int key , semid;
key = ftok(".",'e');
semid=semget(key,1,IPC_CREAT |0644);
arg.val=1;
semctl(semid,0,SETVAL, arg);
}

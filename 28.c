/*
============================================================================
Name : 28.c
Author : Tanvi Kulkarni
Description : Write a program to change the exiting message queue permission.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){

struct msqid_ds mq_info;

int key=ftok(".",12);
if(key==-1){
perror("Error in generating the Key\n");
return 1;
}

int msg_id=msgget(key,IPC_CREAT|0744);
if(msg_id==-1){
perror("Error in generating the Message Queue id\n");
return 1;
}

if(msgctl(msg_id,IPC_STAT,&mq_info)==-1){
perror("Error in retreving the current status of the message queue\n");
return 1;
}

printf("The current permissions of the message queue: %o\n",mq_info.msg_perm.mode);

mq_info.msg_perm.mode=0666;

if(msgctl(msg_id,IPC_SET,&mq_info)==-1){
perror("Error in changing permissions of the message queue\n");
return 1;
}

printf("The New permissions of the message queue: %o\n",mq_info.msg_perm.mode);

return 0;

}


/*
============================================================================
Output:
The current permissions of the message queue: 666
The New permissions of the message queue: 666

============================================================================
*/

/*
============================================================================
Name : 26.c
Author : Tanvi Kulkarni
Description : 26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct mg_info{
long msg_type;
char msg_text[50];
}my_msg;

int main(){

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

my_msg.msg_type=1;

printf("Enter the message that you want to send through Message Queue\n");
fgets(my_msg.msg_text,sizeof(my_msg.msg_text), stdin);

if((msgsnd(msg_id,&my_msg,sizeof(my_msg.msg_text),0))==-1){
perror("Error in sending the message\n");
return 1;
}

return 0;

}

/*
============================================================================
Output:
Enter the message that you want to send through Message Queue
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0c06640e 1          tanvikulka 666        0            0           
0x0c066662 2          tanvikulka 744        200          4           
0x0c066664 3          tanvikulka 744        0            0 


============================================================================
*/

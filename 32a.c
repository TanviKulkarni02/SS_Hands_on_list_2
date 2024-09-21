/*
============================================================================
Name : 32a.c
Author : Tanvi Kulkarni
Description : 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 21st Sept, 2024.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>

int main(void)
{struct {int ticket_no;}db;

int fd, key,semid;
key=ftok(".",'a');
semid=(key,1,0);
struct sembuf buf={0,-1,0};
semid=semget(key,1,0);

fd=open("db",O_RDWR);
read(fd,&db,sizeof(db));
printf("before eterning cs\n");
semop(semid,&buf, 1);
printf("inside cs\n");
printf("current tickect no. - %d\n",db.ticket_no);
db.ticket_no ++;
lseek(fd,0L,SEEK_SET);
write(fd,&db,sizeof(db));
printf("ticket no. after updation - %d\n",db.ticket_no);
printf("press enter to exit cs\n");
getchar();
buf.sem_op=1;
semop(semid,&buf,1);
printf("exited cs\n");
}

/*output

tanvikulkarni@tanvikulkarni-Vostro-14-5401:~/ss/hands-on-list-2$ cc 32a.c
tanvikulkarni@tanvikulkarni-Vostro-14-5401:~/ss/hands-on-list-2$ ./a.out
before eterning cs
inside cs
current tickect no. - 0
ticket no. after updation - 1
press enter to exit cs

exited cs

*/

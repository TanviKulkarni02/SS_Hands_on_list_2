
/*
============================================================================
Name : 33_client.c
Author : Tanvi Kulkarni
Description : 33. Write a program to communicate between two machines using socket.
Date: 19th Sept, 2024.
============================================================================
*/







#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>




int main(int argc, char * argv[])

{

struct sockaddr_in serv;
int sd;
char buff[80];
sd = socket(AF_UNIX , SOCK_STREAM,0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons(5777);

bind(sd, (void*)(&serv) , sizeof(serv));

connect(sd,(void*)(&serv) , sizeof(serv));
write(sd, "hello server\n",14);
read(sd,buff,sizeof(buff));
printf("Message from server : %s\n",buff);

return  0;
}
/*output -

tanvikulkarni@tanvikulkarni-Vostro-14-5401:~/ss/hands-on-list-2$ ./33server
Message from client : hello server


*/

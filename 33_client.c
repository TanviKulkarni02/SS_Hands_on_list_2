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
serv.sin_port = htons(5055);

bind(sd, (void*)(&serv) , sizeof(serv));

connect(sd,(void*)(&serv) , sizeof(serv));
write(sd, "hello server\n",14);
read(sd,buff,sizeof(buff));
printf("Message from server : %s\n",buff);

return  0;
}


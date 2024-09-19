#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main()
{


struct sockaddr_in serv, cli;
int sd, sz, nsd;
char buff[80];
sd = socket(AF_UNIX , SOCK_STREAM, 0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons(5055);

bind(sd,(void*)(&serv) , sizeof(serv));

listen(sd,5);
sz = sizeof(cli);
nsd = accept(sd, (void*)(&cli) , &sz);
read(nsd, buff, sizeof(buff));
printf("Message from client : %s\n" , buff);
write(nsd, "ACK from server\n",17);
return 0;

}

/*
============================================================================
Name : 14.c
Author : Tanvi Kulkarni
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 20th Sept, 2024.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int pipefd[2]; 
char *buff;
char buf[80];
pipe(pipefd);
printf("enter string\n");
scanf("%s", buf);
write(pipefd[1], buf, sizeof(buf));
write(pipefd[1], "\n", 1);
close(pipefd[1]);

printf("Display on Monitor\n");
while (read(pipefd[0], &buff, 1))
{
write(1, &buff, 1);
}
return 0;
}

/*output
enter string
hi
Display on Monitor
hi
*/

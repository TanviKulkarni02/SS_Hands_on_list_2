

/*
============================================================================
Name : 17c.c
Author : Tanvi Kulkarni
Description : 17. Write a program to execute ls -l | wc.
c. use fcntl
Date: 21st Sept, 2024.
============================================================================
*/







#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void main()
{
    int pipefd[2];
    pid_t cid;

    if (pipe(pipefd) == -1)
    {
        printf("ERROR");
    }
    else
    {
        cid = fork();
        if (cid == 0)
        {
            close(0);
            fcntl(pipefd[0], F_DUPFD, 0);
            close(pipefd[1]); 
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(1); 
            fcntl(pipefd[1], F_DUPFD, 1);
            close(pipefd[0]); 

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}


/* output -

tanvikulkarni@tanvikulkarni-Vostro-14-5401:~/ss/hands-on-list-2$ ./a.out
     67     595    4388
*/

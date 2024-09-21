/*
============================================================================
Name : 19e.c
Author : Tanvi Kulkarni
Description : 19. Create a FIFO file by
d. mkfifo library function 
Date: 21st Sept, 2024.
============================================================================
*/



#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {

if (mkfifo("myfifo_e", 0666) == -1) {
perror("mkfifo failed");
return 1;
}

printf("FIFO file created using mkfifo library function.\n");
return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
struct rlimit r1;

if(getrlimit(RLIMIT_CPU,&r1) ==0 )
{
printf("The current limits are - soft limit : %ld , hard limit : %ld \n", r1.rlim_cur, r1.rlim_max);

}
else{
perror("error couldn't be retrieved");
}



r1.rlim_cur = 5 * 1024;
r1.rlim_max = 10 * 1024;

if(setrlimit(RLIMIT_CPU,&r1) == 0 ) 
{
printf("The limits were successfully set!\n");
}
else
{
perror("Limit couldn't be set");
}


if(getrlimit(RLIMIT_CPU , &r1) == 0)
{
printf("The modified limits are - soft link : %ld , hard limit : %ld \n", r1.rlim_cur , r1.rlim_max);
}
else{
perror("can't retrieve limit");
}

return 0;

}

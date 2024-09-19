
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc(){
 unsigned long long dst;
 __asm__ __volatile("rdtsc" :"=A" (dst));
}


int main()
{
pid_t ppid;
unsigned long long int beg;
unsigned long long int end;
unsigned long long int time;



beg = rdtsc();
for(int i=0;i<100;i++)
{
ppid = getpid();
}
end  = rdtsc();
time = (end - beg)/0.27;
printf("The time taken to execute 100 getpid() system call is : %lld seconds\n" ,  time);


return 0;
}

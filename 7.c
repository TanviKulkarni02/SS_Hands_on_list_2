#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* func(void *arg)
{
int num = *((int*)arg);
pthread_t thread_id = pthread_self();
printf("The thread id of thread %d is %lu\n" ,num , thread_id); 
pthread_exit(NULL);
}


int main()
{
pthread_t threads[3];
int thr_args[3];

for(int i=0;i<3;i++)
{
thr_args[i] = i+1;

if(pthread_create(&threads[i],NULL,func, &thr_args[i]) != 0 )
{
perror("thread creation failed");
exit(1);
}

}

for(int i=0;i<3;i++)
{
pthread_join(threads[i] , NULL);

}

printf("All threads have completed\n");

return 0;
}

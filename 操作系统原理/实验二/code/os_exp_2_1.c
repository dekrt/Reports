#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define re register

void* thread_1(void* arg)
{
	usleep(10000); // 避免输出异常
	int i; 
    for(i = 1; i <= 1000; i++)
    {
        printf("B: %04d\n", i);
        // 使用usleep函数将程序挂起2e5微秒，即0.2秒
        usleep(200000);
    }
    return NULL;
}

void* thread_2(void* arg)
{
	int i;
    for(i = 1000; i >= 1; i--)
    {
        printf("A: %04d\n", i);
        usleep(200000);
    }
    return NULL;
}

int main()
{
    pthread_t pid1, pid2;
	pthread_create(&pid1, NULL, thread_1, NULL);
	pthread_create(&pid2, NULL, thread_2, NULL);
	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
    return 0;
}

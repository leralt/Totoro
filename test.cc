#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <netinet/in.h>
#include "./include/wrap.h"


typedef struct
{
    void *(*function)(void *);          /*函数指针，回调函数*/
    void *arg;                          /*上面函数的参数*/
} threadpool_task_t;                    /*任务结构体*/

struct threadpool_t
{
    pthread_mutex_t lock;         //互斥锁
    pthread_cond_t notify;        //条件变量：配合互斥锁来避免死锁
    pthread_t *threads;           //线程数组
    threadpool_task_t *queue;     //任务队列
    int thread_count;             //线程数
    int queue_size;               //任务数
    int head;                     //头部元素
    int tail;                     //尾部元素
    int count;                    //等待的任务数
    int shutdown;                 //关闭状态
    int started;                  //已经启动的线程数
};


threadpool_t *threadpool_create(int thread_count,int queue_size,int flags)
{
    threadpool_t *pool;
    do{
        if(thread_count <= 0 || thread_count > MAX_THREADS || queue_size <= 0|| queue_size > MAX_QUEUE) return NULL;
        if((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL) break;
        
        pool->thread_count = 0;
        pool->queue_size = queue_size;
        pool->head = pool->tail = pool->count = pool->shutdown = pool->started = 0;
        pool->threads = (pthread_t *)malloc(sizeof(pthread_t)* thread_count);
        pool->queue = (threadpool_task_t *)malloc(sizeof(threadpool_task_t) * queue_size);
        
        if((pthread_mutex_init(&(pool->lock),NULL)!=0) || (pthread_cond_init(&(pool->notify),NULL)!=0) || (pool->threads==NULL)||(pool->queue == NULL)){ break; }
    }while()
}

int main(){
    for(char i = 0; i < 256; ++i) 
        printf("%d\n", i);

    return 0;
}
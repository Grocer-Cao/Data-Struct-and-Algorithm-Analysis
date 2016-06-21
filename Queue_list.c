#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
    队列功能
    InitQueue(*Q):初始化操作，建立一个空队列Q。
    QueueEmpty(*Q):若队列Q为空，返回true,否则返回false。
    EnQueue(*Q,e):若队列Q存在，插入新元素e到队列Q中并成为队尾元素。
    DeQueue(*Q,*e):删除队列Q中对头元素，并用e返回其值。
    GetHead(*Q,*e):若队列Q存在且非空，用e返回队列Q的对头元素。
    QueueLength(*Q):返回队列Q的元素个数。
    ClearQueue(*Q):将队列Q清空。
    DestroyQueue(*Q):若队列Q存在，则销毁它。
 */

//链式存储的C代码实现
typedef struct Queue
{
    int data;
    struct Queue* next;
}queue;

typedef struct QueuePtr
{
    struct Queue* front;
    struct Queue* rear;
    int length;
}queueptr;


queueptr* InitQueue()
{
    queueptr* temp = malloc(sizeof(queueptr));
    temp->front = temp->rear = NULL;
    temp->length = 0;
    return temp;
}

bool QueueEmpty(queueptr* Q)
{
    if(Q!=NULL && Q->length == 0)
        return true;
    else if(Q!=NULL)
        return false;
    else
    {
        printf("\nQueue is NULL\n");
        return false;
    }
}

int EnQueue(queueptr* Q,int e)
{
    if(Q!=NULL)
    {
        queue* temp = malloc(sizeof(queue));
        temp->data = e;

        if(Q->front==NULL&&Q->rear==NULL)
        {
            Q->front = Q->rear = temp;
        }
        else
        {
            Q->rear->next = temp;
            Q->rear = temp;
        }

        Q->length++;

        return 0;
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int DeQueue(queueptr* Q,int* e)
{
    if(Q!=NULL)
    {
        if(QueueEmpty(Q))
        {
            printf("\nQueue is Empty\n");
            return -1;
        }
        else
        {

            queue* temp;
            temp = Q->front;
            *e = temp->data;

            if(Q->length == 1)
            {
                Q->front = Q->rear = NULL;
            }
            else
            {
                Q->front = temp->next;
            }

            Q->length--;
            free(temp);

            return 0;
        }
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int GetHead(queueptr* Q,int* e)
{
    if(Q!=NULL)
    {
        if(QueueEmpty(Q))
        {
            printf("\nQueue is Empty\n");
            return -1;
        }
        else
        {
            *e = Q->front->data;
            return 0;
        }
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int QueueLength(queueptr* Q)
{
    if(Q!=NULL)
    {
        return Q->length;
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int ClearQueue(queueptr* Q)
{
    if(Q!=NULL)
    {
        int temp;
        while(Q->length!=0)
        {
            DeQueue(Q,&temp);
        }
        return 0;
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

queueptr* DestroyQueue(queueptr* Q)
{
    if(Q!=NULL)
    {
        ClearQueue(Q);
        free(Q);
    }
    return NULL;
}

/**
 *MAIN函数
 */
int main()
{
    //初始化操作，建立一个队列
    queueptr* testqueue = NULL;
    testqueue = InitQueue();

    //判断队列是否为空
    QueueEmpty(testqueue)?printf("True\n"):printf("False\n");
    printf("\n");

    //数据进入队列
    int i;
    for(i=0;i<15;i++)
    {
        EnQueue(testqueue,i);
    }
    QueueEmpty(testqueue)?printf("True\n"):printf("False\n");
    printf("\n");

    //数据退出队列
    int temp;
    for(i=0;i<10;i++)
    {
        if(DeQueue(testqueue,&temp)>-1)
            printf("%d ",temp);
    }
    QueueEmpty(testqueue)?printf("\nTrue\n"):printf("\nFalse\n");
    printf("\n");

    //数据进入队列
    for(i=0;i<15;i++)
    {
        EnQueue(testqueue,i);
    }
    QueueEmpty(testqueue)?printf("True\n"):printf("False\n");
    printf("\n");

    //数据退出队列
    for(i=0;i<17;i++)
    {
        if(DeQueue(testqueue,&temp)>-1)
            printf("%d ",temp);
    }
    QueueEmpty(testqueue)?printf("\nTrue\n"):printf("\nFalse\n");
    printf("\n");

    //获取队首数据
    GetHead(testqueue,&temp);
    printf("%d\n\n",temp);

    //获取队列长度
    int len;
    len = QueueLength(testqueue);
    printf("%d\n\n",len);

    //清除一个队列
    ClearQueue(testqueue);
    len = QueueLength(testqueue);
    printf("%d\n\n",len);

    //销毁一个队列
    testqueue = DestroyQueue(testqueue);
    len = QueueLength(testqueue);
    printf("%d\n\n",len);

    return 0;
}


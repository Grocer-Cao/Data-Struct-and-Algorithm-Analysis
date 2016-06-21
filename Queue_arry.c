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

//顺序循环存储的C代码实现
#define QueueSize 20
typedef struct Queue
{
    int data[QueueSize];
    int* front;
    int* rear;
    int flag;
}queue;

queue* InitQueue()
{
    queue* temp = malloc(sizeof(queue));
    temp->front = temp->rear = &(temp->data[0]);
    temp->flag = 0;
    return temp;
}

bool QueueEmpty(queue* Q)
{
    if(Q!=NULL && Q->front==Q->rear && Q->flag==0)
        return true;
    else if(Q!=NULL)
        return false;
    else
    {
        printf("\nQueue is NULL\n");
        return false;
    }
}

bool QueueFull(queue* Q)
{
    if(Q!=NULL && Q->front==Q->rear && Q->flag==1)
        return true;
    else if(Q!=NULL)
        return false;
    else
    {
        printf("\nQueue is NULL\n");
        return false;
    }
}

int EnQueue(queue* Q,int e)
{
    if(Q!=NULL)
    {
        if(QueueFull(Q))
        {
            printf("\nQueue is Full\n");
            return -1;
        }
        else
        {
            *(Q->rear) = e;
            if(Q->rear == &(Q->data[QueueSize-1]))
            {
                Q->rear = &(Q->data[0]);
                Q->flag = 1;
            }
            else
            {
                Q->rear++;
            }
            return 0;
        }
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int DeQueue(queue* Q,int* e)
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
            *e = *(Q->front);
            if(Q->front == &(Q->data[QueueSize-1]))
            {
                Q->front = &(Q->data[0]);
                Q->flag = 0;
            }
            else
            {
                Q->front++;
            }
            return 0;
        }
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int GetHead(queue* Q,int* e)
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
            *e = *(Q->front);
            return 0;
        }
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int QueueLength(queue* Q)
{
    if(Q!=NULL)
    {
        if(Q->rear!=Q->front)
            return (Q->rear-Q->front+QueueSize)%QueueSize;
        else if(Q->rear==Q->front&&Q->flag==1)
            return QueueSize;
        else if(Q->rear==Q->front&&Q->flag==0)
            return 0;
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

int ClearQueue(queue* Q)
{
    if(Q!=NULL)
    {
        Q->front = Q->rear = &(Q->data[0]);
        Q->flag = 0;
    }
    else
    {
        printf("\nQueue is NULL\n");
        return -1;
    }
}

queue* DestroyQueue(queue* Q)
{
    free(Q);
    return NULL;
}

/**
 *MAIN函数
 */
int main()
{
    //初始化操作，建立一个队列
    queue* testqueue = NULL;
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
        DeQueue(testqueue,&temp);
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
        DeQueue(testqueue,&temp);
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

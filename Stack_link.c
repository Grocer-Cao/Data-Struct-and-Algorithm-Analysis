#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
    栈功能
    InitStack(*S):初始化操作，建立一个空栈S。
    StackEmpty(*S):若栈为空返回true，否则返回false。
    Push(*S,e):若栈S存在，插入新元素e到栈S中并成为栈顶元素。
    Pop(*S,*e):删除栈S中栈顶元素，并用e返回其值。
    GetTop(*S,*e):若栈存在且非空，用e返回S的栈顶元素。
    StackLength(*S):返回栈S的元素个数。
    ClearStack(*S):将栈清空。
    DestroyStack(*S):若栈存在，销毁这个栈。
 */

//链表存储的C代码实现
typedef struct StackNode
{
    int data;
    struct StackNode* next;
}stack;
typedef struct StackTopPtr
{
    stack* top;
    int length;
}topptr;

topptr* InitStack()
{
    topptr* temp;
    temp = malloc(sizeof(topptr));

    if(temp!=NULL)
    {
        temp->length = 0;
        temp->top = NULL;
        return temp;
    }
    else
    {
        printf("Init Stack Error\n");
        return NULL;
    }
}

bool StackEmpty(topptr* S)
{
    if(S!=NULL&&S->length>0)
        return false;
    else if(S!=NULL&&S->length==0)
        return true;
    else
    {
        printf("Stack Empty Error, Stack is NULL\n");
        return false;
    }
}

int Push(topptr* S,int e)
{
    if(S!=NULL)
    {
        stack* temp;
        temp = malloc(sizeof(stack));
        temp->data = e;
        temp->next = S->top;
        S->top = temp;
        S->length++;
        return 0;
    }
    else
    {
        printf("Push Error, Stack is NULL\n");
        return -1;
    }
}

int Pop(topptr* S,int* e)
{
    if(S!=NULL&&S->length>0)
    {
        stack* temp;
        temp = S->top;
        S->top = temp->next;
        S->length--;

        *e = temp->data;
        free(temp);
        return 0;
    }
    else if(S!=NULL&&S->length==0)
    {
        printf("Pop Error, Stack is Empty\n");
        return -1;
    }
    else
    {
        printf("Pop Error, Stack is NULL\n");
        return -1;
    }
}

int GetTop(topptr* S,int* e)
{
    if(S!=NULL&&S->length>0)
    {
        *e = S->top->data;
        return 0;
    }
    else if(S!=NULL&&S->length==0)
    {
        printf("Get Top Error, Stack is Empty\n");
        return -1;
    }
    else
    {
        printf("Get Top Error, Stack is NULL\n");
        return -1;
    }
}

int StackLength(topptr* S)
{
    if(S!=NULL)
    {
        return S->length;
    }
    else
    {
        printf("Stack is NULL\n");
        return -1;
    }
}

int ClearStack(topptr* S)
{
    if(S!=NULL)
    {
        int temp;
        while(S->length>0)
        {
            Pop(S,&temp);
        }
        return 0;
    }
    else
    {
        printf("Clear Stack Error, Stack is NULL\n");
        return -1;
    }
}

topptr* DestroyStack(topptr* S)
{
    if(S!=NULL)
    {
        ClearStack(S);
        free(S);
    }
    return NULL;
}

/**
 *MAIN函数
 */
int main()
{
    //初始化操作，建立一个栈
    topptr* teststack;
    teststack = InitStack();

    //判断栈是否为空
    StackEmpty(teststack)?printf("True\n"):printf("False\n");
    printf("\n");

    //数据入栈
    int i;
    for(i=0;i<5;i++)
    {
        Push(teststack,i);
    }
    StackEmpty(teststack)?printf("True\n"):printf("False\n");
    printf("\n");

    //数据出栈
    int temp;
    for(i=0;i<3;i++)
    {
        Pop(teststack,&temp);
        printf("%d ",temp);
    }
    StackEmpty(teststack)?printf("\nTrue\n"):printf("\nFalse\n");
    printf("\n");

    //获取栈顶数据
    GetTop(teststack,&temp);
    printf("%d\n\n",temp);

    //获得栈的长度
    int len;
    len = StackLength(teststack);
    printf("%d\n\n",len);

    //清除栈内的数据
    ClearStack(teststack);
    StackEmpty(teststack)?printf("True\n"):printf("False\n");
    len = StackLength(teststack);
    printf("%d\n\n",len);

    //销毁一个栈
    teststack = DestroyStack(teststack);
    StackLength(teststack);

    return 0;
}

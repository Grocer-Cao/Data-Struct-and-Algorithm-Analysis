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

//顺序存储的C代码实现
#define StackSize 20
typedef struct Stack
{
    int data[StackSize];
    int top;
}stack;

stack* InitStack()
{
    stack* S = malloc(sizeof(stack));
    S->top = -1;
    return S;
}

bool StackEmpty(stack* S)
{
    if(S!=NULL&&S->top>-1)
        return false;
    else if(S!=NULL&&S->top==-1)
        return true;
    else
    {
        printf("Stack Empty Error, Stack is NULL\n");
        return false;
    }
}

int Push(stack* S,int e)
{
    if(S!=NULL&&S->top!=StackSize-1)
    {
        S->data[S->top+1] = e;
        S->top++;
        return 0;
    }
    else
    {
        printf("Push Error\n");
        return -1;
    }
}

int Pop(stack* S,int* e)
{
    if(S!=NULL&&S->top!=-1)
    {
        *e = S->data[S->top];
        S->top--;
        return 0;
    }
    else
    {
        printf("Pop Error\n");
        return -1;
    }
}

int GetTop(stack* S,int* e)
{
    if(S!=NULL&&S->top!=-1)
    {
        *e = S->data[S->top];
        return 0;
    }
    else
    {
        printf("GetTop Error\n");
        return -1;
    }
}

int StackLength(stack* S)
{
    if(S!=NULL&&S->top>-2)
    {
        return S->top+1;
    }
    else
    {
        printf("Stack is NULL\n");
        return -1;
    }
}

int ClearStack(stack* S)
{
    if(S!=NULL)
    {
        S->top = -1;
        return 0;
    }
    else
    {
        printf("Clear Stack Error, Stack is NULL\n");
        return -1;
    }
}

stack* DestroyStack(stack* S)
{
    free(S);
    return NULL;
}


/**
 *MAIN函数
 */
int main()
{
    //初始化操作，建立一个栈
    stack* teststack;
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

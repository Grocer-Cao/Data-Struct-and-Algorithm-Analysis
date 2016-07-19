#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define StackSize 100

typedef struct _stack
{
    int data[StackSize];
    int *top;
    int count;
}stack;

//入栈
int push(stack *ss, int num)
{
    if(ss->count<StackSize)
    {
        *(ss->top) = num;
        ss->top++;
        ss->count++;
        return 0;
    }
    else
    {
        printf("Push error, stack is full\n");
        return -1;
    }
}

//出栈
int pop(stack *ss)
{
    int num;
    if(ss->count>0)
    {
        ss->top--;
        num = *(ss->top);
        ss->count--;
        return num;
    }
    else
    {
        printf("Pop error, stack is empty\n");
        return -1;
    }
}

/**
 * RpnExpression
 * 逆波兰表达式算法，主要通过栈结构来实现
 * 输入样例(Input Exp):"9 3 1 - 3 * + 10 2 / +"
 * 输出样例(Output Exp):"20"
 * 输入样例(Input Exp):"9 3 1 - 3 * + 4 2 / +"
 * 输出样例(Output Exp):"17"
 */

int main()
{
    int i = 0;
    int ans = 0;
    int idata, temp1, temp2;

    char userdata[StackSize];
    memset(userdata,0,sizeof(userdata));

    //栈的初始化
    stack express;


    while(1)
    {
        express.top = &express.data[0];
        express.count = 0;
        i = 0;

        fgets(userdata,sizeof(userdata),stdin);

        while(i<StackSize)
        {
            if(userdata[i]>='0'&&userdata[i]<='9')
            {
                //入栈
                idata = atoi(&userdata[i]);
                push(&express,idata);

                //如果输入的数据大于10，则需要多后移几位
                while(idata>=10)
                {
                    i++;
                    idata /= 10;
                }

            }
            else if(userdata[i] == '\0')
            {
                //出栈，将结果存于ans中
                ans = pop(&express);
                break;
            }
            else if(userdata[i] == '+')
            {
                //出栈，运算，结果入栈
                temp1 = pop(&express);
                temp2 = pop(&express);
                temp2 += temp1;
                push(&express,temp2);
            }
            else if(userdata[i] == '-')
            {
                //出栈，运算，结果入栈
                temp1 = pop(&express);
                temp2 = pop(&express);
                temp2 -= temp1;
                push(&express,temp2);
            }
            else if(userdata[i] == '*')
            {
                //出栈，运算，结果入栈
                temp1 = pop(&express);
                temp2 = pop(&express);
                temp2 *= temp1;
                push(&express,temp2);
            }
            else if(userdata[i] == '/')
            {
                //出栈，运算，结果入栈
                temp1 = pop(&express);
                temp2 = pop(&express);
                temp2 /= temp1;
                push(&express,temp2);
            }
            else;

            i++;
        }

        printf("%d\n",ans);
    }

    return 0;
}

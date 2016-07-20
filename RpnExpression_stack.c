#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义栈容量大小
#define StackSize 100

//用于将中缀表达式转后缀表达式的栈
typedef struct _cstack
{
    char data[StackSize];
    char *top;
    int count;
}cstack;

//入栈操作
int cpush(cstack *css, char buffer)
{
    if(css->count<StackSize)
    {
        *(css->top) = buffer;
        css->top++;
        css->count++;
        return 0;
    }
    else
    {
        printf("Push error, stack is full\n");
        return -1;
    }
}

//出栈操作
char cpop(cstack *css)
{
    char buffer;
    if(css->count>0)
    {
        css->top--;
        buffer = *(css->top);
        css->count--;
        return buffer;
    }
    else
    {
        printf("Pop error, stack is empty\n");
        return -1;
    }
}

//用于计算的栈
typedef struct _stack
{
    int data[StackSize];
    int *top;
    int count;
}stack;

//入栈操作
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

//出栈操作
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

//中缀表达式转后缀表达式
int middToEnd(char* mid, char* end)
{
    int i = 0, j = 0;
    char ctemp1;

    //栈的初始化
    cstack cexpress;
    cexpress.top = &cexpress.data[0];
    cexpress.count = 0;

    while(i<StackSize)
    {
        if(mid[i]>='0' && mid[i]<='9')
        {
            end[j++] = mid[i];
            //将数据存入end数组中
            if (mid[i+1]<'0' || mid[i+1]>'9')
            {
                end[j++] = ' ';
            }


        }
        else if(mid[i]=='+' || mid[i]=='-')
        {
            //将遇到 ( 前的所有符号全部出栈，然后将 + - 入栈
            while(cexpress.count > 0)
            {
                ctemp1 = cpop(&cexpress);

                //若为 ( 则将它再入栈
                if (ctemp1 == '(')
                {
                    cpush(&cexpress,ctemp1);
                    break;
                }
                //依次出栈,在符号的后面加入空格
                else
                {
                    end[j++] = ctemp1;
                    end[j++] = ' ';
                }
            }
            cpush(&cexpress,mid[i]);
        }
        else if(mid[i]=='*' || mid[i]=='/' || mid[i]=='(')
        {
            //将 * / (入栈
            cpush(&cexpress,mid[i]);
        }
        else if(mid[i] == ')')
        {
            //将栈内最接近栈顶的 ( 及之前的所有元素出栈
            while(cexpress.count > 0)
            {
                ctemp1 = cpop(&cexpress);
                if (ctemp1 == '(')
                {
                    break;
                }
                end[j++] = ctemp1;
                end[j++] = ' ';
            }
        }
        else if(mid[i] == '\0')
        {
            //依次出栈,在符号的前后加入空格
            while(cexpress.count>0)
            {
                ctemp1 = cpop(&cexpress);
                end[j++] = ctemp1;
                end[j++] = ' ';
            }

            end[j++] = mid[i];
            break;
        }
        else;

        i++;
    }

}

//后缀表达式计算结果
int rpnCalculate(char* rpn)
{
    int i = 0;
    int idata, temp1, temp2;
    int ans = 0;

    stack express;
    express.top = &express.data[0];
    express.count = 0;

    while(i<StackSize)
    {
        if (rpn[i]>='0' && rpn[i]<='9')
        {
            //将数据入栈
            idata = atoi(&rpn[i]);
            push(&express, idata);

            //如果数据大于10，则需要多后移几位
            while(idata>=10)
            {
                i++;
                idata /= 10;
            }
        }
        else if (rpn[i] == '+')
        {
            //出栈，运算，存入结果
            temp1 = pop(&express);
            temp2 = pop(&express);
            temp2 += temp1;
            push(&express,temp2);
        }
        else if (rpn[i] == '-')
        {
            //出栈，运算，存入结果
            temp1 = pop(&express);
            temp2 = pop(&express);
            temp2 -= temp1;
            push(&express,temp2);
        }
        else if (rpn[i] == '*')
        {
            //出栈，运算，存入结果
            temp1 = pop(&express);
            temp2 = pop(&express);
            temp2 *= temp1;
            push(&express,temp2);
        }
        else if (rpn[i] == '/')
        {
            //出栈，运算，存入结果
            temp1 = pop(&express);
            temp2 = pop(&express);
            temp2 /= temp1;
            push(&express,temp2);
        }
        else if (rpn[i] == '\0')
        {
            //出栈，将结果存于ans中
            ans = pop(&express);
            break;
        }

        i++;
    }


    return ans;
}
/**
 * RpnExpression
 * 逆波兰表达式算法，主要通过栈结构来实现
 *
 * 符号优先级：乘除高于加减，左右括号相匹配不与四则运算符比较优先级
 *
 * 输入样例(Input Exp):"9+(3-1)*3+10/2"
 * 后缀表达式:"9 3 1 - 3 * + 10 2 / + "
 * 输出样例(Output Exp):"20"
 *
 * 输入样例(Input Exp):"9+(3-1)*3+4/2"
 * 后缀表达式:"9 3 1 - 3 * + 4 2 / + "
 * 输出样例(Output Exp):"17"
 */
int main()
{
    int ans = 0;

    char cuserdata[StackSize];
    char userdata[StackSize];
    memset(cuserdata,0,sizeof(cuserdata));
    memset(userdata,0,sizeof(userdata));

    while(1)
    {
        fgets(cuserdata,sizeof(cuserdata),stdin);

        //中缀表达式转后缀表达式
        middToEnd(cuserdata, userdata);

        //后缀表达式计算结果
        ans = rpnCalculate(userdata);
        printf("%d\n",ans);
    }
    return 0;
}

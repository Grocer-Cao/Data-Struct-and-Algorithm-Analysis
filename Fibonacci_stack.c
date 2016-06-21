#include <stdio.h>
#include <stdlib.h>

//通过循环方式实现
/*
int Fibonacci(int num)
{
    if(num>0)
    {
        int a = 0;
        int b = 1;
        int c = 1;
        while(num-1)
        {
            c = b+a;
            a = b;
            b = c;
            num--;
        }
        return c;
    }
    else
    {
        return 0;
    }
}
*/

//通过递归方式实现

int Fibonacci(int num)
{
    if(0<num&&num<3)
    {
        return 1;
    }
    return Fibonacci(num-1)+Fibonacci(num-2);
}


int main()
{
    int i;
    for(i=1;i<40;i++)
    {
        printf("%d ",Fibonacci(i));
    }

    return 0;
}

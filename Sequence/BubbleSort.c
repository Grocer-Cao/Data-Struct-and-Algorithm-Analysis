#include <stdio.h>
#include <stdlib.h>

void bubble(int* arry, int size)
{
    if(arry!=NULL)
    {
        int i, j;
        int temp;

        //标准冒泡法
        for(i=0;i<size-1;i++)
        {
            for(j=size-1;j>i;j--)
            {
                if(arry[j]<arry[j-1])
                {
                    arry[j-1] += arry[j];
                    arry[j] = arry[j-1] - arry[j];
                    arry[j-1] -= arry[j];
                }
            }
        }
//
        //标准下沉法
//        for(i=size-1;i>0;i--)
//        {
//            for(j=0;j<i;j++)
//            {
//                if(arry[j]>arry[j+1])
//                {
//                    arry[j+1] += arry[j];
//                    arry[j] = arry[j+1] - arry[j];
//                    arry[j+1] -= arry[j];
//                }
//            }
//        }
    }
}

void prt_array(int* arry, int size)
{
    if(arry!=NULL)
    {
        int temp = 0;
        while(temp<size-1)
        {
            printf("%d,",arry[temp++]);
        }
        printf("%d\n",arry[temp]);
    }
}

int main()
{
    int num[11] = {10,8,2,4,3,7,6,5,0,9,1};
    prt_array(num,sizeof(num)/sizeof(int));
    bubble(num, sizeof(num)/sizeof(int));
    prt_array(num,sizeof(num)/sizeof(int));
    return 0;
}

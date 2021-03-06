#include <stdio.h>
#include <stdlib.h>

//int * num_addr;

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

void quickSort(int* arry, int size)
{
    if(arry == NULL)
        return;



    if(size>2)
    {
        int i=1, j=size-1;
        while(i<j)
        {
            while(i<=j && arry[j]>arry[0])
            {
                j--;
            }
            while(i<=j && arry[i]<=arry[0])
            {
                i++;
            }

            if(i<j)
            {
                arry[i] += arry[j];
                arry[j] = arry[i] - arry[j];
                arry[i] -= arry[j];
            }
        }

        if(j>0)
        {
            arry[0] += arry[j];
            arry[j] = arry[0] - arry[j];
            arry[0] -= arry[j];
        }


//        printf("i = %d\t j = %d\t size = %d\n",i,j,size);
//        prt_array(num_addr,11);
//        printf("\n");

        quickSort(&(arry[0]),j);
        quickSort(&(arry[i]),size-i);

    }
    else if(size == 2)
    {
        if (arry[0]>arry[1])
        {
            arry[0] += arry[1];
            arry[1] = arry[0] - arry[1];
            arry[0] -= arry[1];
        }
    }
    else;
}

//参考：http://www.cnblogs.com/luchen927/archive/2012/02/29/2368070.html
int quicksort_1 (int* v, int left, int right)
{
        if(left < right){
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && v[high] > key){
                                high--;
                        }
                        v[low] = v[high];
                        while(low < high && v[low] <= key){
                                low++;
                        }
                        v[high] = v[low];
                }
                v[low] = key;
                quicksort_1(v,left,low-1);
                quicksort_1(v,low+1,right);
        }
        return 0;
}


int main()
{
    int num[11] = {10,8,2,4,3,7,6,5,0,9,1};
    //int num[11] = {0,1,2,3,4,5,6,7,8,9,10};
    //int num[11] = {10,9,8,7,6,5,4,3,2,1,0};
    //int num[11] = {10,8,2,4,2,7,5,5,0,9,1};
    //int num[11] = {2,2,2,2,2,2,2,2,2,2,2};
    //int num[11] = {10,8,-2,3,3,-7,6,2555,0,9,11};

    //num_addr = num;

    prt_array(num,sizeof(num)/sizeof(int));

    //quickSort(num, sizeof(num)/sizeof(int));
    quicksort_1(num,0,11);

    prt_array(num,sizeof(num)/sizeof(int));
    return 0;
}

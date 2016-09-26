#include <stdio.h>
#include <stdlib.h>

//非递归方式实现
int binarySearch(int* arry, int low, int high, int target)
{
    int mid = (low+high)/2;

    while(low<=high)
    {
        if(arry[mid]>target)
            high = mid-1;
        else if(arry[mid]<target)
            low = mid+1;
        else
            return mid;

        mid = (low+high)/2;
    }

    return -1;
}

//递归方式实现
int binSrhRecursion(int* arry, int low, int high, int target)
{
    if(low<=high)
    {
        int mid = (low+high)/2;

        if(arry[mid]>target)
            return binSrhRecursion(arry, low, mid-1, target);
        else if(arry[mid]<target)
            return binSrhRecursion(arry, mid+1, high, target);
        else
            return mid;
    }

    else
        return -1;
}

int main()
{
    int num[10] = {0,2,4,6,8,10,12,14,16,18};
    int want_num = 4;
    int pos = -1;

    //pos = binarySearch(num, 0, 10,want_num);
    pos = binSrhRecursion(num, 0, 10,want_num);

    printf("%d\n",pos);

    return 0;
}

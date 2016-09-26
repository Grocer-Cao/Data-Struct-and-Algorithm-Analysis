#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arry, int size, int target)
{
    int srt=0, end=size-1;
    int mid = (srt+end)/2;

    while(srt<end-1)
    {
        if(arry[mid]>target)
        {
            end = mid;
        }
        else if(arry[mid]<target)
        {
            srt = mid;
        }
        else
        {
            return mid;
        }
        mid = (srt+end)/2;
    }

    if(arry[srt]==target)
        return srt;
    else if(arry[end]==target)
        return end;
    else
        return -1;
}

int main()
{
    int num[10] = {0,2,4,6,8,10,12,14,16,18};
    int want_num = 9;
    int pos = -1;

    pos = binarySearch(num, sizeof(num)/sizeof(int),want_num);

    printf("%d\n",pos);

    return 0;
}

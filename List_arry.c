#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
    线性链表功能
    InitList(*L): 初始化操作，建立一个空的线性表
    ListEmpty(L): 若表为空，返回True，否则返回False
    ClearList(*L): 将线性表清空
    GetElem(L,i,*e): 将线性表L中第i个位置元素返回给e。
    LocateElem(L,e): 在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中的序号，
                     否则，返回0表示失败。
    ListInsert(*L,i,e): 在线性表的第i个位置插入新元素e。
    ListDelete(*L,i,*e): 删除线性表L中第i个位置元素，并用e返回其值。
    ListLength(L): 返回线性表L的元素个数。
 */


//顺序存储的C代码实现
typedef struct List
{
    int data[40];
    int length;
}list;

list* InitList(list* L)
{
    L = malloc(sizeof(list));
    L->length = 0;
    return L;
}

bool ListEmpty(list *L)
{
    if(L!=NULL&&L->length==0)
        return true;
    else
        return false;
}

int ClearList(list *L)
{
    if(L!=NULL)
    {
        L->length = 0;
        return 0;
    }
    else
        return -1;
}

int GetElem(list *L,int i,int *e)
{
    if((L!=NULL) && (i>0) && (i<=L->length))
    {
        *e = L->data[i-1];
        return 0;
    }
    else
    {
        *e = -1;
        return -1;
    }
}

int LocateElem(list *L,int e)
{
    if(L!=NULL)
    {
        int count;
        for(count=0;count<L->length;count++)
        {
            if(L->data[count] == e)
            {
                return count+1;
            }
        }
        return 0;
    }
    else
        return -1;
}

int ListInsert(list *L,int i,int e)
{
    if((L!=NULL)&&(i>0)&&(i<=L->length+1))
    {
        int count;
        for(count=L->length-1;count>=i-1;count--)
        {
            L->data[count+1] = L->data[count];
        }
        L->data[i-1] = e;
        L->length = L->length + 1;

        return 0;
    }
    else
        return -1;
}

int ListDelete(list* L,int i,int *e)
{
    if((L!=NULL)&&(i>0)&&(i<=L->length))
    {
        *e = L->data[i-1];
        int count;
        for(count=i-1;count<L->length-1;count++)
        {
            L->data[count] = L->data[count+1];
        }
        L->length = L->length - 1;
        return 0;
    }
    else
    {
        *e = -1;
        return -1;
    }
}

int ListLength(list* L)
{
    if(L!=NULL)
        return L->length;
    else
        return -1;
}

/**
 *MAIN函数
 */
int main()
{
    //初始化操作，建立一个线性表
    list* testlist;
    testlist = InitList(testlist);


    //判断线性表是否为空
    ListEmpty(testlist)?printf("True\n"):printf("False\n");
    int i;
    for(i=0;i<20;i++)
    {
        testlist->data[i] = i;
        testlist->length++;
    }
    ListEmpty(testlist)?printf("True\n"):printf("False\n");
    printf("\n");



    //获取线性表中某位置的值
    int a=0;
    GetElem(testlist,8,&a);
    printf("%d\n\n",a);


    //查找线性表中是否含有某个值
    int pos=0;
    pos = LocateElem(testlist,19);
    printf("%d\n\n",pos);


    //线性表中某个位置插入一个元素
    GetElem(testlist,21,&a);
    printf("%d\n",a);
    ListInsert(testlist,5,100);
    GetElem(testlist,5,&a);
    printf("%d\n",a);
    GetElem(testlist,21,&a);
    printf("%d\n\n",a);


    //线性表中删除某个位置的一个元素
    GetElem(testlist,5,&a);
    printf("%d\n",a);
    ListDelete(testlist,5,&a);
    printf("%d\n",a);
    GetElem(testlist,5,&a);
    printf("%d\n\n",a);


    //清除一个线性表
    ClearList(testlist);
    ListEmpty(testlist)?printf("True\n"):printf("False\n");
    printf("\n");


    //获取线性表长度
    int len=0;
    len = ListLength(testlist);
    printf("%d\n",len);


    return 0;
}

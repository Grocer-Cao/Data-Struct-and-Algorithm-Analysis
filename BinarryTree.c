#include <stdio.h>
#include <stdlib.h>

//使用的是较常用的孩子表示法。
typedef struct _bintree
{
    char data;
    struct _bintree* Lch;
    struct _bintree* Rch;
}bintree;

//创建一个用户定义的二叉树
/*
        A
    B        C
  #  D      #  #
    # #
  用户需要按前序遍历的顺序输入AB#D##C##
  其中#代表空指针
*/
int CreateTree(bintree** T)
{
    char ch;
    scanf("%c",&ch);
    if(ch == '#')
        *T = NULL;
    else
    {
        *T = malloc(sizeof(bintree));
        (*T)->data = ch;
        CreateTree(&((*T)->Lch));
        CreateTree(&((*T)->Rch));
    }
    return 0;
}

int ClearTree(bintree** T)
{
    if(*T!=NULL)
    {
        ClearTree(&((*T)->Lch));
        ClearTree(&((*T)->Rch));
        free(*T);
        *T = NULL;
    }
    return 0;
}

//前序遍历
void Front(bintree* T)
{
    if(T!=NULL)
    {
        printf("%c ",T->data);
        Front(T->Lch);
        Front(T->Rch);
    }
    else;
}

//中序遍历
void Middle(bintree* T)
{
    if(T!=NULL)
    {
        Middle(T->Lch);
        printf("%c ",T->data);
        Middle(T->Rch);
    }
    else;
}

//后序遍历
void End(bintree* T)
{
    if(T!=NULL)
    {
        End(T->Lch);
        End(T->Rch);
        printf("%c ",T->data);
    }
    else;
}

/**
 *二叉树
 *CreateTree(*T,buf,*L,*R)
 *CreateTree(*T,def)
 */
int main()
{
    //构造空树T
    bintree* bTree = NULL;

    CreateTree(&bTree);

    printf("前序遍历结果：");
    Front(bTree);
    printf("\n");

    printf("中序遍历结果：");
    Middle(bTree);
    printf("\n");

    printf("后序遍历结果：");
    End(bTree);
    printf("\n");

    ClearTree(&bTree);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//使用的是较常用的孩子表示法。
typedef struct _binarytree
{
    char data;
    struct _btree* Lch;
    struct _btree* Rch;
}binarytree;

//创建一个用户定义的二叉树
/*
        A
    B        C
  #  D      #  #
    # #
  用户需要按前序遍历的顺序输入AB#D##C##
  其中#代表空指针
*/
void Createtree(binarytree** T)
{
    char ch;
    scanf("%c",&ch);

    if(ch == '#')
        *T = NULL;
    else
    {
        *T = malloc(sizeof(binarytree));
        (*T)->data = ch;
        Createtree(&((*T)->Lch));
        Createtree(&((*T)->Rch));
    }
}

void ClearTree(binarytree** T)
{
    if(*T!=NULL)
    {
        ClearTree(&((*T)->Lch));
        ClearTree(&((*T)->Rch));
        free(*T);
        *T = NULL;
    }
}

//前序遍历
void Preorder(binarytree* T)
{
    if(T!=NULL)
    {
        printf("%c ",T->data);
        Preorder(T->Lch);
        Preorder(T->Rch);
    }
}

//中序遍历
void Inorder(binarytree* T)
{
    if(T!=NULL)
    {
        Inorder(T->Lch);
        printf("%c ",T->data);
        Inorder(T->Rch);
    }
}

//后序遍历
void Postorder(binarytree* T)
{
    if(T!=NULL)
    {
        Postorder(T->Lch);
        Postorder(T->Rch);
        printf("%c ",T->data);
    }
}

/**
 *二叉树
 */
int main()
{
    //构造空树T
    binarytree* btree = NULL;

    Createtree(&btree);

    printf("前序遍历结果：");
    Preorder(btree);
    printf("\n");

    printf("中序遍历结果：");
    Inorder(btree);
    printf("\n");

    printf("后序遍历结果：");
    Postorder(btree);
    printf("\n");

    ClearTree(&btree);

    return 0;
}

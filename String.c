#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

/**
    字符串的功能
    StrLength(S):返回串S的元素个数，即串的长度。
    StringEmpty(S):若串S为空，返回true，否则返回false。
    ClearString(S):串S存在，将串清空。
    StrAssign(T,*chars):生成一个其值等于字符串常量chars的串T。
    StrCopy(T,S):串S存在，由串S复制得到串T。
    StrCompare(S,T):若S>T，返回1，若S=T，返回0，若S<T，返回-1。
    Concat(T,S1,S2):用T返回由S1和S2连接而成的新串。
    SubString(Sub,S,pos,len):串S存在，1<=pos<=StrLength(S)，且0<=len<=StrLength(S)-pos+1，用Sub返回
                             串S的第pos个字符起长度为len的子串。
    StrInsert(S,pos,T):串S和T存在，1<=pos<=StrLength(S)+1。在串S的第pos个字符之前插入串T。
    StrDelete(S,pos,len):串S存在，1<=pos<=StrLength(S)-len+1。从串S中删除第pos个字符起长度为len的子串。

    TODO:
    Index(S,T,pos):串S和T存在，T是非空串，1<=pos<=StrLength(S)，若主串S中存在和串T值相同的子串，则
                   返回它在主串中第pos个字符之后第一次出现的位置，否则返回0。
    Replace(S,T,V):串S、T和V存在，T是非空串。用V替换主串S中出现的所有与T相等的不重叠子串。
 */
int StrLength(char* S)
{
    int count = 0;
    while(S[count]!='\0')
    {
        count++;
    }
    return count;
}

bool StringEmpty(char* S)
{
    if(S[0] == '\0')
        return true;
    else
        return false;
}

int CleanString(char* S)
{
    //简单方式
    //S[0] = '\0';

    //全清空方式
    int len = StrLength(S);
    while(len>0)
    {
        S[len-1] = '\0';
        len--;
    }

    return 0;
}

//T在外部需要被手动释放
char* StrAssign(char* T,const char* chars)
{
    char* temp = NULL;
    int size = StrLength(chars)+1;
    temp = malloc(size);
    if(temp!=NULL)
    {
        T = temp;
        //从尾至头复制chars中内容到T中
        while(size>0)
        {
            T[size-1] = chars[size-1];
            size--;
        }
        return T;
    }
    else
    {
        printf("Malloc Error\n");
        return NULL;
    }
}

int StrCopy(char* T,char* S)
{
    int len = StrLength(S)+1;
    while(len>0)
    {
        T[len-1] = S[len-1];
        len--;
    }
    return 0;
}

int StrCompare(char* S,char* T)
{
    int count = 0;
    int flag = 0;
    while(S[count]!='\0'&&T[count]!='\0')
    {
        if(S[count]>T[count])
        {
            flag = 1;
            break;
        }
        else if(S[count]<T[count])
        {
            flag = -1;
            break;
        }
        else
            count++;
    }

    if(S[count]=='\0'&&T[count]=='\0')
    {
        flag = 0;
    }
    else if(S[count]=='\0')
    {
        flag = -1;
    }
    else if(T[count]=='\0')
    {
        flag = 1;
    }
    else;

    return flag;
}

int Concat(char* T,char* S1,char* S2)
{
    int s1_len = StrLength(S1);
    StrCopy(T,S1);
    StrCopy(&T[s1_len],S2);
    return 0;
}

int SubString(char* Sub,char* S,int pos,int len)
{
    int count = 0;
    while(count<len)
    {
        Sub[count] = S[pos-1+count];
        count++;
    }
    Sub[len] = '\0';
    return 0;
}

int StrInsert(char* S,int pos,char* T)
{
    //GCC允许数组个数为变量，但如果是C89标准就不支持了
    int size = StrLength(S)-pos+2;
    char temp[size];
    StrCopy(temp,&S[pos-1]);

    S[pos-1] = '\0';

    Concat(S,S,T);
    Concat(S,S,temp);

    return 0;
}

int StrDelete(char* S,int pos,int len)
{
    int size = StrLength(S)-pos-len+2;
    char temp[size];
    StrCopy(temp,&S[pos+len-1]);

    S[pos-1] = '\0';

    Concat(S,S,temp);

    return 0;
}

int main()
{
    //获取字符串长度
    char test[20] = {"Hello CPH!"};
    printf("%s\n",test);
    printf("%d\n",StrLength(test));

    //判断字符串是否为空
    bool empty = false;
    empty = StringEmpty(test);
    printf("%s\n",empty==1?"true":"false");

    //清空字符串
    CleanString(test);
    empty = StringEmpty(test);
    printf("%s\n",empty==1?"true":"false");

    //生成一个与指定常量字符串相同的字符串
    char* test2;
    test2 = StrAssign(test2,"Linux Ubuntu 16.04");
    printf("%s\n",test2);
    free(test2);

    //复制一个串
    StrCopy(test,"ABC");
    printf("%s\n");

    //判断字符串大小
    char* a = "abcde";
    char* b = "abbbb";
    char* c = "abb";
    char* d = "abb";
    printf("%s\n",StrCompare(a,b)>0?"a>b":(StrCompare(a,b)<0?"a<b":"a=b"));
    printf("%s\n",StrCompare(b,c)>0?"b>c":(StrCompare(b,c)<0?"b<c":"b=c"));
    printf("%s\n",StrCompare(c,d)>0?"c>d":(StrCompare(c,d)<0?"c<d":"c=d"));

    //连接生成新串
    char* st1 = "China ";
    char* st2 = "America";
    char T[20];
    Concat(T,st1,st2);
    printf("%s\n",T);

    //获取一个子串
    char sub[20];
    char* st3 = "abcdefghijklmnopqrstuvwxyz";
    SubString(sub,st3,3,4);
    printf("%s\n",sub);

    //在指定位置插入一个字符串
    char aa[20] = {"Hello dear!"};
    char* bb = "my ";
    StrInsert(aa,7,bb);
    printf("%s\n",aa);

    //在指定位置删除一定长度的字符串
    char cc[30] = {"I don't like eat apple!"};
    StrDelete(cc,3,6);
    printf("%s\n",cc);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *KMP算法总结
 *1、求出next数组
 *2、利用next数组进行字符串查找
 */

//分析待匹配字符串T，求出next数组。
int getNext(char* T,int* next)
{
    int i;
    int j;
    next[0] = 0;
    next[1] = 1;
    
    //i在这里指的都是第T[i]个元素，即第i+1位
    i=2;
    //这里的j是T[j]个元素，（即第j+1位）
    j=0;

    while(i<strlen(T))
    {
        if(T[i-1]==T[j])
        {
            next[i] = j+2;
            i++;
            j++;
        }
        else if(j == 0)
        {
            next[i] = j+1;
            i++;
        }
        else
            j = next[j]-1;
    }

    return 0;
}

//返回值pst用于表示带查找字符串T位于S的第几位（从第一位开始计），若pst等于0则说明S中没有T字符串
int Index(char* S,char* T,int pos)
{
    int pst = 0;
    int i = pos - 1;
    int j = 0;

    int nxt[strlen(T)];
    getNext(T,nxt);

    while(i < strlen(S))
    {
    	if (S[i] == T[j])
    	{
    		j++;
    		i++;
    	}
    	else
    	{
    		if (j==0)
    		{
    			if (i<strlen(S)-strlen(T)+1)
    				i++;
    			else
    				break;
    		}
    		else
    			j = nxt[j] - 1;
    	}

    	if (j==strlen(T))
    	{
    		pst = i - j + 1;
    		break;
    	}
    }

    return pst;
}

int main()
{
    //char* st1 = "ababaaaba";
    //char* st1 = "aaaabxxxxaaaaaxxxxx";
    //char* st1 = "aabxxaaaxx";
    char* st1 = "abababxxxxababaaxxx";

    int num[strlen(st1)];
    getNext(st1,num);

    int i = 0;
    while(i<strlen(st1))
    {
        printf("%d ",num[i]);
        i++;
    }
    printf("\n");

    char* st2 = "abcabbccbacabaabcabbccbacaba";
    char* st3 = "abbc";

    int position = 0;
    position = Index(st2,st3,1);
    printf("position = %d\n",position);

    return 0;
}
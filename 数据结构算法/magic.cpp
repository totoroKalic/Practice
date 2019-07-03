#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define STACK_INIT_SIZE 100;
#define STACKINCREMENNT 10;

typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack, *Sq;                                 //构建一个栈类型的结构体 

int InitStack(SqStack &S)
{
	S.base = (char*)malloc(100 * sizeof(char));
	if (!S.base)
		exit(1);                                  //判断内存分配是否成功 
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}                                             //创建一个空栈 

int Push(SqStack &S, char e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (char *)realloc(S.base, (S.stacksize + 10)*sizeof(char));
		if (!S.base)
			return 0;                             // 判断内存分配是否成功 
		S.top = S.base + S.stacksize;
		S.stacksize += 10;
	}                                         //判断栈是否满了，满了的话再多分配空间 
	*S.top = e;
	S.top = S.top + 1;                         //元素插入栈顶 
	return 1;
}                                             //实现元素的入栈 

void Pop(SqStack &S, char *e)
{
	//char e;
	if (S.top != S.base)                       //判断栈是否为空栈了 
		//return 0;
	{
		--S.top;
		*e = *S.top;
	}
}                                              //删除栈顶元素并用e返回其值 

int main()
{
	char words[100];
	char words2[100];
	printf("请输入该魔法语言\n");
	gets(words);                               //输入魔法语言，并将其放入到words字符串数组里 
	//	puts(words);

	SqStack S;
	int a, b, num, nnm = 0, numt;
	char flag, demo;//=NULL;
	if (InitStack(S) == 1)
	{
		printf("顺序栈初始化成功\n");
	}
	num = strlen(words);                       //确定魔法语言的长度 
	//printf("%d",num);
	for (a = num; a>0; a--)
	{
		flag = words[a - 1];
		Push(S, flag);
		//int qqq = Push(S,flag);
		//printf("%d",qqq);
	}                                          //将魔法语言的数据从后往前压入栈里 
	//printf("ghg");
	//Pop(S,&demo); 
	nnm = 0;
	for (b = 0; b<num; b++)
	{
		//demo = 'a';
		Pop(S, &demo);                          //输出栈顶元素 
		//printf("%c",demo);
		if (demo == 'B')
		{
			printf("tsaedsae");
			//continue;
		}
		else if (demo == 'A')
		{
			printf("sae");
			//continue;
		}
		else if (demo == '(')
		{
			continue;
		}
		else
		{
			if (demo == ')')
			{
				numt = strlen(words2) - 1;
				//printf("%d",num_2);
				//puts(words2);
				for (a = numt; a >= 0; a--)
				{
					if (a == 0)
					{
						printf("%c", words2[0]);
						//putchar(words2[0]);
					}
					else
					{
						//printf("%s%s",words2[nnm],words2[a]);
						//putchar(words2[0]);
						//putchar(words2[a]);
						printf("%c", words2[0]); printf("%c", words2[a]);
					}
				}                                               // 将括号里的魔法语言换成相应的现实编码 
				nnm = 0;
				//continue;
			}
			else
			{
				words2[nnm++] = demo;                          // 如果是括号里的，将其输入到字符串words2里面 
				//nnm++;
				//continue;
			}
		}
	}
	printf("\n");
	return 0;
}















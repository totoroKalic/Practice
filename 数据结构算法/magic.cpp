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
}SqStack, *Sq;                                 //����һ��ջ���͵Ľṹ�� 

int InitStack(SqStack &S)
{
	S.base = (char*)malloc(100 * sizeof(char));
	if (!S.base)
		exit(1);                                  //�ж��ڴ�����Ƿ�ɹ� 
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}                                             //����һ����ջ 

int Push(SqStack &S, char e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (char *)realloc(S.base, (S.stacksize + 10)*sizeof(char));
		if (!S.base)
			return 0;                             // �ж��ڴ�����Ƿ�ɹ� 
		S.top = S.base + S.stacksize;
		S.stacksize += 10;
	}                                         //�ж�ջ�Ƿ����ˣ����˵Ļ��ٶ����ռ� 
	*S.top = e;
	S.top = S.top + 1;                         //Ԫ�ز���ջ�� 
	return 1;
}                                             //ʵ��Ԫ�ص���ջ 

void Pop(SqStack &S, char *e)
{
	//char e;
	if (S.top != S.base)                       //�ж�ջ�Ƿ�Ϊ��ջ�� 
		//return 0;
	{
		--S.top;
		*e = *S.top;
	}
}                                              //ɾ��ջ��Ԫ�ز���e������ֵ 

int main()
{
	char words[100];
	char words2[100];
	printf("�������ħ������\n");
	gets(words);                               //����ħ�����ԣ���������뵽words�ַ��������� 
	//	puts(words);

	SqStack S;
	int a, b, num, nnm = 0, numt;
	char flag, demo;//=NULL;
	if (InitStack(S) == 1)
	{
		printf("˳��ջ��ʼ���ɹ�\n");
	}
	num = strlen(words);                       //ȷ��ħ�����Եĳ��� 
	//printf("%d",num);
	for (a = num; a>0; a--)
	{
		flag = words[a - 1];
		Push(S, flag);
		//int qqq = Push(S,flag);
		//printf("%d",qqq);
	}                                          //��ħ�����Ե����ݴӺ���ǰѹ��ջ�� 
	//printf("ghg");
	//Pop(S,&demo); 
	nnm = 0;
	for (b = 0; b<num; b++)
	{
		//demo = 'a';
		Pop(S, &demo);                          //���ջ��Ԫ�� 
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
				}                                               // ���������ħ�����Ի�����Ӧ����ʵ���� 
				nnm = 0;
				//continue;
			}
			else
			{
				words2[nnm++] = demo;                          // �����������ģ��������뵽�ַ���words2���� 
				//nnm++;
				//continue;
			}
		}
	}
	printf("\n");
	return 0;
}















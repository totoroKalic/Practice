#pragma once
#include <stdio.h>
#include <stdlib.h>

//typedef struct LNode{
//int num,code;
//struct LNode *next;
//struct LNode *prior;
//}LNode,*LinkList;           //����һ��˫������Ľṹ��

typedef struct LNode{
    int num, code;
	struct LNode *next;
}LNode, *LinkList;           // ����һ����������

int main()
{
    int m, n, i, j;
	LinkList p, q, head, tail;
	printf("����������\n");
	scanf("%d", &n);
	printf("�������ϱ�����\n");
	scanf("%d", &m);
	head = (LinkList)malloc(sizeof(LNode));
	q = head;
	/*for(i=1;i<n;i++)
	{
	p = (LinkList)malloc(sizeof(LNode));
	q->next = p;
	p->prior = q;
	q = p;
	} */                       //��������������Ӧ��Ŀ�Ľڵ���Ŀ
	/*for (i = 1; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		q->next = p;
		q = p;
	}
	tail = p;
	tail->next = head;
	//head->prior = tail;      //�������β���� 

	printf("�밴˳������ÿ���˵�����\n");
	q = head;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &q->code);
		q->num = i;
		q = q->next;
	}                         //��һ��ѭ������ÿ���˵ı�ź���������ڵ����� 

	q = tail;                //��ǰһλ����ʼ��ʹ�ÿ�ʼʱ��һ��ʼ 
	/*for(i = 0; i < n; i++)   //�м����˾ͻ�ѭ������
	{
	for(j =0;j<m;j++)
	{
	q = q->next;
	}
	m = q->code;         //���µ����븳��m
	printf("%d ",q->num);
	q->prior->next = q->next;
	q->next->prior = q->prior;         //˫�������нڵ�p��ɾ��
	p = q;
	q = q->prior;
	free(p);                           //�ͷſռ�
	}*/
    /*for (i = 0; i < n; i++)   //�м����˾ͻ�ѭ������ 
	{
		for (j = 1; j<m; j++)
		{
			q = q->next;
		}
		p = q->next;
		m = p->code;                  //���µ����븳��m 
		printf("%d ", p->num);         //���������нڵ�p��ɾ�� 
		q->next = p->next;
		free(p);                      //�ͷſռ�
	}

	printf("\n");

	return 0;
}
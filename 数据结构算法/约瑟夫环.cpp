#pragma once
#include <stdio.h>
#include <stdlib.h>

//typedef struct LNode{
//int num,code;
//struct LNode *next;
//struct LNode *prior;
//}LNode,*LinkList;           //定义一个双向链表的结构体

typedef struct LNode{
    int num, code;
	struct LNode *next;
}LNode, *LinkList;           // 定义一个单向链表

int main()
{
    int m, n, i, j;
	LinkList p, q, head, tail;
	printf("请输入人数\n");
	scanf("%d", &n);
	printf("请输入上报上限\n");
	scanf("%d", &m);
	head = (LinkList)malloc(sizeof(LNode));
	q = head;
	/*for(i=1;i<n;i++)
	{
	p = (LinkList)malloc(sizeof(LNode));
	q->next = p;
	p->prior = q;
	q = p;
	} */                       //跟据人数分配相应数目的节点数目
	/*for (i = 1; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		q->next = p;
		q = p;
	}
	tail = p;
	tail->next = head;
	//head->prior = tail;      //链表的首尾相连 

	printf("请按顺序输入每个人的密码\n");
	q = head;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &q->code);
		q->num = i;
		q = q->next;
	}                         //做一个循环，将每个人的编号和密码输进节点里面 

	q = tail;                //从前一位数开始，使得开始时从一开始 
	/*for(i = 0; i < n; i++)   //有几个人就会循环几次
	{
	for(j =0;j<m;j++)
	{
	q = q->next;
	}
	m = q->code;         //将新的密码赋给m
	printf("%d ",q->num);
	q->prior->next = q->next;
	q->next->prior = q->prior;         //双向链表中节点p的删除
	p = q;
	q = q->prior;
	free(p);                           //释放空间
	}*/
    /*for (i = 0; i < n; i++)   //有几个人就会循环几次 
	{
		for (j = 1; j<m; j++)
		{
			q = q->next;
		}
		p = q->next;
		m = p->code;                  //将新的密码赋给m 
		printf("%d ", p->num);         //单向链表中节点p的删除 
		q->next = p->next;
		free(p);                      //释放空间
	}

	printf("\n");

	return 0;
}
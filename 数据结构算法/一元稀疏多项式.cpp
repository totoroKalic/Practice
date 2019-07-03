/*
  一元稀疏方程组的计算
*/
/*
  该程序存在问题！还需要调试
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int down;
	int up;
	struct LNode *next;
}LNode,*LNodeList;

void creatLNode(LNodeList &hp, int m)
{
	LNodeList  p;
	hp = (LNodeList)malloc(sizeof(LNode));
	p = hp;
	for (int i = 0; i < m; i++)
	{
		p->next = (LNodeList)malloc(sizeof(LNode));
		scanf("%d %d", &p->next->down, &p->next->up);
		p = p->next;
	}
	
	p->next = NULL;
}

void add(LNodeList pa, LNodeList pb)
{
	LNodeList t_a, t_b;
	t_a = pa->next;
	t_b = pb->next;
	while (pb != NULL)
	{
		if (pa == NULL)
		{
			pa->next = pb;
			break;
		}
		if (t_a->up == t_b->up)
		{
			t_a->down += t_b->down;
			if (t_a->down == 0)
				pa->next = t_a->next;
			else
				pa = pa->next;
			t_a = t_a->next;
			t_b = t_b->next;
		}
		if (t_a->up < t_b->up)
		{
			t_a = t_a->next;
			pa = pa->next;
		}
		if (t_a->up > t_b->up)
		{
			pa->next = t_b;
			pb = t_b->next;
			t_b->next = t_a;
			t_b = pb;
			pa = pa->next;
		}
	}
}

void sub(LNodeList pa, LNodeList pb)
{
	LNodeList t_a, t_b;
	t_a = pa->next;
	t_b = pb->next;
	while (pa != NULL&&pb != NULL)
	{
		if (t_a->up == t_b->up)
		{
			t_a->down -= t_b->down;
			if (t_a->down == 0)
				pa->next = t_a->next;
			else
				pa = pa->next;
			t_a = t_a->next;
			t_b = t_b->next;
		}
		else if (t_a->up < t_b->up)
		{
			t_a = t_a->next;
			pa = pa->next;
		}
		else if (t_a->up > t_b->up)
		{
			pa->next = t_b;
			pb = t_b->next;
			t_b->next = t_a;
			t_b->down = -1 * t_b->down;
			t_b = pb;
			pa = pa->next;
		}
	}
	if (t_b != NULL)
	{
		pa->next = t_b;
		while (t_b)
		{
			t_b->down *= -1;
			t_b = t_b->next;
		}
	}
}

void printLNode(LNodeList pa)
{
	LNodeList hp;
	int flag = 1;
	hp = pa;
	while(hp->next!=NULL)
	{
		hp = hp->next;
		if (hp->down)
		{
			if (flag != 0 && hp->down > 0)
			{
				printf("+");
			}
			flag = 0;
			if (hp->up == 0)
				printf("%d", hp->down);
			else
			{
				if (hp->down == -1)
					printf("-");
				else if (hp->down != 1)
					printf("%d", hp->down);
				if (hp->up != 1)
					printf("x^%d", hp->up);
				else
					printf("x");
			}
		}
	}
	if (flag == 0)
		printf("0");
}

int main()
{
	int m, n, a;
	scanf("%d %d %d", &m, &n, &a);
	LNodeList pa, pb;
	creatLNode(pa, m);
	creatLNode(pb, n);
	if (a == 0)
		add(pa, pb);
	else
		sub(pa, pb);
	printLNode(pa);
	printf("\n");
	return  0;
}
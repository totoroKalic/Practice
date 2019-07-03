#include<stdio.h>
#include<string.h>
typedef struct Book{
	char name[20];
	int ISBN;
	double price;
	char writer[10];
	int a;
	char borrow[10];
	char sex[4];
	char num[20];
}Book;

int print(Book *book,int i)//�����Ƿ�ɹ�
{
	printf("������%s\n",book[i].name);
	printf("��ţ�%d\n",book[i].ISBN);
	printf("�۸�%.2lf\n",book[i].price);
	printf("���ߣ�%s\n",book[i].writer);
	printf("�Ƿ���裺%d\n",book[i].a);
	if(book[i].a==1)
	{
		printf("�����ˣ�%s\n",book[i].borrow);
		printf("�Ա�%s\n",book[i].sex);
		printf("ѧ�ţ�%s\n",book[i].num);
	}
	else
		printf("��δ���\n");
	return 1;
}
int scan_new(Book *book,int n)//�������б���
{
	scanf("%s",book[n].name);
	scanf("%lf",&book[n].price);
	scanf("%s",book[n].writer);
	book[n].a=1;
	book[n].ISBN=n;
	strcpy(book[n].borrow,"δ���");
	strcpy(book[n].sex,"0");
	strcpy(book[n].num,"0");
	book[n].a=0;
	return n+1;
}

int search_name(Book *book,int n,char *name)//�����Ƿ�ɹ�
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp(name,book[i].name)==0)
			break;
	if(print(book,i)==1) return 1;
	else return 0;
}

int delete_book(Book *book,int n,Book base,char *name)//�������б���
{
	int i,j;
	for(i=0;i<n;i++)
		if(strcmp(name,book[i].name)==0)
			break;
	for(j=i;j<n-1;j++)
	{
		book[j]=base;
		book[j]=book[j+1];
	}
	book[n-1]=base;
	return n-1;
}

void borrow(Book *book,int n)
{
	int i;
	char x[20];
	printf("����������Ҫ����鱾��\n");
	scanf("%s",x);
	for(i=0;i<n;i++)
		if(strcmp(book[i].name,x)==0)
		{
			if(book[i].a==0)
			{
				printf("�鱾δ��������������������\n");
				scanf("%s",book[i].borrow);
				printf("�����Ա�\n");
				scanf("%s",book[i].sex);
				printf("����ѧ�ţ�\n");
				scanf("%s",book[i].num);
				book[i].a=1;
			}
			else
				printf("�����Ѿ��������Ǹ��\n");
			break;

		}
}

void back_name(Book *book,int n,char *x)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp(book[i].name,x)==0)
		{
			strcpy(book[i].borrow,"\0");
			strcpy(book[i].sex,"\0");
			strcpy(book[i].num,"\0");
			book[i].a=1;
			break;
		}
}

int main()
{
	FILE *p;
	Book book[100];
	Book base;
	int i,how,n;
	char names[20];

	
	strcpy(base.name,"\0");
	base.ISBN=-1;
	base.price=0;
	strcpy(base.writer,"\0");
	strcpy(base.borrow,"\0");
	strcpy(base.sex,"\0");
	strcpy(base.num,"\0");
	base.a=0;

	for(i=0;i<100;i++)
		book[i]=base;

	p=fopen("book.txt","r");
	n=0;
	while(fscanf(p,"%s",book[n].name)!=EOF)
	{
		fscanf(p,"%d",&book[n].ISBN);
		fscanf(p,"%lf",&book[n].price);
		fscanf(p,"%s",book[n].writer,20,p);
		fscanf(p,"%d",&book[n].a);
		fscanf(p,"%s",book[n].borrow);
		fscanf(p,"%s",book[n].sex);
		fscanf(p,"%s",book[n].num);
		n++;
	}
	while(1)
	{
		strcpy(names,"\0");
		printf("Please choose :1.���� 2.�������  3.������Ŀ 4.ɾ����Ŀ 5.���� 6.����\n");
		scanf("%d",&how);
		if(how==1)  break;
		if(how==2)  n=scan_new(book,n);
		if(how==3)  
		{
			printf("������������\n");
			scanf("%s",names);
			search_name(book,n,names);
		}
		if(how==4)
		{
			printf("������������\n");
			scanf("%s",names);
			n=delete_book(book,n,base,names);
		}
		if(how==5)	borrow(book,n);
		if(how==6)  
		{
			printf("������������\n");
			scanf("%s",names);
			back_name(book,n,names);
		}
	}
	fclose(p);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>

typedef struct DianGe
{
	int songnum[15];
	char songname[15];
	char songername[15];
 } DianGe;

int getdata(DianGe dian[])
{
	FILE *fp;
	int k = 0;
	fp = fopen("song.txt","r");
	while(fscanf(fp,"%d%s%s",&dian[k].songnum,dian[k].songname,dian[k].songername)!=EOF)
	{
		k++;
	} 
	fclose(fp);
	return k;
}

int out()
{
	char a[5];
	printf("ȷ���˳�ϵͳ��(y/n)");
	scanf("%s",a);
	if(strcmp(a,"y") == 0)
	{
		return 0;
	} 
 }
  
void ShowMenu(int cho)
{
	if(cho == 1)
	{
		printf("1.�������������\n");
		printf("2.���ո������\n"); 
	}
	else
	{
		printf("1.��Ӹ���\n");
		printf("2.ɾ������\n");
	}
	printf("3.�˳�\n");
	printf("��ѡ���ܣ� "); 
}

void choocebysinger()
{
	char a[20];
	DianGe dian[100];
	int t,q;
	int k = getdata(dian);
	printf("������Ҫ��ĸ��ֵ����֣� "); 
	scanf("%s",a);
	for(q=0;q<k;q++)
	{
		if(!strcmp(a,dian[q].songername))
		{
			if(t == 0)
			printf("�ø��������¸�����\n");
			t++;
			printf("[%d]%s\n",q+1,dian[q].songname);
		}
	}
	if(t==0)
	{
		printf(" ��ϵͳ�޷����ָ�����\n");
	}
	printf("���������볪�ĸ����ĸ����� ");
	scanf("%s",a);
	t = 0;
	for(q=0;q<k&&t == 0;q++)
	{
		if(!strcmp(a,dian[q].songname))
		{
			FILE *p;
			char b[5] = ".txt";
			char temp[100];
			strcat(a,b);
			p = fopen(a,"r");
			t = 1;
			while(fgets(temp,100,p)!=NULL)
			printf("%s",temp);
		}
		printf("\n");
	 } 
	 if(t == 0)
	 {
	 	printf(" ��ϵͳ�޸ø�����\n");
	 //	return 0;
	 }
}

void choocebysong()
{
	char a[20];
	DianGe dian[100];
	int t = 0,q;
	int k = getdata(dian);
	printf("KTV�����¸���: \n");
	for(q=0;q < k;q++)
	{
		printf("[%d]%s\n",q+1,dian[q].songname);
	}
	printf("���������볪�ĸ����ĸ����� ");
	scanf("%s",a);
	t = 0;
	for(q=0;q<k&&t==0;q++)
	{
		if(!strcmp(a,dian[q].songname))
		{
			FILE *p;
			char b[5] = ".txt";
			char temp[100];
			strcat(a,b);
			p = fopen(a,"r");
			t = 1; 
			while(fgets(temp,100,p)!=NULL)
			printf("%s",temp);
		}
		printf("\n"); 
    }
    if(t==0)
    {
        printf(" ��ϵͳ�޸ø�����\n");
        return ;
    }
}
	
void add()
{
	FILE *fp;
	char a[20];
	DianGe dian[100];
	int t = 0;
	int k = getdata(dian);
	
	fp = fopen("song.txt","a+");   //���ӵ���ʽ���ϸ����� 
	fprintf(fp,"\n%d ",k+1);
	printf("��������ӵĸ���: \n");
	scanf("%s",a);
	fprintf(fp,"%s",a);
	printf("������ø����ĸ���: \n");
	scanf("%s",a);
	fprintf(fp,"%s",a);
	fclose(fp);
}
void del()
{
	FILE *fp;
	char a[20];
	DianGe dian[100];
	int t = 0,i = 1;
	int k = getdata(dian);
	printf("**********%d*********\n",k);
	fp = fopen("song.txt","w");
	printf("������ɾ���ĸ��������֣� ");
	scanf("%s",a);
	for(t = 0;t < k;t++)
	{
		if(strcmp(dian[t].songname,a)!=0)
		{
			fprintf(fp,"%d %s %s\n",i,dian[t].songname,dian[t].songername);
			i++;
		}
	} 
	if((i - 1) == k)
	{
		printf("������û����Ҫɾ���ĸ�\n");
	}
	else
	printf("ɾ���ɹ�\n");
	fclose(fp);
}
void process_user()
{
	int cho;
	int flag = 1;
	while(flag)
	{
		ShowMenu(1);
		scanf("%d",&cho);
		if(cho == 1)
		choocebysinger();
		else if(cho == 2)
		choocebysong();
		else if(cho == 3)
		{
			flag = out();
		}
		else
		printf("����������������룡\n");
	}
}

void process_admin()
{
	int cho;
	int flag = 1;
	while(flag)
	{
		ShowMenu(2);
		scanf("%d",&cho);
		if(cho == 1)
		{
			add();
		}
		else if(cho == 2)
		{
			del();
		}
		else if(cho == 3)
		{
			flag = out();
		}
		else
		printf("����������������룡\n");
	}
}
int main()
{
	char keyword[10]="88888888";
	printf("���ڵ�½ϵͳ.........\n");
	while(1)
	{
		int user;
		printf("�û��밴1������Ա�밴2.......\n");
		scanf("%d",&user);
		if(user == 1)
		{
			process_user();
		}
		else if(user == 2)
		{
			char key[20];
			printf("���������Ա����:");
			scanf("%s",key);
			if(strcmp(key,keyword) == 0)
			process_admin();
			else
			printf("�������...............\n");
		}
		else
		printf("�������������ѡ��..........\n");
		
	}
	return 0;
}

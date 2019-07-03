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
	printf("确定退出系统？(y/n)");
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
		printf("1.按歌手姓名点歌\n");
		printf("2.按照歌曲点歌\n"); 
	}
	else
	{
		printf("1.添加歌曲\n");
		printf("2.删除歌曲\n");
	}
	printf("3.退出\n");
	printf("请选择功能： "); 
}

void choocebysinger()
{
	char a[20];
	DianGe dian[100];
	int t,q;
	int k = getdata(dian);
	printf("请输入要查的歌手的名字： "); 
	scanf("%s",a);
	for(q=0;q<k;q++)
	{
		if(!strcmp(a,dian[q].songername))
		{
			if(t == 0)
			printf("该歌手有以下歌曲；\n");
			t++;
			printf("[%d]%s\n",q+1,dian[q].songname);
		}
	}
	if(t==0)
	{
		printf(" 本系统无法歌手歌曲！\n");
	}
	printf("请输入你想唱的歌曲的歌名： ");
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
	 	printf(" 本系统无该歌曲！\n");
	 //	return 0;
	 }
}

void choocebysong()
{
	char a[20];
	DianGe dian[100];
	int t = 0,q;
	int k = getdata(dian);
	printf("KTV有以下歌曲: \n");
	for(q=0;q < k;q++)
	{
		printf("[%d]%s\n",q+1,dian[q].songname);
	}
	printf("请输入你想唱的歌曲的歌名： ");
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
        printf(" 本系统无该歌曲！\n");
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
	
	fp = fopen("song.txt","a+");   //附加的形式加上歌曲名 
	fprintf(fp,"\n%d ",k+1);
	printf("请输入添加的歌曲: \n");
	scanf("%s",a);
	fprintf(fp,"%s",a);
	printf("请输入该歌曲的歌手: \n");
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
	printf("输入想删除的歌曲的名字： ");
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
		printf("曲库里没有你要删除的歌\n");
	}
	else
	printf("删除成功\n");
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
		printf("输入错误！请重新输入！\n");
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
		printf("输入错误！请重新输入！\n");
	}
}
int main()
{
	char keyword[10]="88888888";
	printf("正在登陆系统.........\n");
	while(1)
	{
		int user;
		printf("用户请按1，管理员请按2.......\n");
		scanf("%d",&user);
		if(user == 1)
		{
			process_user();
		}
		else if(user == 2)
		{
			char key[20];
			printf("请输入管理员密码:");
			scanf("%s",key);
			if(strcmp(key,keyword) == 0)
			process_admin();
			else
			printf("输入错误...............\n");
		}
		else
		printf("输入错误，请重新选择..........\n");
		
	}
	return 0;
}

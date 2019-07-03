/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	unsigned int weight;
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode,*HuffmanTree;                                  //定义一个哈夫曼树的结构体; 权数 父节点 左子数 右子数

typedef char *HuffmanCode[100]; 

void Mune()                                            //主目录，通过输入可以完成相应的功能
{
	printf("==================================================================================\n");
	printf("\n");
	printf("请选择你想进行的操作:\n");
	printf("I:初始化（Initialization）\n");
	printf("E:编码(Eecoding)\n");
	printf("D:译码(Decoding)\n");
	printf("P:印代码文件(Print)\n");
	printf("T:印哈夫曼树(Tree printing)\n");
	printf("\n");
	printf("===================================================================================\n");
}

int Max(int words[], int pos)                         //算出所有叶子结点的权数的和，在后面的select函数选择两个最小的数时会用到
{
	int temp = 0;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		temp += words[i];
	}
	return temp;
}                                                      //这里的pos为所有的元素个数也就是叶子结点的个数

void CrtHuffurmanTree(HuffmanTree ht, int words[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		ht[i].weight = words[i];
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	}
	k = 2 * n - 1;                                     //n个叶子节点也就是拥有2*n-1个节点
	for (j = n; j <= k - 1; j++)
	{
		ht[j].weight = 0;
		ht[j].parent = 0;
		ht[j].lchild = 0;
		ht[j].rchild = 0;
	}
}                                                     //将哈夫曼树的其他未知变量写成0，把图表的框架写出来

void select(HuffmanTree ht, int pos, int words[], int *s1, int *s2, int max)
{
	int j, m1, m2, n;
	n = pos;
	m1 = m2 = max;
	for (j = 0; j < pos; j++)
	{
		if (ht[j].weight < m1 && ht[j].parent == 0)
		{                                             //算法很巧妙，可以在以后的编程中用到
			m2 = m1;
			*s2 = *s1;
			*s1 = j;
			m1 = ht[j].weight;
		}                                                                   //比最小值小，不仅要把最小值赋值，也要把次小值往前移
		else if (ht[j].weight < m2 && ht[j].parent == 0)
		{
			m2 = ht[j].weight;
			*s2 = j;
		}
	}
}

void CreatHuffmanTree(HuffmanTree ht, int n, int words[], int max)         //分别的写出叶子结点的父子书，把哈夫曼树构建完成
{
	int k, s1, s2, i;
	k = 2 * n - 1;
	for (i = n; i <= k - 1; i++)
	{
		select(ht, i, words, &s1, &s2, max);           
		ht[i].weight = ht[s1].weight + ht[s2].weight;                      //父节点
		ht[s1].parent = i;                                                 
		ht[i].lchild = s1;
		ht[i].rchild = s2;                                                 //左子数
		ht[s2].parent = i;                                                 //右子数
	}
}

void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)                 //关键的一部！哈夫曼树的编码
{
	int i, p, start, c;
	char *cd;
	cd = (char *)malloc(n*sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++)
	{
		start = n - 1;
		c = i - 1;
		p = ht[i - 1].parent;
		while (p != 0)
		{
			--start;                                                      //因为是从叶子结点往上数的，所以相应编码往后放
			if (ht[p].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
	 	hc[i - 1] = (char *)malloc((n - start - 1)*sizeof(char));        //分配确定的空间，保证不溢出也不出现没利用的空间   
   		strcpy(hc[i - 1], &cd[start]);                                   //因为cd[]数组前面有空，所以copy时从有数据的地方开始
	}
	free(cd);
}

void InitTree(HuffmanTree ht, FILE *fp1,int n)
{
	int i, max;
	int words[50];
	printf("请输入个元素的频度\n");                                     //这个我与书中的有一些不同，我忽略了元素的输入，仅仅输入元素的权数，元素的输出靠权数的下标和ASICII码来确定
	for (i = 0; i < n; i++)
	{
		scanf("%d", &words[i]);
	}
	max = Max(words, n);
	CrtHuffurmanTree(ht, words, n);                                     //初始化
	CreatHuffmanTree(ht, n, words, max);                                //然后把哈夫曼树确定
	for (i = 0; i <= 2 * n - 2; i++)
	{
		fprintf(fp1, "%d %d %d %d\n", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	}
	fclose(fp1);                                                        //文件一定要关闭，不然数据会一直在缓存里面，后面引用不了（调试了很长时间发现的）
}

void Encoding(HuffmanTree ht, FILE *fp2,FILE *fp3, HuffmanCode hc, int n)
{
	int i, num, temp;
	char words[100];                         
	FILE *fp1 = fopen("hfmTree.txt", "r+");                              //文件打开，因为我在之前的I初始化函数里面已经将文件关闭了，所以这里面引用时需要再打开
	//char words2[100];
	if (ht == NULL)                                                      //如果内存里没有了哈夫曼树的缓存，将哈夫曼树从文件里调用出来
	{
		for (i = 0; i < 2 * n - 1; i++)
		{
			fscanf(fp1, "%d %d %d %d", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
		}
	}
	CrtHuffmanCode(ht, hc, n);                                            //每个元素求出其编码
	fgets(words,100,fp2 );                                                //用了fgets，因为考虑到fscanf会在空格处停止
	//puts(words);
	num = strlen(words);
	for (i = 0; i < num; i++)
	{
		if ((words[i] - 'A') >= 0 && (words[i] - 'A') <= 26)
		{
			temp = words[i] - 'A';                                          //元素减去‘A’，再配合ascii就可以实现元素啦
			//puts(hc[a]);
			//puts(hc[temp+1]);
			fprintf(fp3,"%s", hc[temp+1]);
			//fputs(hc[temp + 1], fp3);                                      //纠结了好久，调试了很多次，然后用了fprintf
		}
		else if (words[i] == ' ')
		{
			fprintf(fp3,"%s", hc[0]);                                        //C语言数组里的o位是空格，配合书上的题目，其他的可以换一下条件的
			//fputs(hc[0], fp3);
		}
	}
	fclose(fp3);
	//fscanf(fp3, "%s", words2);
	//puts(words2);
}

void Decoding(HuffmanTree ht, FILE *fp4, int n)
{
	char words[1000];
	int num, flag, i;
	FILE *fp1 = fopen("hfmTree.txt", "r+");
	FILE *fp3 = fopen("CodeFile.txt","r+");                                 //和上面的fp1原理是一样的
	fgets(words, 1000, fp3);                                                //同上
	num = strlen(words);
	for (i = 0; i < num; i++)                                               //根据一位一位的遍历，如果到叶子结点就输出元素，再回到根节点再遍历
	{
		flag = 2 * n - 2;
		//printf("@%d@ ",i);
		while (1)
		{
			if (words[i] == '0')
			{
				flag = ht[flag].lchild;
				i++;
			}
			else
			{
				flag = ht[flag].rchild;
				i++;
			}
			if (ht[flag].lchild == 0 && ht[flag].rchild == 0)
			{
				if (flag > 0)
				{
					fprintf(fp4,"%c", 'A' + flag - 1);
				}
				else
					fprintf(fp4," ");
				i = i - 1;                                                       //这一点一定要注意，上面是i++
				break;
			}
		}
	}
	fclose(fp4);
}

void OptionP(FILE *fp5)
{
	char words[100][100] = {'\0'};
	int i = 0; 
	FILE *fp3 = fopen("CodeFile.txt", "r+");
	while (fgets(words[i],50,fp3)!=NULL)                                        //根据fgets的特性，让words数组没一次存50个，没一次数据都会替换上一个的
	{
		printf("%s\n", words[i]);
		fprintf(fp5, "%s\n", words[i]);
		i++;
	}
	fclose(fp5);
}

void TreePrint(HuffmanTree ht,FILE *fp6,int n)
{
	int i;
	printf("标号     权数       父节点       左子数          右子数\n");
	for (i = 0; i < 2 * n - 1; i++)
	{
		printf("  %d       %d          %d             %d               %d\n", i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
		fprintf(fp6,"  %d      %d          %d            %d               %d\n", i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	}
	fclose(fp6);
}
int main()
{
	FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;                           //定义六个文件指针，分别指向相应的六个文件
	fp1 = fopen("hfmTree.txt", "w+");
	fp2 = fopen("ToBeTran.txt", "r+");
	fp3 = fopen("CodeFile.txt", "w+");
	fp4 = fopen("TextFile.txt", "w+");
	fp5 = fopen("CodePrin.txt", "w+");
	fp6 = fopen("TreePrint.txt", "w+");
	if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL || fp5 == NULL || fp6 == NULL)  //判断是否出现文件打开不成功
	{
		printf("The file can not be opened.\n");
		exit(1);                                                    //结束程序的执行
	}

	int i, a, n, temp, num, max, num2, flag;
	char code[100], option = 'A';
	HTNode ht[100];
	HuffmanCode hc;
	Mune();
	scanf("%c", &option);
	while (option != 'Q')          //根据不同的选择，跳转到不同的函数来实现功能
	{
		switch (option)
		{
		case 'I':
		{
			printf("请输入元素的个数n\n");
			scanf("%d", &n);
			InitTree(ht, fp1, n);
			printf("初始化以完成，");
			break;
		}
		case 'E':
		{
			Encoding(ht, fp2, fp3, hc, n);
			printf("编码完成，");
			break;
		}
		case 'D':
		{
			Decoding(ht, fp4, n);
			printf("译码完成,");
			break;
		}
		case 'P':
		{
			OptionP(fp5);
			printf("代码打印完成,");
			break;
		}
		case 'T':
		{
			TreePrint(ht, fp6, n);
			printf("哈夫曼树的打印完成,");
			break;
		}
		}
		printf("请继续您的选择\n");
		getchar();
		scanf("%c", &option);
	}
	fcloseall();                                                                   //用的是vs2013编译器，但dev c++会报错
	return 0;
}*/
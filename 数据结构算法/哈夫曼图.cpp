/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	unsigned int weight;
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode,*HuffmanTree;                                  //����һ�����������Ľṹ��; Ȩ�� ���ڵ� ������ ������

typedef char *HuffmanCode[100]; 

void Mune()                                            //��Ŀ¼��ͨ��������������Ӧ�Ĺ���
{
	printf("==================================================================================\n");
	printf("\n");
	printf("��ѡ��������еĲ���:\n");
	printf("I:��ʼ����Initialization��\n");
	printf("E:����(Eecoding)\n");
	printf("D:����(Decoding)\n");
	printf("P:ӡ�����ļ�(Print)\n");
	printf("T:ӡ��������(Tree printing)\n");
	printf("\n");
	printf("===================================================================================\n");
}

int Max(int words[], int pos)                         //�������Ҷ�ӽ���Ȩ���ĺͣ��ں����select����ѡ��������С����ʱ���õ�
{
	int temp = 0;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		temp += words[i];
	}
	return temp;
}                                                      //�����posΪ���е�Ԫ�ظ���Ҳ����Ҷ�ӽ��ĸ���

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
	k = 2 * n - 1;                                     //n��Ҷ�ӽڵ�Ҳ����ӵ��2*n-1���ڵ�
	for (j = n; j <= k - 1; j++)
	{
		ht[j].weight = 0;
		ht[j].parent = 0;
		ht[j].lchild = 0;
		ht[j].rchild = 0;
	}
}                                                     //����������������δ֪����д��0����ͼ��Ŀ��д����

void select(HuffmanTree ht, int pos, int words[], int *s1, int *s2, int max)
{
	int j, m1, m2, n;
	n = pos;
	m1 = m2 = max;
	for (j = 0; j < pos; j++)
	{
		if (ht[j].weight < m1 && ht[j].parent == 0)
		{                                             //�㷨������������Ժ�ı�����õ�
			m2 = m1;
			*s2 = *s1;
			*s1 = j;
			m1 = ht[j].weight;
		}                                                                   //����СֵС������Ҫ����Сֵ��ֵ��ҲҪ�Ѵ�Сֵ��ǰ��
		else if (ht[j].weight < m2 && ht[j].parent == 0)
		{
			m2 = ht[j].weight;
			*s2 = j;
		}
	}
}

void CreatHuffmanTree(HuffmanTree ht, int n, int words[], int max)         //�ֱ��д��Ҷ�ӽ��ĸ����飬�ѹ��������������
{
	int k, s1, s2, i;
	k = 2 * n - 1;
	for (i = n; i <= k - 1; i++)
	{
		select(ht, i, words, &s1, &s2, max);           
		ht[i].weight = ht[s1].weight + ht[s2].weight;                      //���ڵ�
		ht[s1].parent = i;                                                 
		ht[i].lchild = s1;
		ht[i].rchild = s2;                                                 //������
		ht[s2].parent = i;                                                 //������
	}
}

void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)                 //�ؼ���һ�������������ı���
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
			--start;                                                      //��Ϊ�Ǵ�Ҷ�ӽ���������ģ�������Ӧ���������
			if (ht[p].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
	 	hc[i - 1] = (char *)malloc((n - start - 1)*sizeof(char));        //����ȷ���Ŀռ䣬��֤�����Ҳ������û���õĿռ�   
   		strcpy(hc[i - 1], &cd[start]);                                   //��Ϊcd[]����ǰ���пգ�����copyʱ�������ݵĵط���ʼ
	}
	free(cd);
}

void InitTree(HuffmanTree ht, FILE *fp1,int n)
{
	int i, max;
	int words[50];
	printf("�������Ԫ�ص�Ƶ��\n");                                     //����������е���һЩ��ͬ���Һ�����Ԫ�ص����룬��������Ԫ�ص�Ȩ����Ԫ�ص������Ȩ�����±��ASICII����ȷ��
	for (i = 0; i < n; i++)
	{
		scanf("%d", &words[i]);
	}
	max = Max(words, n);
	CrtHuffurmanTree(ht, words, n);                                     //��ʼ��
	CreatHuffmanTree(ht, n, words, max);                                //Ȼ��ѹ�������ȷ��
	for (i = 0; i <= 2 * n - 2; i++)
	{
		fprintf(fp1, "%d %d %d %d\n", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	}
	fclose(fp1);                                                        //�ļ�һ��Ҫ�رգ���Ȼ���ݻ�һֱ�ڻ������棬�������ò��ˣ������˺ܳ�ʱ�䷢�ֵģ�
}

void Encoding(HuffmanTree ht, FILE *fp2,FILE *fp3, HuffmanCode hc, int n)
{
	int i, num, temp;
	char words[100];                         
	FILE *fp1 = fopen("hfmTree.txt", "r+");                              //�ļ��򿪣���Ϊ����֮ǰ��I��ʼ�����������Ѿ����ļ��ر��ˣ���������������ʱ��Ҫ�ٴ�
	//char words2[100];
	if (ht == NULL)                                                      //����ڴ���û���˹��������Ļ��棬�������������ļ�����ó���
	{
		for (i = 0; i < 2 * n - 1; i++)
		{
			fscanf(fp1, "%d %d %d %d", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
		}
	}
	CrtHuffmanCode(ht, hc, n);                                            //ÿ��Ԫ����������
	fgets(words,100,fp2 );                                                //����fgets����Ϊ���ǵ�fscanf���ڿո�ֹͣ
	//puts(words);
	num = strlen(words);
	for (i = 0; i < num; i++)
	{
		if ((words[i] - 'A') >= 0 && (words[i] - 'A') <= 26)
		{
			temp = words[i] - 'A';                                          //Ԫ�ؼ�ȥ��A���������ascii�Ϳ���ʵ��Ԫ����
			//puts(hc[a]);
			//puts(hc[temp+1]);
			fprintf(fp3,"%s", hc[temp+1]);
			//fputs(hc[temp + 1], fp3);                                      //�����˺þã������˺ܶ�Σ�Ȼ������fprintf
		}
		else if (words[i] == ' ')
		{
			fprintf(fp3,"%s", hc[0]);                                        //C�����������oλ�ǿո�������ϵ���Ŀ�������Ŀ��Ի�һ��������
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
	FILE *fp3 = fopen("CodeFile.txt","r+");                                 //�������fp1ԭ����һ����
	fgets(words, 1000, fp3);                                                //ͬ��
	num = strlen(words);
	for (i = 0; i < num; i++)                                               //����һλһλ�ı����������Ҷ�ӽ������Ԫ�أ��ٻص����ڵ��ٱ���
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
				i = i - 1;                                                       //��һ��һ��Ҫע�⣬������i++
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
	while (fgets(words[i],50,fp3)!=NULL)                                        //����fgets�����ԣ���words����ûһ�δ�50����ûһ�����ݶ����滻��һ����
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
	printf("���     Ȩ��       ���ڵ�       ������          ������\n");
	for (i = 0; i < 2 * n - 1; i++)
	{
		printf("  %d       %d          %d             %d               %d\n", i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
		fprintf(fp6,"  %d      %d          %d            %d               %d\n", i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	}
	fclose(fp6);
}
int main()
{
	FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;                           //���������ļ�ָ�룬�ֱ�ָ����Ӧ�������ļ�
	fp1 = fopen("hfmTree.txt", "w+");
	fp2 = fopen("ToBeTran.txt", "r+");
	fp3 = fopen("CodeFile.txt", "w+");
	fp4 = fopen("TextFile.txt", "w+");
	fp5 = fopen("CodePrin.txt", "w+");
	fp6 = fopen("TreePrint.txt", "w+");
	if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL || fp5 == NULL || fp6 == NULL)  //�ж��Ƿ�����ļ��򿪲��ɹ�
	{
		printf("The file can not be opened.\n");
		exit(1);                                                    //���������ִ��
	}

	int i, a, n, temp, num, max, num2, flag;
	char code[100], option = 'A';
	HTNode ht[100];
	HuffmanCode hc;
	Mune();
	scanf("%c", &option);
	while (option != 'Q')          //���ݲ�ͬ��ѡ����ת����ͬ�ĺ�����ʵ�ֹ���
	{
		switch (option)
		{
		case 'I':
		{
			printf("������Ԫ�صĸ���n\n");
			scanf("%d", &n);
			InitTree(ht, fp1, n);
			printf("��ʼ������ɣ�");
			break;
		}
		case 'E':
		{
			Encoding(ht, fp2, fp3, hc, n);
			printf("������ɣ�");
			break;
		}
		case 'D':
		{
			Decoding(ht, fp4, n);
			printf("�������,");
			break;
		}
		case 'P':
		{
			OptionP(fp5);
			printf("�����ӡ���,");
			break;
		}
		case 'T':
		{
			TreePrint(ht, fp6, n);
			printf("���������Ĵ�ӡ���,");
			break;
		}
		}
		printf("���������ѡ��\n");
		getchar();
		scanf("%c", &option);
	}
	fcloseall();                                                                   //�õ���vs2013����������dev c++�ᱨ��
	return 0;
}*/
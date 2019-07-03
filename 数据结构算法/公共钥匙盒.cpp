/* 公共钥匙盒的问题  */

#include <stdio.h>
#include <stdlib.h>

typedef struct Teacr
{
	int key;
	int start;
	int stop;
}Teacr;


void paixu(int a[], int n)
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (a[j]>a[i])
			{
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int m, n, i, j, k, num;
	int code[2000];
	int keynum[100];
	Teacr words[1000];
	scanf("%d %d", &m, &n);
	for (i = 0; i<n; i++)
	{
		//words[i].num = i;
		scanf("%d %d %d", &words[i].key, &words[i].start, &words[i].stop);
	}
	for (i = 0; i<m; i++)
	{
		keynum[i] = i + 1;
	}
	for (i = 0; i<n; i++)
	{
		code[i] = words[i].start + words[i].stop;
	}
	paixu(code, n);
	num = code[0];
	for (i = 0; i<num + 1; i++)
	{
		for (j = 0; j<n; j++)
		{
			if ((words[j].start + words[j].stop) == i)
			{
				for (k = 0; k<m; k++)
				{
					if (keynum[k] == 0)
					{
						keynum[k] = words[j].key;
						k = m;
						//printf("%d%d",,words[j].key);
						//printf("gg");
					}
				}
			}
		}
		for (j = 0; j < n; j++)
		{
			if (words[j].start == i)
			{
				//keynum[words[j].key]=0;
				//continue;
				//printf("code\n");
				for (k = 0; k<m; k++)
				{
					if (keynum[k] == words[j].key)
					{
						keynum[k] = 0;
						//printf("ff");
					}
				}
			}
		}
	}
	for (i = 0; i<m; i++)
	{
		printf("%d ", keynum[i]);
	}
	printf("\n");

	return 0;
}








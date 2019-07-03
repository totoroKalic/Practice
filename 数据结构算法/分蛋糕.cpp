#include <stdio.h>
#include <stdlib.h>

void rank(int A[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (A[j]<A[i])
			{
				int Temp = A[j];
				A[j] = A[i];
				A[i] = Temp;
			}
		}
	}
}

int main()
{
	int m, n, i, num, temp, j,rem=0;
	int words[20000000];
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &num);
		words[i] = num;
	}
	rank(words, m);

	for (j = 0; j < m; j++)
	{
		temp = 0;
		for (i = 0; i < m; i++)
		{
			if (words[i] != 0)
			{
				temp += words[i];
				words[i] = 0;
				if (temp >= n)
				{
					rem++;
					break;
				}
				else if (temp<n&&i!=m-1)
 					continue;
				else if (temp < n&&i == m - 1)
				{
					words[i] = 0;
					rem++;
					break;
				}
			}
		}
		if (words[m - 1] == 0)
			break;
	}
	printf("%d\n", rem);

	return 0;
}
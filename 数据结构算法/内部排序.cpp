#include<stdio.h>
#include<stdlib.h>

static long sort1 = 0, change1 = 0;
static long sort2 = 0, change2 = 0;
static long sort3 = 0, change3 = 0;
static long sort4 = 0, change4 = 0;
static long sort5 = 0, change5 = 0;
static long sort6 = 0, change6 = 0;

void sort1_pao(int *list, int n){                //起泡排序  从0开始 
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n - i - 1; ++j){
			sort1++;							//比较加1 
			if (list[j]>list[j + 1]){
				int ch;
				ch = list[j];
				list[j] = list[j + 1];
				list[j + 1] = ch;
				change1 += 3;						//交换+3 
			}
		}
	}
}

void sort2_insert(int *list, int n){             //直接插入排序  从0开始 
	int i, j;

	for (i = 1; i<n; ++i){
		sort2++;								//比较+1 
		if (list[i]<list[i - 1]){
			int ch;
			ch = list[i];
			list[i] = list[i - 1];
			change2 += 2;							//交换+2 
			for (j = i - 2; j >= 0 && ch<list[j]; j--){
				sort2++;						//比较+1 
				list[j + 1] = list[j];
				change2++;
			}
			sort2++;
			list[j + 1] = ch;
			change2++;
		}
	}
}

int select(int *list, int i, int n){
	int min = i;
	for (int j = i + 1; j<n; ++j){
		sort3++;
		if (list[min]>list[j]){
			min = j;
		}
	}
	return min;
}

void sort3_choice(int *list, int n){            //简单选择排序   从0开始 
	for (int i = 0; i<n; ++i){
		int j = select(list, i, n);                //选择最小的那个 
		if (i != j){
			int ch;
			ch = list[j];
			list[j] = list[i];
			list[i] = ch;
			change3 += 3;
		}
	}
}

int partition(int *list, int low, int high){        //快速排序 从0开始 
	int ch = list[low];
	change4++;
	while (low<high){
		while (low<high&&list[high] >= ch) { sort4++; high--; }
		sort4++;
		if (low == high) break;
		list[low] = list[high];
		change4++;
		while (low<high&&list[low] <= ch) { sort4++; low++; }
		sort4++;
		if (low == high) break;
		list[high] = list[low];
		change4++;
	}
	change4++;
	list[low] = ch;
	return low;
}

void sort4_quick(int *list, int low, int high){    //high是最后一个元素的位置，不是长度 
	if (low<high){
		int p = partition(list, low, high);
		sort4_quick(list, low, p - 1);
		sort4_quick(list, p + 1, high);
	}
}

void Sinsert(int *list, int n, int d){
	int i, j;

	for (i = d; i<n; ++i){
		if (list[i]<list[i - d]){
			change5++;
			int ch = list[i];
			for (j = i - d; j >= 0 && list[j]>ch; j -= d){
				sort5++;
				change5++;
				list[j + d] = list[j];
			}
			sort5++;
			change5++;
			list[j + d] = ch;
		}
	}
}

void sort5_shell(int *list, int n, int *d, int k){     //希尔排序  从0开始 
	for (int i = 0; i<k; ++i){
		Sinsert(list, n, d[i]);
	}
}

void heapsort(int *list, int b, int n){
	int ch = list[b];
	change6++;
	for (int i = 2 * b; i <= n; i *= 2){
		sort6++;
		if (i<n&&list[i + 1]>list[i]) i++;
		sort6++;
		if (ch>list[i]) break;
		list[b] = list[i];
		change6++;
		b = i;
	}
	list[b] = ch;
	change6++;
}

void sort6_heap(int *list, int n){     //堆排序   从1开始 
	for (int i = n / 2; i>0; --i){
		heapsort(list, i, n);
	}
	for (int i = n; i>1; --i){
		int ch;
		ch = list[1];
		list[1] = list[i];
		list[i] = ch;
		change6 += 3;

		heapsort(list, 1, i - 1);
	}
}

int main(){
	int a1[1050], a2[1050], a3[1050], a4[1050], a5[1050], b[1050];
	int xier[6] = { 10, 8, 6, 4, 2, 1 };

	for (int i = 0; i<100; ++i){
		int sz = rand() % 1000;
		a1[i] = sz;
		a2[i] = sz;
		a3[i] = sz;
		a4[i] = sz;
		a5[i] = sz;
		b[i + 1] = sz;
	}
	printf("\n\n");
	sort1_pao(a1, 100);
	sort2_insert(a2, 100);
	sort3_choice(a3, 100);
	sort4_quick(a4, 0, 99);
	sort5_shell(a5, 100, xier, 6);
	sort6_heap(b, 100);

	printf("\n\n");

	printf("100个随机变量\n");
	printf("\t\t比较次数\t\t移动次数\n");
	printf("起泡排序：\t %d\t\t\t  %d\n", sort1, change1);

	printf("直接插入排序：\t %d\t\t\t  %d\n", sort2, change2);

	printf("简单选择排序：\t %d\t\t\t  %d\n", sort3, change3);

	printf("快速排序：\t %d\t\t\t  %d\n", sort4, change4);

	printf("希尔排序：\t %d\t\t\t  %d\n", sort5, change5);

	printf("堆排序：\t %d\t\t\t  %d\n", sort6, change6);


	for (int i = 0; i<500; ++i){
		int sz = rand() % 5000;
		a1[i] = sz;
		a2[i] = sz;
		a3[i] = sz;
		a4[i] = sz;
		a5[i] = sz;
		b[i + 1] = sz;
	}
	printf("\n\n");
	sort1_pao(a1, 500);
	sort2_insert(a2, 500);
	sort3_choice(a3, 500);
	sort4_quick(a4, 0, 499);
	sort5_shell(a5, 500, xier, 6);
	sort6_heap(b, 500);

	printf("\n\n");

	printf("500个随机变量\n");
	printf("\t\t比较次数\t\t移动次数\n");
	printf("起泡排序：\t %d\t\t\t  %d\n", sort1, change1);

	printf("直接插入排序：\t %d\t\t\t  %d\n", sort2, change2);

	printf("简单选择排序：\t %d\t\t\t  %d\n", sort3, change3);

	printf("快速排序：\t %d\t\t\t  %d\n", sort4, change4);

	printf("希尔排序：\t %d\t\t\t  %d\n", sort5, change5);

	printf("堆排序：\t %d\t\t\t  %d\n", sort6, change6);


	for (int i = 0; i<1000; ++i){
		int sz = rand() % 10000;
		a1[i] = sz;
		a2[i] = sz;
		a3[i] = sz;
		a4[i] = sz;
		a5[i] = sz;
		b[i + 1] = sz;
	}
	printf("\n\n");
	sort1_pao(a1, 1000);
	sort2_insert(a2, 1000);
	sort3_choice(a3, 1000);
	sort4_quick(a4, 0, 999);
	sort5_shell(a5, 1000, xier, 6);
	sort6_heap(b, 1000);

	printf("\n\n");

	printf("1000个随机变量\n");
	printf("\t\t比较次数\t\t移动次数\n");
	printf("起泡排序：\t %d\t\t\t  %d\n", sort1, change1);

	printf("直接插入排序：\t %d\t\t\t  %d\n", sort2, change2);

	printf("简单选择排序：\t %d\t\t\t  %d\n", sort3, change3);

	printf("快速排序：\t %d\t\t\t  %d\n", sort4, change4);

	printf("希尔排序：\t %d\t\t\t  %d\n", sort5, change5);

	printf("堆排序：\t %d\t\t\t  %d\n", sort6, change6);


	return 0;
}
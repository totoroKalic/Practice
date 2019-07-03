#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
	char x[10];
	char m[15];
}Hash;

Hash hash[60];                         //哈希表 
int d[31];                             //随机树组 
char x[10], m[15];                      //输入的姓与名 

int hash_number(char *x1, char *m1){     //哈希函数求姓名的位置 
	int i = 0;
	int key = 0;
	while (1){
		if (x1[i] == '\0') break;
		key += toascii(x1[i]);
		i++;
	}
	i = 0;
	while (1){
		if (m1[i] == '\0') break;
		key += toascii(m1[i]);
		i++;
	}
	return key % 59;
}

void hash_insert(char *x1, char *m1){        //放入哈希表  并消除矛盾 
	int key = hash_number(x1, m1);
	if (hash[key].x[0] == '\0'){
		strcpy(hash[key].x, x1);
		strcpy(hash[key].m, m1);
	}
	else{
		for (int i = 0; i<31; ++i){
			key += d[i];
			key = key % 31;
			if (hash[key].x[0] == '\0'){
				strcpy(hash[key].x, x1);
				strcpy(hash[key].m, m1);
				break;
			}
		}
	}
}


int main(){
	int key, j;
	for (int i = 0; i<31; ++i){             //构建随机数组 
		while (1){
			key = rand() % 59;
			for (j = 0; j<i; ++j){
				if (d[j] == key) break;
			}
			if (j == i) break;
		}
		d[i] = key;
	}


	while (1){                          //哈希表的设计 
		printf("哈希表设计\n");
		printf(" 1.初始化\n");
		printf(" 2.查找\n");
		printf(" 3.关闭\n");
		scanf("%d", &key);
		if (key == 1){
			printf("  输入信息:\n");
			for (int i = 0; i<30; ++i){
				printf("姓:");
				scanf("%s", x);
				printf("名:");
				scanf("%s", m);
				hash_insert(x, m);
			}

			for (int i = 0; i<60; ++i){
				printf("%d %s %s\n", i, hash[i].x, hash[i].m);
			}
		}
		if (key == 2){
			printf("  输入信息:\n");
			printf("姓:");
			scanf("%s", x);
			printf("名:");
			scanf("%s", m);
			int vv = hash_number(x, m);
			if ((strcmp(hash[vv].x, x) == 0) && (strcmp(hash[vv].m, m) == 0)){
				printf("%d\n", vv);
			}
			else{
				for (int i = 0; i<31; ++i){
					vv += d[i];
					vv = vv % 31;
					if ((strcmp(hash[vv].x, x) == 0) && (strcmp(hash[vv].m, m) == 0)){
						printf("%d\n", vv);
						break;
					}
				}
			}


		}

		if (key == 3) break;
	}


	return 0;
}
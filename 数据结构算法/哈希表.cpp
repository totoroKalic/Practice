#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
	char x[10];
	char m[15];
}Hash;

Hash hash[60];                         //��ϣ�� 
int d[31];                             //������� 
char x[10], m[15];                      //����������� 

int hash_number(char *x1, char *m1){     //��ϣ������������λ�� 
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

void hash_insert(char *x1, char *m1){        //�����ϣ��  ������ì�� 
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
	for (int i = 0; i<31; ++i){             //����������� 
		while (1){
			key = rand() % 59;
			for (j = 0; j<i; ++j){
				if (d[j] == key) break;
			}
			if (j == i) break;
		}
		d[i] = key;
	}


	while (1){                          //��ϣ������ 
		printf("��ϣ�����\n");
		printf(" 1.��ʼ��\n");
		printf(" 2.����\n");
		printf(" 3.�ر�\n");
		scanf("%d", &key);
		if (key == 1){
			printf("  ������Ϣ:\n");
			for (int i = 0; i<30; ++i){
				printf("��:");
				scanf("%s", x);
				printf("��:");
				scanf("%s", m);
				hash_insert(x, m);
			}

			for (int i = 0; i<60; ++i){
				printf("%d %s %s\n", i, hash[i].x, hash[i].m);
			}
		}
		if (key == 2){
			printf("  ������Ϣ:\n");
			printf("��:");
			scanf("%s", x);
			printf("��:");
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
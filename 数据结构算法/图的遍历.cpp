#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM  30

typedef enum { unvisited, isvisited }VisitIf;

typedef struct EBox{	//�߼� 
	VisitIf	mark;	//���ʱ��
	int 	ivex, jvex;	//�ñ����������������λ��
	struct EBox	*ilink, *jlink;	//�ֱ�ָ�������������������һ����
	int weight;
}EBox;

typedef struct VexBox{	//�㼯 
	char	data[8];
	EBox	*firstedge;	//ָ���һ�������õ�ı� 
}VexBox;

typedef struct{
	VexBox adjmulist[MAX_VERTEX_NUM + 1];
	int vexnum, edgenum;
}AMLGraph;

int Visited[MAX_VERTEX_NUM + 1];

void CreatGraph(AMLGraph *ga){	//������Ŀn���ߵ���Ŀe 
	int i, j, k, w;
	EBox *s;                   	//ȷ��ͼ�Ķ������ͱ��� 
	printf("������ͼ�Ķ������ͱ���\n");
	scanf("%d%d", &ga->vexnum, &ga->edgenum);

	//�������� 
	printf("����������Ϣ\n");
	getchar();
	for (i = 0; i < ga->vexnum; i++){
		printf("%d:", i + 1);
		gets(ga->adjmulist[i + 1].data);
		ga->adjmulist[i + 1].firstedge = NULL;
		Visited[i + 1] = 0;
	}

	//������
	printf("������ߵ���Ϣ\n");
	for (k = 0; k < ga->edgenum; k++){
		scanf("%d%d", &i, &j);
		s = (EBox*)malloc(sizeof(EBox));
		s->ivex = i;
		s->jvex = j;
		//s->weight = w;
		s->mark = unvisited;

		s->ilink = ga->adjmulist[i].firstedge;
		ga->adjmulist[i].firstedge = s;

		s->jlink = ga->adjmulist[j].firstedge;
		ga->adjmulist[j].firstedge = s;
	}
}

void DFS(AMLGraph *ga, int v){
	EBox *p;
	Visited[v] = 1;

	p = ga->adjmulist[v].firstedge;	//����ĵ�һ���ڵ�
	printf("%s  ", ga->adjmulist[v].data);
	//printf("(%d,%d)\n",p->ivex,p->jvex);	 
	while (p != NULL){
		int ivex = p->jvex;
		if (!Visited[ivex]){
			printf("(%d,%d)\n", p->ivex, p->jvex);
			DFS(ga, ivex);
		}

		//��v��δ���ʹ����ڽӶ�����������������
		p = p->ilink;
	}
}

void DFS_traverse(AMLGraph *ga){
	int v;
	for (v = 0; v < ga->vexnum; v++){
		Visited[v + 1] = 0;	//���ʱ�־��ʼ�� 
	}

	for (v = 0; v < ga->vexnum; v++){
		if (!Visited[v + 1])	DFS(ga, v + 1);
	}
}

typedef struct {
	int *elem;
	int front, rear;
}Queue;

void InitQueue(Queue *Q){
	Q->elem = (int *)malloc(MAX_VERTEX_NUM*sizeof(int));
	Q->front = Q->rear = 0;
}

void EnQueue(Queue *Q, int e){
	Q->elem[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;
	//	printf("EnQueue:%d %d\n",Q->front,Q->elem[Q->front]);
}

void DeQueue(Queue *Q){
	if (Q->front == Q->rear)	return;

	Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
}

int QueueEmpty(Queue *Q){
	if (Q->front == Q->rear)	return 1;
	return 0;
}

void BFS_traverse(AMLGraph *ga){
	//��������ȷǵݹ����ͼga��ʹ�ø������кͷ��ʱ�־����visited��
	int v, w, u;
	for (v = 0; v < ga->vexnum; v++)	Visited[v + 1] = 0;
	Queue Q;
	InitQueue(&Q);
	EBox *q;
	for (v = 0; v < ga->vexnum; v++)
		if (!Visited[v + 1]){
			Visited[v + 1] = 1;
			q = ga->adjmulist[v + 1].firstedge;
			printf("%s  ", ga->adjmulist[v + 1].data);
			printf("(%d,%d)\n", q->ivex, q->jvex);//000
			EnQueue(&Q, v + 1);
			while (!QueueEmpty(&Q)){
				int ivex = Q.elem[Q.front];
				DeQueue(&Q);
				EBox *p;
				p = ga->adjmulist[ivex].firstedge;

				while (p){
					int j = p->jvex;
					if (!Visited[j]){
						printf("%s  ", ga->adjmulist[j].data);
						q = ga->adjmulist[j].firstedge;
						printf("(%d,%d)\n", q->ivex, q->jvex);//000
						Visited[j] = 1;
						EnQueue(&Q, j);
					}
					p = p->ilink;
				}
			}
		}
}

int main(){
	AMLGraph G;
	CreatGraph(&G);
	printf("�����������˳��Ϊ��\n");
	DFS_traverse(&G);
	printf("\n");
	printf("\n");
	printf("�����������˳��Ϊ:\n");
	BFS_traverse(&G);

}


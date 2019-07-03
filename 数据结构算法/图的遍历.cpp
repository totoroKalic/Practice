#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM  30

typedef enum { unvisited, isvisited }VisitIf;

typedef struct EBox{	//边集 
	VisitIf	mark;	//访问标记
	int 	ivex, jvex;	//该边依附的两个顶点的位置
	struct EBox	*ilink, *jlink;	//分别指向依附着两个顶点的下一条边
	int weight;
}EBox;

typedef struct VexBox{	//点集 
	char	data[8];
	EBox	*firstedge;	//指向第一条依附该点的边 
}VexBox;

typedef struct{
	VexBox adjmulist[MAX_VERTEX_NUM + 1];
	int vexnum, edgenum;
}AMLGraph;

int Visited[MAX_VERTEX_NUM + 1];

void CreatGraph(AMLGraph *ga){	//顶点数目n，边的数目e 
	int i, j, k, w;
	EBox *s;                   	//确定图的顶点数和边数 
	printf("请输入图的顶点数和边数\n");
	scanf("%d%d", &ga->vexnum, &ga->edgenum);

	//建立顶点 
	printf("请输入点的信息\n");
	getchar();
	for (i = 0; i < ga->vexnum; i++){
		printf("%d:", i + 1);
		gets(ga->adjmulist[i + 1].data);
		ga->adjmulist[i + 1].firstedge = NULL;
		Visited[i + 1] = 0;
	}

	//建立边
	printf("请输入边的信息\n");
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

	p = ga->adjmulist[v].firstedge;	//链表的第一个节点
	printf("%s  ", ga->adjmulist[v].data);
	//printf("(%d,%d)\n",p->ivex,p->jvex);	 
	while (p != NULL){
		int ivex = p->jvex;
		if (!Visited[ivex]){
			printf("(%d,%d)\n", p->ivex, p->jvex);
			DFS(ga, ivex);
		}

		//从v的未访问过的邻接顶点出发深度优先搜索
		p = p->ilink;
	}
}

void DFS_traverse(AMLGraph *ga){
	int v;
	for (v = 0; v < ga->vexnum; v++){
		Visited[v + 1] = 0;	//访问标志初始化 
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
	//按广度优先非递归遍历图ga。使用辅助队列和访问标志数组visited。
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
	printf("深度优先搜索顺序为：\n");
	DFS_traverse(&G);
	printf("\n");
	printf("\n");
	printf("广度优先搜索顺序为:\n");
	BFS_traverse(&G);

}


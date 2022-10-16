#define MAX 20
#define INFINITY 32768
#include<stdio.h>
#define OK 1
#define ERROR 0
#include<malloc.h>

typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef char VertexData;
typedef int AdjType;
//typedef int OtherInfo;

typedef struct ArcNode{
	AdjType adj;//����Ȩͼ��0,1��ʾ�Ƿ����ڣ��Դ�Ȩͼ��ΪȨֵ���͡� 
//	OtherInfo info;
	
}ArcNode;

typedef struct 
{
	VertexData vertex[MAX];
	ArcNode arcs[MAX][MAX];
	int vexnum,arcnum;
	GraphKind kind;
	
}AdjMatrix;

int LocateVertex(AdjMatrix *G,VertexData v)
{
	int j = ERROR,k;
		for(k = 0;k < G->vexnum;k++)
			if(G->vertex[k] == v)
				{
					j = k;
					break;
				}
		return (j);
}
int CreateDN(AdjMatrix *G,int *q)
{
	int i ,j ,k,weight,kinds;
	VertexData v1,v2;
	printf("���붥�����뻡�� ���Ÿ���\n");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	fflush(stdin);
	for(i = 0;i<G->vexnum;i++)
		for(j = 0;j<G->vexnum;j++)
			G->arcs[i][j].adj = INFINITY;
		printf("�����붥�������\n");
	for(i = 0;i<G->vexnum;i++)
		scanf("%c",&G->vertex[i]),
		fflush(stdin);
		printf("������Ҫ����ͼ������ enum {DG,DN,UDG,UDN}\n");
		scanf("%d",&kinds);
		fflush(stdin);
		printf("����v1,v2,Ȩ��\n");
	switch (kinds){
	
	case 0:
		{
		
		for(k = 0;k<G->arcnum;k++)
			{
				scanf("%c,%c,%d",&v1,&v2,&weight);
				fflush(stdin);
				i = LocateVertex(G,v1);
				j = LocateVertex(G,v2);
				G->arcs[i][j].adj = weight;
			}
			*q = G->vexnum;
		G->kind = DN;
		return(OK);
    	}
    case 1:
    		{
		
		for(k = 0;k<G->arcnum;k++)
			{
				scanf("%c,%c,%d",&v1,&v2,&weight);
				fflush(stdin);
				i = LocateVertex(G,v1);
				j = LocateVertex(G,v2);
				G->arcs[i][j].adj = weight;
				G->arcs[j][i].adj = weight;
			}
			*q = G->vexnum;
		G->kind = DG;
		return(OK);
    	}
	}
}

int main()
{
	int status = 0,w,*q = &w;
	AdjMatrix *G;
	G = (AdjMatrix*)malloc(sizeof(AdjMatrix));//ɵɵ�ֲ���� 
	status = CreateDN(G,q);
	int i,j;
	for(i = 0;i < *q;i++)
		for(j = 0;j < *q; j++)
		{
			printf("%6d",G->arcs[i][j].adj);
			if(j == *q-1)
			printf("\n");
		}
}

















#define MAX 20
#define MAX_VERTEX 10
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



struct ClosedgeNode{  //ԭ������ǽṹ������ 
	int adjvex;
	int lowcost;
}closedge[MAX_VERTEX+1];//0�ŵ�Ԫ����


int Minium(ClosedgeNode *closedge,int vexnum)

{
	int i,minlowcost,tag;
		for(i = 1;i <=vexnum;i++)
		if(closedge[i].lowcost != 0){
			
		minlowcost = closedge[i].lowcost;
		tag = i;
		break;
		}
	for(i = 1;i <=vexnum;i++)
		{
		
			if(minlowcost > closedge[i].lowcost&&closedge[i].lowcost != 0)
			minlowcost = closedge[i].lowcost,tag = i;
		}
	return tag;
}
int LocateVertex(AdjMatrix *G,VertexData v);
void MinSpanTree_Prim(AdjMatrix gn,int u)
{
	int i ;
	for(i = 1;i <= gn.vexnum;i++)
		if(i != u)
			{
				closedge[i].adjvex = u;
				closedge[i].lowcost = gn.arcs[u-1][i-1].adj;//��Ӧ�������� 
				
			}
	int e;
	for(e = 1;e <= gn.vexnum-1;e++)
		{
			int v;
			v = Minium(closedge,gn.vexnum);
			u = closedge[v].adjvex;
			printf("%d,%d \n",u,v);
			closedge[v].lowcost = 0;
			
			for(i = 1;i<=gn.vexnum;i++)
				if(gn.arcs[v-1][i-1].adj < closedge[i].lowcost)
					{
						closedge[i].lowcost = gn.arcs[v-1][i-1].adj;
						closedge[i].adjvex = v;
					}
		}
		
}int LocateVertex(AdjMatrix *G,VertexData v)
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
	VertexData u;
	AdjMatrix *G;
	G = (AdjMatrix*)malloc(sizeof(AdjMatrix));//ɵɵ�ֲ���� 
	status = CreateDN(G,q);
	int i,j;
	for(i = 0;i < *q;i++)
		for(j = 0;j < *q; j++)
		{
			printf("%8d",G->arcs[i][j].adj);
			if(j == *q-1)
			printf("\n");
		}
		printf("��������ʵ����\n");
		fflush(stdin);
		scanf("%c",&u);
		MinSpanTree_Prim(*G,LocateVertex(G,u)+1);
		//QW
		
}


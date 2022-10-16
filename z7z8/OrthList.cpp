#define MAX 20
typedef enum {DG,DN,UDG,UDN
};GraphKind;

typedef struct ArcNode
{
	int tailvex,headvex;
	struct ArcNode *hlink,*tlink;
}ArcNode;

typedef struct VertexNode
{
	VertexData data;
	ArcNode *firstin,*firstout;
}VertexNode;

typedef struct 
{
	VertexNode vertex[MAX];
	int vexnum,arcnum;
	GraphKind kind;
	
}OrthList;
#include<stdio.h>

void CrtOrthList(OrthList *g)
{
	
	scanf("%d,%d",&n,&e);
	g->vexnum = n;
	g->arcnum = e;
	for(i = 0;i < n;i++)
	{
		scanf("%c",&(g->vertex[i].data));
		g->vertex[i].firstin = NULL;
		g->vertex[i].firstout = NULL;
	 } 
	 for(k = 0;k<e;k++)
	 {
	 	scanf("%c,%c",&vt,&vh);
	 	i = LocateVertex(g,vt);
	 	j = LocateVertex(g,vh);
	 	p = (ArcNode*)malloc(sizeof(ArcNode));
	 	p->tailvex = i;p->headvex = j;
	 	p->tlink = g->vertex[i].firstout;
	 	g->vertex[i].firstout = p;
	 	p->hlink = g->vertex[j].firstin;
	 	g->vertex[j].firstin = p;
	 }
}







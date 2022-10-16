#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0

typedef char ElemType ;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkQueueNode;

typedef struct 
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

//初始化
int InitQueue(LinkQueue *Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front != NULL)
		{
			Q->rear = Q->front;
			Q->front->next = NULL;
			return(OK);
		}
	else
		{
			return(ERROR);//溢出 
		}
}
int EnterQueue(LinkQueue *Q,ElemType x)//入列 
{
	LinkQueueNode *NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear=NewNode;
		return (OK);
	}
	else
		return ERROR;//溢出 
	
}
 
int DeleteQueue(LinkQueue *Q,ElemType *x)
 {
 	LinkQueueNode *p;
 	if(Q->front == Q->rear)
 		return(ERROR);
 	p = Q->front->next;
 	Q->front->next = p->next;
 	if(Q->rear == p)
 		Q->rear = Q->front;
 	*x = p->data;
 	free(p);
 	return(OK);
 }

main()
{
	LinkQueue *Q;
	ElemType c,*x;
	x = &c;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(Q);
	while((c = getchar()) != '$')
	{
		EnterQueue(Q,c);
		
	}
	while(Q->front != Q->rear)
	{
		DeleteQueue(Q,x);
		printf("%c",*x);
	}
	printf("\n");
	
		
	
}



 





 

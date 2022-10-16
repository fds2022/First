#include<stdio.h>
#define Elemdata char
#define TURE 1
#define ERROR 0
#include<malloc.h>
typedef struct Node
{
	Elemdata data;
	struct Node* next;
}Node,*LinkList;


void InitList(LinkList *L);
void CreateFromHead(LinkList L);
void createFromTail(LinkList L);
Node * GetData(LinkList L,int i);
Node *Locate(LinkList L,Elemdata e,int *i);
int ListLength(LinkList L);
int  InsList(LinkList L,int i,Elemdata e);
int DelList(LinkList L,int i,Elemdata *e);



main()
{
	Node L2,*L1,**L;
	
	L1 = &L2;
	L=&L1;
	Node *q;
	InitList(L);
//	CreateFromHead(*L);
	createFromTail(*L);
	for(q = (*L)->next;q->next!= NULL;q = q->next)
		printf("%c",q->data);
		printf("%c\n",q->data);
	int i,*mount = &i;
	scanf("%d",&i);
//	q = GetData(*L,i);
//	printf("%c\n",q->data);
	Elemdata e,*E=&e;
//	fflush(stdin);
//	scanf("%c",&e);
//	q = Locate(*L,e,mount);
//	if(q != NULL)
//	{
//		printf("%c,%d\n",q->data,*mount);
//	}
	
//	i = ListLength(*L);
//	printf("%d",i);
	
//	if(InsList(*L,i,e))
//		{
//			printf("OK\n");
//		}
	
		DelList(*L,i,E);
		for(q = (*L)->next;q->next!= NULL;q = q->next)
		printf("%c",q->data);
		printf("%c\n",q->data);
		printf("%c\n",*E);
}
void InitList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}
void CreateFromHead(LinkList L)
{
	Elemdata c;
	Node* s;
	while((c = getchar())!= '$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;	
		}
		
}
void createFromTail(LinkList L)
{
	Elemdata c;
	Node *rear = L,*s;
	while((c = getchar())!= '$' )
		{
			
			s = (Node *)malloc(sizeof(Node));
			s->data = c;
			s->next = rear;
			rear->next = s;//?
			rear = s;//?
		}
		rear->next = NULL;//?
}
Node * GetData(LinkList L,int i)
{
	int t = 1;
	if(i<=0)
		return NULL;
	while(L->next != NULL&& t != i)
	{
		L=L->next;
		t++;
	}
	L=L->next;
	if(t == i)
		{
			return L;
		}
	else	return NULL;
}
Node *Locate(LinkList L,Elemdata e,int *i)
{
	int j = 1;
	while(L != NULL && L->data != e)
		{
			L = L->next;
			j++;
		}
		if(L != NULL)
			{
				
				*i = j-1;
				return L;
			}
		else return NULL;
}
int ListLength(LinkList L)
{
	int i = 0;
	Node *q;
	q = L->next;
	while(q != NULL)
		{
			i++;
			q = q->next;
		}
		return i;
}
int  InsList(LinkList L,int i,Elemdata e)
{
	Node *q;
	q = L->next;
	if(i<0||i>ListLength(L))
		{
			return ERROR;
		}
	int k;
	for(k = 1;k<i;k++)
		{
			q = q->next;
			if(q == NULL)
				{
					return ERROR;
				}
		}
	Node *s;
	s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = q->next;
	q->next = s;
	
	return TURE;
}
int DelList(LinkList L,int i,Elemdata *e)
{
	if(i<1||i>ListLength(L))
		{
			return ERROR;
		}
	int k;
	Node*q = L->next,*s;
	for(k = 1;k < i-1;k++)
	{
		if(q == NULL)
			return ERROR;
		q = q->next;
	}
	*e = q->next->data;
	q->next = q->next->next;
	return TURE;
	
}
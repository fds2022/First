#include<stdio.h>
#define Elemdata char
#define TURE 1
#define ERROR 0
#define MAX 30

typedef struct 
{
	Elemdata data[MAX];
	int last;
}SeqList;


void InitList(SeqList*L); 
int ListLength(SeqList* L);
int ListLength(SeqList* L);
Elemdata GetData(SeqList*L,int i);
int InsList(SeqList*L,int i,Elemdata e);
int DelList(SeqList*L,int i,Elemdata *e);
int Locate(SeqList*L,Elemdata e);
int IsEmptyList(SeqList*L);
void In(SeqList*);


main()
{
	SeqList L1,*L;
	L = &L1;
	InitList(L);
	
	In(L);
	ListLength(L);
	int i;
	char e,*E = &e;
	scanf("%d",&i);
	printf("%c\n",GetData(L,i));
//	printf("�������λ����Ԫ��\n");
//	scanf("%d %c",&i,&e),
//	printf("%s",L->data);
//	InsList(L,i,e);
//	printf("%s",L->data);
//	printf("����ɾ��λ��\n");
//	scanf("%d",&i);
//	printf("%s",L->data);
//	DelList(L,i,E);
//	printf("%s",L->data);
	fflush(stdin);
	scanf("%c",&e);
	if(Locate(L,e))
		printf("OK");
	else
		printf("NO");
	if(IsEmptyList(L))
		printf("OK");
	else
		printf("NO");
	
}
void In(SeqList*L)
{
	int i = 0;
	Elemdata c;
	while(((c = getchar()) != EOF)&&i<=MAX-1)
		L->data[i]=c,i++;	
		L->last = i;
		
}
void InitList(SeqList*L)//��ʼ�� 
{
	L->last = -1;
}
int ListLength(SeqList* L)//�� 
{
	printf("��Ϊ%d\n",L->last);
	return L->last;
}
Elemdata GetData(SeqList*L,int i)//ȡ��Ԫ�� 
{
	i--;
	if(L->last==-1)
	{
			printf("�ձ�\n");
		return '/n';
	}
	
	if(i>-1&&i<=L->last)
	{
		return L->data[i];
			
	}
	else return '/n';
}
	
int InsList(SeqList*L,int i,Elemdata e)//iǰ���� 
{
	int k;
	i--;
	if(L->last >= MAX-1)
	{
		printf("����\n");
		return ERROR;
	}
	
	if(i<-1||i>L->last)
	{
		printf("����λ�ô���\n");
		return ERROR;
	}
		
	for(k = L->last;k>i;k--)
		{
			L->data[k + 1] = L->data[k];
			
		}
	L->data[i + 1] = e;
	L->last++;
	return TURE;
}
int DelList(SeqList*L,int i,Elemdata *e)//ɾ�� 
{
	i--;
	if(L->last== -1)
	{
			printf("�ձ�\n");
		return ERROR;
	}
	
	if(i<0||i>L->last)
	{
			printf("ɾ��λ�ò�����\n");
		return ERROR;
	}
	
		int k;
		*e = L->data[i];
	for(k = i;k<L->last;k++)
		L->data[k] = L->data[k+1];
	
	return TURE;
} 
int Locate(SeqList*L,Elemdata e)//���� 
{
	if(L->last == -1)
	{
		printf("�ձ�\n");
		return ERROR;
	}
		
	int i;
	for(i = 0;i<= L->last;i++)
	{
		if(L->data[i] == e)
			return TURE;
	}
	return ERROR;
			
}
int IsEmptyList(SeqList*L)//�Ƿ�� 
{
	if(L->last == -1)
		return TURE;
	else
		return ERROR;
}
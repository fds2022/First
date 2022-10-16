#define OK 1
#define ERROR 0
#define Type c
#include<stdio.h>
#include<malloc.h>
typedef char ElemType ;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;




void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}
/*ͷ�� */
int CreatFromHead(LinkList L)//L is Headpoint
{
	Node *p;
	char c;
	int flat = 1;
	printf("��������\n");
	while(flat)
	{  
		c = getchar();
		if(c != '$')
			{
				p = (Node *)malloc(sizeof(Node));
				p->data = c;
				p->next = L->next;
				L->next = p;
			}
		else flat = 0;
	}
	 
}
 //β��
 int CreatFromTail(LinkList L)
 {
 	Node *p,*r;
 	r = L;
 	char c;
 	int flat = 1;
 	fflush(stdin);
 	printf("��������\n");
 	while(flat)
 	{
 		//fflush(stdin);    fflush���ܷ���ѭ���� 
 	   	c = getchar();//ǰ������\n??? 
 		
 		if(c != '$')
 		{
 			p = (Node*)malloc(sizeof(Node));
			p->data = c;
			r->next = p;
			r = r->next;
		 }
		 else
		 	r->next = NULL,
		 	flat = 0;
			 
	 }
  } 
  //���ҵ�i���ڵ㣬���ظýڵ��ַ
  Node* GetData(LinkList L, int i)
  {
  	int j;
  	Node *p;
  	if(i<0) return NULL;
  	p = L;j = 0;
  	while((p->next != NULL)&&(j<i))
  	{
  		p = p->next;
  		j++;
	  }
	  if(i == j)
	  return p;
	  else
	  	return NULL;
  	
   } 
   //�������в���ֵΪkey�Ľڵ�λ��
   Node* Locate(LinkList L, ElemType key)
   {
   	Node *p;
   	p = L->next;
   	while(p->next!=NULL)
   		if(p->data != key)
   			p = p->next;
   		else
   			break;
   			p = p->next;
   		return p;
	} 
//�������� 
int ListLength(LinkList L)
{
	Node *p;
	p = L->next;
	int j = 0;
	while(p!= NULL)
	{
		p = p->next;
		j++;//0~j
	}
	return j;
 } 
 
 //���������,��i���ڵ�ǰ����� 
 int InsList(LinkList L,int i,ElemType e)
 {
 	Node *pre,*s;
 	int k;
 	if(i<=0) return ERROR;
 	pre = L;
 	k = 0;
 	while(pre != NULL&& k <i - 1)//FIND I - 1 Node
 	{
 		pre = pre->next;
 		k++;
	 }
	 if(pre == NULL)
	 	{
	 		printf("����λ�ò�����\n");
	 		return ERROR;
	 		
		 }
		 s = (Node *)malloc(sizeof(Node));
		 s->data = e;
		 s->next = pre->next;
		 pre->next = s;
		 return OK;
	 
  } 
  //������ɾ��
int DelList(LinkList L,int i,ElemType *e)
{
	Node *r,*pre;
	int k;
	pre = L;
	k = 0;
	while(pre->next != NULL && k < i-1)
	{
		pre = pre->next;
		k++;
	}
	if(pre->next == NULL)
		{
			printf("ɾ���ڵ�λ�ò�����\n");
			return ERROR;
			
		}
	r = pre->next;
	pre->next = r->next;
	*e = r->data;
	free(r);
	return OK;
}
   
 main()
{
	int k;
	Node Head;
	LinkList point = &Head;
	LinkList *L = &point;
	InitList(L);
	printf("�����ʼ���ɹ�\n");
	

	while(1)
	{
		int i,j;
		Node *q;
		ElemType b,*y;
		printf("��Ҫִ�еĲ�����\n1 ͷ�彨�� \t 2 β�彨�� \t 3 ����i�ڵ� \n4 ����keyֵ \t 5 �������� \t 6 iλ��ǰ����ڵ�\n");
		printf("7 ɾ��i�ڵ� \t 8 �˳�\n");
		fflush(stdin);
		scanf("%d",&k);
		switch(k)
		{
			case 1:CreatFromHead(*L);
					break;
			case 2: CreatFromTail(*L);
					break;
			case 3:printf("���ҵĵڼ����ڵ�\n");
					scanf("%d",&i);
					q = GetData(*L,i);
					if(q != NULL)
						printf("�ҵ��ýڵ�,data = %c\n",q->data);
					else
						printf("����\n");
					break;
			case 4:printf("����keyֵ\n");
					fflush(stdin);
					scanf("%c",&b);
					q = Locate(*L,b);
					if(q == NULL)
						printf("�Ҳ���\n");
					else
						printf("�ҵ�%c\n",b) ;
					break;
			case 5:i = ListLength(*L);
					printf("L��%d\n",i);
					break;
			case 6:printf("������i����������\n");
					fflush(stdin);
					scanf("%d",&i);
					gets(y);
					j = InsList(*L,i,*y);
					if(j)
						printf("����ɹ�\n");
					break;
			case 7:printf("������Ҫɾ���Ľڵ�\n");
					scanf("%d",&i);
					j = DelList(*L,i,y);
					printf("�ڵ�����Ϊ%Type\n",*y);
					if(j)
						printf("�ɹ�ɾ��\n");
					break;
			
		}
		if(k == 8)
			break;
	}
	//fqw perfect 22-03-22
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


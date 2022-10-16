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
/*头差 */
int CreatFromHead(LinkList L)//L is Headpoint
{
	Node *p;
	char c;
	int flat = 1;
	printf("输入数据\n");
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
 //尾插
 int CreatFromTail(LinkList L)
 {
 	Node *p,*r;
 	r = L;
 	char c;
 	int flat = 1;
 	fflush(stdin);
 	printf("输入数据\n");
 	while(flat)
 	{
 		//fflush(stdin);    fflush不能放在循环里 
 	   	c = getchar();//前面多出个\n??? 
 		
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
  //查找第i个节点，返回该节点地址
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
   //在链表中查找值为key的节点位置
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
//求链表长度 
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
 
 //单链表插入,在i个节点前面插入 
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
	 		printf("插入位置不合理\n");
	 		return ERROR;
	 		
		 }
		 s = (Node *)malloc(sizeof(Node));
		 s->data = e;
		 s->next = pre->next;
		 pre->next = s;
		 return OK;
	 
  } 
  //单链表删除
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
			printf("删除节点位置不合理\n");
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
	printf("链表初始化成功\n");
	

	while(1)
	{
		int i,j;
		Node *q;
		ElemType b,*y;
		printf("你要执行的操作是\n1 头插建表 \t 2 尾插建表 \t 3 查找i节点 \n4 查找key值 \t 5 求链表长度 \t 6 i位置前插入节点\n");
		printf("7 删除i节点 \t 8 退出\n");
		fflush(stdin);
		scanf("%d",&k);
		switch(k)
		{
			case 1:CreatFromHead(*L);
					break;
			case 2: CreatFromTail(*L);
					break;
			case 3:printf("查找的第几个节点\n");
					scanf("%d",&i);
					q = GetData(*L,i);
					if(q != NULL)
						printf("找到该节点,data = %c\n",q->data);
					else
						printf("错误\n");
					break;
			case 4:printf("输入key值\n");
					fflush(stdin);
					scanf("%c",&b);
					q = Locate(*L,b);
					if(q == NULL)
						printf("找不到\n");
					else
						printf("找到%c\n",b) ;
					break;
			case 5:i = ListLength(*L);
					printf("L表长%d\n",i);
					break;
			case 6:printf("请输入i与插入的数据\n");
					fflush(stdin);
					scanf("%d",&i);
					gets(y);
					j = InsList(*L,i,*y);
					if(j)
						printf("插入成功\n");
					break;
			case 7:printf("请输入要删除的节点\n");
					scanf("%d",&i);
					j = DelList(*L,i,y);
					printf("节点数据为%Type\n",*y);
					if(j)
						printf("成功删除\n");
					break;
			
		}
		if(k == 8)
			break;
	}
	//fqw perfect 22-03-22
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


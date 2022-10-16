 
#include<malloc.h>
#include<stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0 

typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int last ;//
	
} SeqList,*SL;

int charudata(SeqList *);
int switchlist(SeqList *,ElemType );
int deletlist(SeqList *SL,int j,ElemType *);

main()
{ 

 
SeqList *p;
p = (SL)malloc(sizeof(SeqList));
p->last = -1;//empty 
printf("插入你要写入的数据\n");
p->last = charudata(p);//插入数据 
/*
ElemType e,n;
printf("你要查找的数据\n");
scanf("%d",&e);
n = switchlist( p, e);
printf("%d",n);
*/
int j,i = 0,v;//v没啥卵用，用于指针初始化 
ElemType *x=&v;
printf("输入删除的位置\n");
scanf("%d",&j);
deletlist(p,j,x);
while(p->last--)
{
	printf("%d",p->data[i]);
	i++;
}
printf("\n");
printf("%d",*x);
}
//数组数据输入 并返回数据元素个数 
int charudata(SeqList *SL)
{

	int i=0;
	ElemType c = 0;
/*	while((c = getchar()) !=EOF)
	{
		SL->data[i] = c;
		i++;
	}
*/
while(1)
{
	scanf("%d",&c);
	if(c==-1)
	break;
	SL-> data[i]= c;
	i++;
}
	return(i);
}
//数组的查找 查找成功返回位置 
 int switchlist(SeqList *SL,ElemType e)
 {
 	if(SL->last == -1)
 	return(ERROR);
 	int i = 0;
 	while(SL->data[i] !=e&&i <= SL->last )
 		i++;
 		if(i>SL->last)
 		return(ERROR);
 		else
 			return i;
	 
 	
  } 
  //线性表的删除 成功返回ture 用指针e返回其值 
  int deletlist(SeqList *SL,int j,ElemType *x)
  {
  	if(SL->last==-1)
  		return(ERROR);
  	if(SL->last<j-1|| j-1 < 0 )//i是第几位，下标为j-1
	  return (ERROR);
	*x = SL->data[j-1];
		while(j != SL->last)
		{
			SL->data[j-1]=SL->data[j];
			j++;
		}
	SL->last--;
	return(OK);
  	
   } 
   //数据的插入 成功返回 OK 
   int  adddata(int i,ElemType e)
   {
   	if(i<0||i>MAXSIZE-1)
   		return ERROR;
   	if(i>=0&&i);
   }
   


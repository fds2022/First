 
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
printf("������Ҫд�������\n");
p->last = charudata(p);//�������� 
/*
ElemType e,n;
printf("��Ҫ���ҵ�����\n");
scanf("%d",&e);
n = switchlist( p, e);
printf("%d",n);
*/
int j,i = 0,v;//vûɶ���ã�����ָ���ʼ�� 
ElemType *x=&v;
printf("����ɾ����λ��\n");
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
//������������ ����������Ԫ�ظ��� 
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
//����Ĳ��� ���ҳɹ�����λ�� 
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
  //���Ա��ɾ�� �ɹ�����ture ��ָ��e������ֵ 
  int deletlist(SeqList *SL,int j,ElemType *x)
  {
  	if(SL->last==-1)
  		return(ERROR);
  	if(SL->last<j-1|| j-1 < 0 )//i�ǵڼ�λ���±�Ϊj-1
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
   //���ݵĲ��� �ɹ����� OK 
   int  adddata(int i,ElemType e)
   {
   	if(i<0||i>MAXSIZE-1)
   		return ERROR;
   	if(i>=0&&i);
   }
   


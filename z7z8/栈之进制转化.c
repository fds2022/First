#include<stdio.h>
#define StackSize 50
#define OK 1
#define ERROR 0
typedef int StackElemType;
typedef struct
{
	StackElemType elem[StackSize];
	int top;
}SeqStack;

SeqStack *S;

 void TransNember(StackElemType x,int a);

void InitStack(SeqStack *S)
{
	S->top = -1;
 }

 int  Push(SeqStack *S,StackElemType x)
 {
 	if(S->top==StackSize-1)
 		return ERROR;
 	S->top++;
 	S->elem[S->top] = x;
 	return OK;
 		
 }
 int Pop(SeqStack *S,StackElemType *x)
 {
 	if(S->top == -1)
 		return ERROR;
 	else
 		{
 			*x = S->elem[S->top];
 			S->top--;
 			return OK;
		 }
  }
  int GetTop(SeqStack *S,StackElemType *x)
  {
  	if(S->top == -1)
  		return ERROR;
  	else
  	{
  		*x = S->elem[S->top];
		  return OK;
		   
	  }
   } 
 int main()
 {
 	int jinzhi;
 	SeqStack q;
 	S = &q;
 	
 	InitStack(S);
 	StackElemType nember,*p = &nember;
 	printf("请输入个被转化的十进制数\n");
 	scanf("%d",&nember);
 	printf("转化成几进制\n");
 	scanf("%d",&jinzhi);
 	TransNember(nember,jinzhi);
 	while(S->top != -1)
 	{
 	Pop(S,p);
	 printf("%d",*p);	
	 }
	 
 	printf("\n");
 	
  } 
 void TransNember(StackElemType x,int a)
 {
 	int temp;
 	while(x != 0)
 	{
 	Push(S,x%a);
 	x = x/a;
    }
 }
  
  
  
  
  
  
  
  
  
  
  

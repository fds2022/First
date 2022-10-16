#include<stdio.h>
typedef int ElemType


typedef struct OLNode
{
	int row,col;
	ElemType value;
	struct OLNode *right ,*down;
}OLNode;*OLink;

typedef struct
{
	OLink *row_head,*col_head;
	int m,n,len;
}CrossList;

CreateCrossList(CrossList *M)
{
	scanf(&m,&n,&t);//Î´ÉùÃ÷
	M->m = m;M->n = n;M->len = t;
	if(!(M->row_head = (OLink *)malloc((m +1)sizeof(OLink)))) 
	exit(OVERFLOW);
	if(!(M->col_head = (OLink *)malloc((n+1)sizeof(OLink))))
	exit(OVERFLOW);
	M->row_head[] = M->col_head[] = NULL;
	for(scanf(&i,&j,&e))
	{
		if(!(p = (OLNode *)malloc(sizeof(OLNode))))
		exit(OVERFLOW);
		p->row = i;p->col= j;p->value = e;
		
		if(M->row_head[i] == NULL)
		M->row_head[i] = p;
		else if (p->col<M->row_head[i]->col)
		{
			p->right = M->row_head[i];
			M->row_head[i] = p;
		}
		else
		{
			for(q = M->row_head[i];q->right&&q->right->col<j;q = q->right);
			p->right = q->right;q->right = p;
		}
		if(M->col_head[j]==NULL)
		M->col_head[j]=p;
		else if(p->row<M->col_head[j]->row)
		{
			p->down = M->col_head[j];M->col_head[j]=p;
		}
		else
		{
			for(q = M->col_head[j];q->down&&q->down->row<i;q = q->down);
			p->down = q->down; q->down = p;
		}
	}

	
	
}

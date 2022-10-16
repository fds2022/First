typedef struct node
{
	KeyType key;
	struct node *lchild,*rchild;
}BSTNode, *BSTree;
void InsretBST(BSTree *bst,KeyType key)//¶þ²æÅÅÐòÊ÷²åÈëµÄµÝ¹éËã·¨ 
{
	BiTree s;
	if(*bst == NULL)
		{
			s = (BSTree)malloc(sizeof(BSTNode));
			s->key = key;
			s->lchild = NULL;s->rchild = NULL;
			*bst = s;
		}
		else if(key <(*bst)->key)
			InsertBST(&((*bst)->lchild),key);
		else if(key > (*bst)->key)
			InsertBST(&((*bst)->rchild),key);
}
void CreateBST(BSTree *bst)//´´½¨¶þ²æÅÅÁÐÊ÷ 
{
	KeyType key;
	*bst=NULL;
	scanf("%d",&key);
	while(key != END)
	{
		InsertBST(bst,key);
		scanf("%d",&key);
	}
}
BSTree SearchBST1(BSTree bst,KeyType key)//¶þ²æÅÅÐòÊ÷µÄµÝ¹éËã·¨ 
{
	if(!bst)  return NULL;
	else if(bst->key == key) return bst;
	else if(bst->key>key) return SearchBST(bst->lchild,key);
	else return SearchBST(bst->rchild,key);
}
BSTree SearchBST2(BSTree bst,KeyType key)
{
	BSTree q;
	q = bst;
	while (q)
	{
		if(q->key == key) return q;
		if(q->key>key) q = q->lchild;
		else q = q->rchild;
	}
	return NULL;
	
}
BSTree *DelBST(BSTree t,KeyType k)
{
	BSTNode *p,*f,*s,*q;
	p = t; f = NULL;
	while(p)
	{
		if(p->key == k) break;
		f = p;
		if(p->key>k)
		p = p->lchild;
		else p = p->rchild;
	}
	if(p == NULL) return t;
	if(p->lchild == NULL)
	{
		if(f == NULL) t = p->rchild;
		else if(f->lchild == p) f->lchild = p->rchild;
		else f->rchild = p->rchild;
		free(p);
	}
	else 
	{
		q = p;s = p->lchild;
		while(s->rchild)
			{
				q = s;
				s = p->lchild;
			} 
			if(q == p) q->lchild = s->lchild;
			else q->rchild = s->lchild;
			p->key = s->key;
			free(s);
	}
	return t;
}









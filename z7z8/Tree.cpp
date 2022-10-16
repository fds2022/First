#include<stdio.h>






typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNOde,*BITree;

//先序遍历
void PreOrder(BiTNode root)
{
	if(root != NULL)
	{
		visit(root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild); 
		
	}
 } 
 //中序遍历
 void PreOrder(BiTNode root)
{
	if(root != NULL)
	{
		PreOrder(root->LChild);
		visit(root->data);
		PreOrder(root->RChild); 
		
	}
 }  
 //后序遍历
 void PreOrder(BiTNode root)
{
	if(root != NULL)
	{
		PreOrder(root->RChild);
		visit(root->data);
		PreOrder(root->LChild);
		 
		
	}
 }  
 //遍历输出二叉树叶子结点  下面给出先序遍历输出二叉树叶子结点
 void PreOrder(BiTree root)
 {
 	if(root->LChild == NULL&&root->RChild == NULL)
 	{
	 
 		printf(root->data);//伪代码
		PreOrder(root->LChild);
		PreOrder(root->RChild);  
	}
  } 
  //统计叶子结点数目
  //给出后序遍历统计二叉树叶子结点数目
  void leaf(BITree root)
  {
  	if(root != NULL)
  	{
  		leaf(root->LChild);
		  leaf(root->RChild);
		  if(root->LChild == NULL&&root->RChild == NULL)
		  LeafCount++;		
	}
   } 
   //后序遍历统计二叉树叶子数目
  void leaf(BiTree root)
  {
 	 int LeafCount;
 	 if(root == NULL)
 	 	LeafCount = 0;
 	else if((root->LChild == NULL) && (root->RChild == NULL))
 		LeafCount = 1;
 	else 
 		LeafCount = leaf(root->LChild) + leaf(root->RChild);
 		return LeafCount;
   } 

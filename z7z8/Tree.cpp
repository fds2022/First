#include<stdio.h>






typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNOde,*BITree;

//�������
void PreOrder(BiTNode root)
{
	if(root != NULL)
	{
		visit(root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild); 
		
	}
 } 
 //�������
 void PreOrder(BiTNode root)
{
	if(root != NULL)
	{
		PreOrder(root->LChild);
		visit(root->data);
		PreOrder(root->RChild); 
		
	}
 }  
 //�������
 void PreOrder(BiTNode root)
{
	if(root != NULL)
	{
		PreOrder(root->RChild);
		visit(root->data);
		PreOrder(root->LChild);
		 
		
	}
 }  
 //�������������Ҷ�ӽ��  �����������������������Ҷ�ӽ��
 void PreOrder(BiTree root)
 {
 	if(root->LChild == NULL&&root->RChild == NULL)
 	{
	 
 		printf(root->data);//α����
		PreOrder(root->LChild);
		PreOrder(root->RChild);  
	}
  } 
  //ͳ��Ҷ�ӽ����Ŀ
  //�����������ͳ�ƶ�����Ҷ�ӽ����Ŀ
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
   //�������ͳ�ƶ�����Ҷ����Ŀ
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

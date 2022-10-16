#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define HASHSIZE 12
#define NULLKEY 0xffffffff/2

typedef int DataType;
typedef struct HashTable
{
	
	int *elem;
	int count;
} 

int InitHashTable(HashTable &pHashTable)
{
	pHashTable.count = 0;
	pHashTable,elem = int[HASHSIZE];
	for(int i = 0; i<HASHSIZE;++i)
		pHashTable.elem[i] = NULLKEY;
		return 1;
}
int Hash(int key)
{
	return key% HASHSIZE;
}
int InsertHashTable(HashTable &pHashTable,int key)
{
	int adddr = Hash(key);
	while(pHashTable.elem[addr] != NULLKEY)
		addr = (addr+1)%HASHSIZE;
		pHashTable.elem[addr] = key;
		pHashTable.count++;
		return 1;
}
int SearchHashTable(HashTable &pHashTable,int key,int *addr)
{
	*addrr = Hash(key);
	while(pHashTable.elem[*addr] != key)
	{
		*addr = (*addr + 1)%HASHSIZE;
		if(pHashTable.elem[*addr] == NULLKEY||*addr== Hash(key))
	
		return 0 ;
	}
	return 1;
}
int main()
{
	HashTable HashTable;
	InitHashTable(HashTable);
	int a[10] = {
		4,5,6,4,8,14,10,23,12,16
	};
	for(int i = 0;i<10;++i)
		{
			InsertHashTable(HashTable,a[i]);
		}
		printf("����������Ϊ��\n");
		
		for(int i= 0;i<10;i++)
		{
			printf("%4d",a[i]);
		}
	printf("\n������Ҫ����Ԫ�ص�ֵ��");
	 DataType locate;
	 scanf("%d",&locate);
	 int addr;
	 if(!SearchHashTable(HashTable,locate,&addr))
	 	printf("��Щ����û����Ҫ���ҵ���\n");
	 	else
	 		printf("��Щ��������Ҫ���ҵ�����Ԫ������λ��Ϊ:%d",addr);
}
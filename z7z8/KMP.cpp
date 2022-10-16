#include<stdio.h>
#define MAX 100
#define LEN 10
int next[LEN];

int SwitchKMP(char *q,char *p,int a);
void creatnext(char *a,int len);

main()
{
	int i = 0,len ;
	char c,q[MAX],p[LEN];
	printf("输入主字符串\n");
	while((c = getchar()) != EOF && i < MAX)
	{
		q[i] = c;
		i++;
	}
	if(i != MAX - 1)
	q[--i] = '/0';
	printf("输入子字符串\n");
	
	i = 0;
		while((c = getchar()) != EOF&&i < LEN)
	{
		p[i] = c;
		i++;
	}
	len = i-1;
	if(i != LEN - 1)
	p[--i] = '\0';
	int addr = 0;
	creatnext(p,len);
	addr = SwitchKMP(q,p,len);
}
int SwitchKMP(char *q,char *p,int a)
{
	int i= 0 ,j = 0;
	qwe:
	if(j == -1)
		i++,j++;
	while(q[i] == p[j] && q[i] != '\0'&&p[j] != '\0')
	{
		i++,j++;
	}
	
	if(j == a )
	{
	
		printf("找到\n");
		return i;
	}
	else if( q[i] == '\0')
	printf("没找到\n");
		
	else
		{
			j = next[j];
			goto qwe;
		}
}

void creatnext(char *a,int len)
{
	next[0] = -1;
	int j = 0,k = -1;
	while(j <len )
	{
		if(k == -1||a[j] == a[k])
			{
				j++,k++;
				next[j] = k;
			}
		else
		k = next[k];
	}
	
}







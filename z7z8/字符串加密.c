#include<stdio.h>
#include<string.h>

	char miwen[128] = {'\0'};
	char Text[128] = {'\0'};
int main(int argc,char *argv[])
{	FILE *fp;
	int result = 1;
	int i = 0;
	int count = 0;
	

	while (1)
	{
		if(result == 1)
		{
			
					void filecopy(FILE *,FILE *);
	if(argc == 1)
		filecopy(stdin,stdout);
	else
		while (--argc > 0)
		if((fp = fopen(*++argv,"r")) == NULL)
	{
		printf("cat : can't open %s \n",argv);
		return 1;
	}
	else 
	{
	filecopy(fp ,stdout);
	
			
			
			
		/*	printf("������Ҫ���ܵ����ģ�\n");
		/	scanf("%s",&Text);
		//	count = strlen(Text);
		//	for(i = 0;i < count;i++)
		//	{
		
		//		
		//	}  */
		for(i = 0;Text[i] != '\0';i++ )
		{
			miwen[i] = Text[i] + i + 5;
		
		}
			miwen[i] = '\0';
			
			printf("���ܺ�����ģ�%s\n",miwen);
		}
	}
		else if(result == 2)
		{
			count = strlen(Text);
			for(i = 0;i < count; i++)
			{
				Text[i] = miwen[i] - i - 5;
				
			}
			Text[i] = '\0';
			printf("���ܺ�����ģ�%s\n",Text); 
		}
		else if (result == 3)
		{
			break;
			
		}
		else 
	
		printf("��������ȷ���������\n");
		
	
	printf("����1�����µ����ģ�����2�Ըռ��ܵ����Ľ��н��ܣ�����3�˳�ϵͳ��\n");
	printf("�������������\n");
	scanf("%d", &result);
	fclose(fp);
			
		
	}
	return 0;
}

 void filecopy(FILE *ifp,FILE *ofp)
 {
 	int c,i = 0;
 	while ((c = getc(ifp)) != EOF)
	Text[i++] = c,
 	putc(c,ofp); 
	
 }
 
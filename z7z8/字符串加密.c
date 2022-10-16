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
	
			
			
			
		/*	printf("请输入要加密的明文：\n");
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
			
			printf("加密后的密文：%s\n",miwen);
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
			printf("解密后的明文：%s\n",Text); 
		}
		else if (result == 3)
		{
			break;
			
		}
		else 
	
		printf("请输入正确的命令符：\n");
		
	
	printf("输入1加密新的明文，输入2对刚加密的密文进行解密，输入3退出系统：\n");
	printf("请输入命令符：\n");
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
 
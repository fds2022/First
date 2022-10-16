#include<stdio.h>
#define MAX 100
main()
{
	int i = 0;
	char c,Text[MAX];
	printf("请输入密文\n");
	while((c =getchar()) != EOF)
		{
			Text[i] = c - i -5;
			i++;
		}
		Text[--i] = '\0';
		printf("明文\n%s\n",Text);
		return 0;
}

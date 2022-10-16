#include<stdio.h>
long Fib(int n)
{
	if(n == 1 || n==2) return n;
	else return (Fib(n-1)+Fib(n-2)); 
}
main()
{
	int n;
	scanf("%d",&n);
	long sum;
	sum = Fib(n);
	printf("%d",sum);
}
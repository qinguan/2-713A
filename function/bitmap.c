#include<stdio.h>
#include<string.h>

void main()
{
	int a=2;
	char b[]="1234";
	strcpy(b,b+2);
	printf("%s\n",b);
	printf("%d\n",a<<1);
	
}

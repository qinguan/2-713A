#include<stdio.h>
#include<assert.h>

void swap(char *p,char *q)
{
	char temp = *p;
	*p = *q;
	*q = temp;
}

void reverse(char *str)
{
	char *p = str;
	int i=0;
	while(*p)//&& *p != '\0') // if del *p != '\0' or while(p)  , the code run into Infinite loop, why ? because the p is a pointer which is not NULL.
		p++;
	p --;
	while(str < p)
	{
		swap(str++,p--);
	}
}

void main()
{
	char str[] = "abcdfg";
	reverse(str);
	printf("%s\n",str);
}

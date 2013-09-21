#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *p, char *q)
{
	char temp = *p;
	*p = *q;
	*q = temp;
}

char * reverse(char *str)
{
	char *head = str;
	char *last = str+strlen(str)-1;
	while(str < last)
		swap(str++,last--);
	return head;
}

int reverse_word(char *words)
{
	char *res=malloc(sizeof(strlen(words)+1));
	char *b = strtok(words," ");
	while(b!=NULL)
	{
		printf("%s\n",b);
		sprintf(res,"%s %s",b,res);
		b = strtok(NULL," ");
	}
	printf(reverse(res));
	return 0;
}
int main()
{
	char a[]  = "12 34 56";
	reverse_word(a);
}

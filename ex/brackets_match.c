#include<stdio.h>
#include<string.h>
#include<assert.h>

char * get_last_ptr(char * str)
{
	int n = strlen(str);
	return str + n - 1;
}

int match_count(char *str)
{
	int count=0;
	while(*str != '\0')
	{
		if(*str == '(')
			count ++;
		else if(*str == ')')
			count --;
		if(count <0)
			return 1;
		str ++;
	}
	if(count != 0)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char a[] = "(12))3";
	char b[] = "((()))";
	char c[] = "qw((k)KK";
	//printf("%s\n",get_last_ptr(a));
	assert( 1 == match_count(a));
	assert( 0 == match_count(b));
	assert( 1 == match_count(c));
}

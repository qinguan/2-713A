#include<stdio.h>
#include<string.h>

/**
 * The strirstr() function shall locate the last occurrence in the string pointed 
 * to by s1 of the sequence of bytes (excluding the terminating null byte) in the 
 * string pointed to by s2. 
 */
char* strrstr(char const *s1, char const *s2)
{
	char * last = NULL;
	char * curr;
	if(*s2 != '\0')
	{
		curr = strstr(s1,s2);
		while(curr != NULL)
		{
			last = curr;
			curr = strstr(curr+1,s2);
		}
	}
	return last;
}
int main()
{
	char *a="qwe er er ty";
	char *b="er";

	printf("%s\n",strrstr(a,b));
}

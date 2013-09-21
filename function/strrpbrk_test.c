#include<stdio.h>
#include<string.h>

/**
 *The strrpbrk function locates the last occurrence in the string pointed to by
 *s1 of any character from the string pointed to by s2, returning a pointer to
 *that character or a null pointer if not found.
 */
char *strrpbrk(char const *s1, char const *s2)
{
	char * last = NULL;
	char * curr;
	if(*s2 != '\0')
	{
		curr = strpbrk(s1,s2);
		while(curr!=NULL)
		{	
			last = curr;
			curr = strpbrk(last+1,s2);
		}
	}
	return last;
}

int main()
{
	char *a="qqw erw rgwt";
	char *b="rw";
	printf("%s\n",strrpbrk(a,b));
	
}

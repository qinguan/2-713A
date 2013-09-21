/*
 * Write a method to decide if two strings are anagrams or not.
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>

/*-----------------------O(nlgn)------------------------------------------*/
int cmp(char const *p, char const *q)
{
	return *p - *q;
}

int is_anagrams(char *p,char *q)
{
	qsort(p,strlen(p),sizeof(char),cmp);
	qsort(q,strlen(q),sizeof(char),cmp);
	return strcmp(p,q);
}
/*-----------------------O(n)------------------------------------------*/
int is_anagrams_2(char *p, char *q)
{
	int bitmap[256];
	int i;
	memset(bitmap,0,sizeof(bitmap));
	while(*p++)
	{
		bitmap[(int)*p] += 1;
	}
	while(*q++)
	{
		bitmap[(int)*q] -= 1;
	}
	for(i=0;i<256;i++)
	{
		if(bitmap[i] != 0)
			return -1;
	}
	return 0;
}

void main()
{
	char a[] = "qwe";
	char b[] = "qwr";
	assert(is_anagrams(a,b) < 0);
	assert(is_anagrams_2(a,b) == -1);
	char c[] = "cde";
	char d[] = "cde";
	assert(is_anagrams(c,d) == 0);
	assert(is_anagrams_2(c,d) == 0);
}

#include"../lib/basic.h"

/**
 * Write a method to sort an array of strings so that all the anagrams are next to each other.
 */

//int cmp_anagrams_str(char const *s1, char const *s2)
int cmp_anagrams_str(const void **s1, const void **s2)
{
	char p1[10],p2[10];
	strcpy(p1,*s1);
	strcpy(p2,*s2);
	printf("s1:%s\ts2:%s  == %d\n",*s1,*s2,is_anagrams(p1,p2));
	return is_anagrams(p1,p2);
}

int main()
{
	int i=0;
	char *str[]={"123","321","231","222","012","326","102"};
	qsort(str,7,sizeof(char *),cmp_anagrams_str);

	for(i=0;i<7;i++)
	{
		printf("%s\n",str[i]);
	}
	return 0;
}


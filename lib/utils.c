#include"basic.h"
void swap(t_type *p,t_type *q)
{
	t_type temp = *p;
	*p = *q;
	*q = temp;
}

int lib_cmp(const void *p, const void *q)
{
        return strcmp((char const *)p, (char const *)q);
}

/*
 * method to decide if two strings are anagrams or not.
 * O(nlgn). 
 * O(n) ../ex/1.4_anagrams.c: is_anagrams_2
 */
int is_anagrams(char *p,char *q)
{
	qsort(p,strlen(p),sizeof(char),lib_cmp);
	qsort(q,strlen(q),sizeof(char),lib_cmp);
	return strcmp(p,q);
}

int test_is_anagrams()
{
	char str1[]="123";
        char str2[]="231";
        char str3[]="230";
        assert(is_anagrams(str1,str2) == 0);
        assert(is_anagrams(str1,str2) != 0);
}


/**
 * sort the string array.
 */
int lib_str_cmp(const void *s1, const void *s2)
{
	return strcmp((*(char **)s1), (*(char **)s2));
}

int sort_string(char *str[],int len)
{
	qsort(str, len, sizeof(char *),lib_str_cmp);
}

int test_sort_string()
{
	char *str[]={"123","321","012","326","102"};
	int i;
	sort_string(str,5);
	for(i=0;i<5;i++)
		printf("%s\n",str[i]);
}

int _main()
{
	test_sort_string();
}

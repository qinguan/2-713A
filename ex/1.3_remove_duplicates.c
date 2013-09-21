#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static int strcmp_p(const void *p1, const void *p2)
{
//	return strcmp(* (char * const *) p1, * (char * const *) p2); //error
	return strcmp((char const *)p1, (char const *)p2); //ok
//	return *(char *)p1 - *(char *)p2;   //ok
}

//error
char * remove_duplicate2(char * str)
{
	char *p,*q;
	p=q=str;
	while(*p)
	{
		p++;
		while(*p == *str)
		{
			p++;
		}
		strcpy(str,p);
	}
	return q;
}

//ok
char* del(char* s)
{
    char* ret = s; // 做为返回指针
    char* end = s; // 修改后的结束
 
    while (*end = *s++) {   //  复制后，使两个指针相邻
        while (*end == *s)  // 如果连续两个字符重复，源指针加1抛弃一个字符
            s++;
        end++;
    }
    *end = '\0'; // 封闭目标字串
    return ret;
}

void main()
{
	char a[]="bqakkwzygg";
	char *b;
	qsort(a,10,sizeof(char), strcmp_p); // sizeof(char *) segmentation fault, why ?
	printf("%s\n",a);
	b=remove_duplicate2(a);
	printf("%s\n",b);
//	b=del(a);
//	printf("%s\n",b);
}

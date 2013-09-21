#include<stdio.h>
#include<assert.h>
#include<string.h>

void swap(char *p,char *q)
{
        char temp = *p;
        *p = *q;
        *q = temp;
}

int reverse(char *p,int start,int end)
{
        char temp;
        for(;start < end;){
		swap(p+start,p+end);
                end --;
                start ++;
        }
        return 0;
}

int rorate(char *s,int sep){
        int len=strlen(s);
        if (len == 0){
                return -1;
        }
        sep = sep % len;
        reverse(s,0,sep-1);
        reverse(s,sep,len-1);
        reverse(s,0,len-1);
        return 0;
}

int is_equal(char *src, char *dst)
{
	while(*src && (*src==*dst))
        	src++,dst++;
	return *(const unsigned char*)src-*(const unsigned char*)dst;
}

int is_roration_str(char *src, char *dst)
{
	int i;
	char *p=src;
	for(i=0;i<strlen(src);i++)
	{
		p=src;
		rorate(p,i);
		if(!is_equal(p,dst))
			return 0;
	}
	return -1;
}
/*--------------------------------------------------------------------------*/
int is_roration_str2(char *src, char *dst)
{
	strcat(src,src);
	if(strstr(src,dst))
	{
		return 0;
	}
	return -1;
}

void main()
{
	char a[] = "qwert";
	char b[] = "wertq";
	char c[] = "1234";
	char d[] = "1235";
	assert(is_roration_str2(a,b) == 0);
	printf("%s\n",a);
	assert(strcmp(a,b) < 0);
	assert(strcmp(c,d) < 0);
	assert(is_equal(a,b) < 0);
	assert(is_equal(c,d) < 0);
	
	assert(is_roration_str(a,b) == 0);
	assert(is_roration_str(c,d) == -1);
}

#include<stdio.h>
#include<string.h>
#include<assert.h>

int is_unique_char(char *p)
{
	int i;
	char bitmap[256] = {0};
	
	for( ; p != NULL && *p != '\0'; p++)
	{
		i = (int)*p;
		if(bitmap[i] == 1)
			return -1;
		bitmap[i] = 1;
	}	
	return 0;
}

int is_unique_char2(char *p)
{
	int i;
	int  bitmap[8];
	memset(bitmap, 0, sizeof(bitmap));
	while(p != NULL && *p != '\0')
	{
		i = (int)*p;
		if(bitmap[i/32] & (1 << i%32))
			return -1;
		bitmap[i/32] |= 1 << i%32;
		p++;
	}	
	return 0;
}

void main()
{
	char a[] = "qwerr";
	assert(is_unique_char(a) == -1);
	assert(is_unique_char("defr") == 0);
	assert(is_unique_char("defrr") == -1);
	assert(is_unique_char2("defrr") == -1);
	assert(is_unique_char2("defr") == 0);
}

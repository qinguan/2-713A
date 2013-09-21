#include<stdio.h>

int num2binary(int num)
{
	int last=0;
	while (num)
	{
		last += num & 0x01;
		num >>= 1;
	}
	return last;
}


int main()
{
	printf("%d\n",num2binary(3));
	printf("%x\n",1999999999);
	printf("%x\n",3);
}

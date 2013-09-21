#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "hhhh kkk dede";
	char * ans;
	ans = strpbrk(str,"e");
	printf("%s\n",ans);
}


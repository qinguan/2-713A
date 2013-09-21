#include<stdio.h>
#include<string.h>

int reverse(char *p,int start,int end);
int rorate(char *s,int sep);

int reverse(char *p,int start,int end)
{
	char temp;
	for(;start < end;){
		temp = *(p+start);
		*(p+start) = *(p+end);
		*(p+end) = temp;
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

int main(){
	char a[]="12345678";
//	reverse(a,4,7);
//	printf("%s\n",a);
	rorate(a,9);
	printf("%s\n",a);
}

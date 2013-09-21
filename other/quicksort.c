#include<stdio.h>

void swap(char *p,char *q)
{
	char temp;
	temp = *p;
	*p = *q;
	*q = temp;
	
	return;
}

int partition(char *p,int start,int end)
{
	char key = *(p+end);
	int i=start-1;
	int j;
	for(j=start;j<end;j++)
	{
		if(*(p+j) <= key)
		{
			swap(p+i,p+j);
			i++;
		}
		
	}
	swap(p+i,p+end);
	return i;
}

void quicksort(char *p, int start, int end)
{
	int k;
	while(start < end)
	{
		k = partition(p,start,end);
		printf("%d\t%s\tstart:%d,end:%d\n",k,p,start,end);
		quicksort(p,start,k);
		quicksort(p,k+1,end);
	}
}

int main()
{
	char a[]="53278614";
//	swap(a+1,a+3);
//	printf("%s\n",a);
//	partition(a,1,7);
	quicksort(a,1,7);
	printf("%s\n",a);
}

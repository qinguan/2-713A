#include"../lib/basic.h"

/**
 * You are given two sorted arrays, A and B, and A has a large enough buffer at
 * the end to hold B. Write a method to merge B into A in sorted order.
 */
void merge_sorted_array(int a[],int b[],int m,int n)
{
	int len = m+n-1;
	int i=m-1,j=n-1;
	while(i>=0 && j>=0)
	{
		if(a[i] >= b[j])
			a[len--] = a[i--];
		else
			a[len--] = b[j--];
	}
	while(j >=0)  a[len--] = b[j--];
}

/**
 * a[0..mid-1]  a[mid..len-1] are in order. you should merge them without other space.
 */
void merge_sorted_array_2(int a[],int start, int mid, int end)
{
	int i,j;
	mid = mid -1;
	end = end -1;
	for(i=start;i<mid;i++){
		if(a[i]>a[mid])
		{
			swap(a+i,a+mid);
			for(j=mid;j<end;j++)

			{
				if(a[j]>a[j+1])
					swap(a+j,a+j+1);
			}
		}
	}
}


void print_array(t_type arr[],int len)
{
	while(len>0) printf("%d\t",arr[--len]);
	printf("\n");
}
int main()
{
	int a[20]={1,3,5,7,9};
	int b[]={2,4,6,8};
	int c[]={1,4,6,7,10,2,3,7,9};
//	merge_sorted_array(a,b,5,4);
	merge_sorted_array_2(c,0,6,9);
	print_array(c,9);
	return 0;
}


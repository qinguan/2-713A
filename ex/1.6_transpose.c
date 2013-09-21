/*
 * Given an image represented by an NxN matrix, where each pixel in the image
 *  is 4 bytes, write a method to rotate the image by 90 degrees. 
 *  Can you do this in place?
 *  
 *  1    2    3    4
 *  5    6    7    8
 *  9   10   11   12
 *  13  14   15   16
 *
 *  to
 *
 *  4    8   12   16
 *  3    7   11   15
 *  2    6   10   14
 *  1    5   9    13
 */
#include<stdio.h>

void swap(int *p,int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void rorateleft(int a[][4], int n)
{
	int i,j;
	for (i=0; i<n; i++ )
	{
		for (j=i+1;j<n;j++)
		{
			swap(&a[i][j],&a[j][i]);
		}
	}
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n;j++)
		{
			swap(&a[i][j],&a[n-1-i][j]);
		}
	}
}

int main()
{
	int i,j;
	int a[][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	rorateleft(a,4);

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

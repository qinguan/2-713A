/*
 * Write an algorithm such that if an element in an MxN matrix is 0, 
 * its entire row and column is set to 0.
 */
#include<stdio.h>
#define NUM 4

void zero(int a[][4],int n)
{
	int i,j;
	int row[NUM]={0};
	int col[NUM]={0};
	for(i=0; i<4; i++)
	{
		for(j=0; j<n; j++)
		{
			if(a[i][j] == 0)
			{	
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(row[i] || col[j])
				a[i][j] = 0;
		}
	}
}
void main()
{
	int i,j;
        int a[][4] = {
                {0,2,3,4},
                {5,6,7,8},
                {9,10,0,12},
                {13,14,15,16}
        };
        zero(a,4);

        for(i=0;i<4;i++)
        {
                for(j=0;j<4;j++)
                {
                        printf("%d\t",a[i][j]);
                }
                printf("\n");
        }
}

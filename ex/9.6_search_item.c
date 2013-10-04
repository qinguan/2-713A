#include"../lib/basic.h"

/**
 * Given a matrix in which each row and each column is sorted, 
 * write a method to find an element in it.
 */


int matrix[][5] = 
	{
		{1, 2, 3, 4, 5},
		{3, 7, 8, 9, 11},
		{5, 9, 10, 17, 18},
	//	{7, 12, 15, 19, 23},
		{9, 13, 16, 20, 25}
	};

int search(int col, int row, int item)
{
	int i=0,j=row-1;
	while(i < col && j >= 0)
	{
		if(matrix[i][j] == item)
			return 0;
		else if(matrix[i][j] > item)
			j--;
		else
			i++;
	}
	return -1;
}

int main()
{
	assert(search(5,5,3) == 0);
	assert(search(5,5,25) == 0);
	assert(search(5,5,0) == -1);
	assert(search(5,5,30) == -1);
	assert(search(5,5,23) == -1);
	return 0;
}


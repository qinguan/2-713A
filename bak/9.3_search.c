#include"../lib/basic.h"

/**
 * Given a sorted array of n integers that has been rotated an unknown number of times, 
 * give an O(log n) algorithm that finds an element in the array. You may assume that 
 * the array was originally sorted in increasing order.
 *
 * EXAMPLE:
 *
 * Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 *
 * Output: 8 (the index of 5 in the array)
 */

int search(int a[],int begin,int end,int item)
{
	int mid = begin + (end - begin)/2;
	
	if(item > a[mid] && item <= a[end])
	{
		return search(a,mid+1,end,item);
	}
	else if (item > a[mid] && item > a[end])
	{
		return search(a,begin,mid,item);
	}
	//else if (item == a[end])
	//	return end;
	else if(item < a[mid])
	{
		return search(a,begin,mid,item);
	}
	else
		return mid;

}

int search_(int a[], int low, int high, int x){
    while(low <= high){
        int mid = low + (high - low)/2;
        if(a[mid] == x) return mid;
        if(a[mid] >= a[low]) {
            if(x<a[mid] && x>=a[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if(x>a[mid] && x<a[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}


int main()
{
	int a[12] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	assert(search(a,0,11,5) == 8);
	assert(search(a,0,11,19) == 2);
	assert(search(a,0,11,15) == 0);
	assert(search(a,0,11,10) == 10);
	assert(search(a,0,11,14) == 11);
	return 0;
}


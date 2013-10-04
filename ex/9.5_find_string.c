#include"../lib/basic.h"
/**
 * Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
 * Example: 
 * find "ball" in ["at", "", "", "", "ball", "", "", "car", "","", "dad", "", ""] will return 4
 * Example: 
 * find "ballcar" in ["at", "", "", "", "", "ball", "car", "", "", "dad", "", ""] will return -1
 */

int find_string(char *str_list[], int len, char *key)
{
	int i=0;
	while(i < len)
	{
		if( strcmp(str_list[i],key) == 0)
		{
			return i;
		}
		i ++;
	}
	return -1;
}

int binary_search_str(char *str_list[],int begin,int end, char *key)
{
	if(strcmp(key,"") == 0)
		return 0;
	while (begin < end)
	{
		int mid = begin + (end - begin)/2;
		int last = mid;
		while(mid <= end && strcmp(str_list[mid],"") == 0)
			mid +=1;
		if(mid > end)
			end = last;
		else if(strcmp(str_list[mid],key) == 0)
			return mid;
		else if((strcmp(str_list[mid],key) < 0))
			begin = mid + 1;
		else
			end = mid - 1;
		
	}
	return -1;
}

int main()
{
	char *str[] = {"12","","","32","","","56"};
	char key[] = "32";
	assert(find_string(str,7,key) == 3);
	assert(find_string(str,7,"12") == 0);
	assert(find_string(str,7,"56") == 6);
	
	assert(binary_search_str(str,0,7,"12") == 0);
	assert(binary_search_str(str,0,7,"22") == -1);
	assert(binary_search_str(str,0,7,"32") == 3);
	assert(binary_search_str(str,0,7,"56") == 6);
	assert(binary_search_str(str,0,7,"57") == -1);
	return 0;
}


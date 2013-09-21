#include<stdio.h>

void swap(char *p,char *q)
{
        char temp;
        temp = *p;
        *p = *q;
        *q = temp;

        return;
}

int partition(char *str,int lo,int hi)   
{  
    int key = *(str+hi);      //�����һ��Ԫ�أ�data[hi]Ϊ��Ԫ  
    int i = lo - 1; 
    int j; 
    for(j = lo; j < hi; j++) ///ע��j��pָ�����r-1������r��  
    {  
        if( *(str+j) <= key)  
        {  
            i++;  
	    swap(str+i,str+j);
        }  
    }  
    swap(str+i+1, str+hi);    //���ܸ�Ϊswap(&data[i+1],&key)  
    return i + 1;   
} 

void quicksort(char *str, int lo, int hi)  
{ 
    int k; 
    if (lo < hi)  
    {  
        k = partition(str, lo, hi);  
        quicksort(str, lo, k - 1);  
        quicksort(str, k + 1, hi);  
    }  
} 

main()
{
	char *p = "3512564";
	quicksort(p,1,7);
	printf("%s\n",p);
}

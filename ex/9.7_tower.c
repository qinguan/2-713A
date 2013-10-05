/**
 * A circus is designing a tower routine consisting of people 
 * standing atop one another¡¯s shoulders. For practical and 
 * aesthetic reasons, each person must be both shorter and 
 * lighter than the person below him or her. Given the heights 
 * and weights of each person in the circus, write a method 
 * to compute the largest possible number of people in such a tower.
 *
 * EXAMPLE:
 *
 * Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
 *
 * Output: The longest tower is length 6 and includes from top to bottom: 
 * (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
 *
 */

#include"../lib/basic.h"

struct person{
	int height;
	int weight;
}list[20];

int cmp(const void *p1, const void *p2)
{
	int diff = (*(struct person *)p1).height - (*(struct person *)p2).height;
	if( diff == 0 )
		return (*(struct person *)p1).weight - (*(struct person *)p2).weight;
	else
		return diff;
}

int get_max_person(struct person list[], int len)
{
	int i,j,max;
	int d[len];
	for(i=0;i<len;i++)
	{
		d[i]=1;
		for(j=0;j<i;j++)
		{
			if(list[i].weight > list[j].weight && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
			}
		}
	}
	max = d[0];
	for(i=0;i<len;i++)
	{
		if(d[i] > max)
			max = d[i];
	}
	return max;
}

int main()
{
	int i=0,j=0,max;
	int h,w;
	freopen("data.in","r",stdin);
	while(scanf("%d,%d",&h,&w)!=EOF)
	{
		list[i].height = h;
		list[i].weight = w;
		i++;
	}
	qsort(list,i,sizeof(list[0]),cmp);
	max = get_max_person(list,6);
	printf("%d\n",max);
	i--;
	while(i>=0)
	{
		printf("%d,%d\n",list[i].height,list[i].weight);
		i--;
	}
	
	
	return 0;
}


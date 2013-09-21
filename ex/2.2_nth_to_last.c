/**
 *Implement an algorithm to find the nth to last element of a singly linked list.
 *
 * gcc 2.2_nth_to_last.c ../lib/list.c ../lib/list.h -g -o 2.2_nth_to_last
 */
#include"../lib/list.h"

struct node * nth_to_last(struct node *list, int n)
{
	int len;
	struct node * tmp = list;
	if(list == NULL) return NULL;
	len = len_list(tmp);
	if(len < n) return NULL;
	
	while(len-- - n >0) 
		list = list->next;

	return list;
}

struct node *nth_to_last_2(struct node *list,int n)
{
	struct node *p,*q;
	p = q = list;
	while(q && n-- >0)
		q = q->next;
	if(n>0) return NULL;
	while(q)
	{
		q=q->next;
		p=p->next;
	}
	return p;
}

int main()
{
	struct node * res = NULL, *q;
	push_node(&res,2);
	push_node(&res,4);
	push_node(&res,7);
	push_node(&res,8);
	print(res);
	//nth_to_last(res,2);
	q=nth_to_last_2(res,2);
	printf("data: %d\n",q == NULL ? -1 : q->data);

}


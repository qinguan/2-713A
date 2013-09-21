#include"../lib/basic.h"

/**
 * You have two numbers represented by a linked list, where each node contains
 * a single digit. The digits are stored in reverse order, such that the 1¡¯s
 * digit is at the head of the list. Write a function that adds the two
 * numbers and returns the sum as a linked list.
 */

/**
 * gcc -g ../lib/basic.h ../lib/list.c 2.4_add_link.c -o 2.4_add_link
 */
struct node *add_link(struct node *a, struct node *b)
{
	struct node *c = NULL;
	t_type tmp = 0;
	int flag = 0;
	if(a == NULL && b == NULL) return NULL;
	if(a == NULL) return b;
	if(b == NULL) return a;

	while(a && b)
	{
		tmp = a->data + b->data + flag;
		flag = 0;
		if(tmp >= 10)
		{
			tmp -= 10;
			flag = 1;
		}
		push_node(&c,tmp);
		a = a->next;
		b = b->next;
	}
	while(a != NULL){
		push_node(&c,a->data + flag);
		a=a->next;
		flag = 0;
	}
	while(b != NULL){
		push_node(&c,b->data +flag);	
		b=b->next;
		flag=0;
	}
	if(flag == 1) push_node(&c,flag);
	return c;
}

int main()
{
	t_type a[]={5,1,3};
	t_type b[]={1,5,9,5};
	struct node *p1 = init_list_data(a,3);
	struct node *p2 = init_list_data(b,4);
	struct node *res = add_link(p1,p2);
	print(p1);
	print(p2);
	print(res);
	return 0;
}


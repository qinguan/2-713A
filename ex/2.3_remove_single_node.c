#include"../lib/basic.h"

/**
 * Implement an algorithm to delete a node in the middle of a single linked 
 * list, given only access to that node.
 */


/**
 * if delptr is the last node of list, it couldn't be deleted. you can set it with special character which shouldn't be print.
 */
void remove_single_node(struct node *delptr)
{
	struct node *temp;
	if(delptr == NULL) 
		return;
	else if(delptr->next == NULL) 
		delptr = NULL;
	else if(delptr->next != NULL){
		temp = delptr->next;
		delptr->data = temp->data;
		delptr->next = temp->next;
		free(temp);
	}
}

int main()
{
	struct node *head=NULL;
	struct node * delptr=NULL;
	head = init_list();
/*	push_node(&head,9);
	push_node(&head,8);
	push_node(&head,7);
	push_node(&head,6);
*/	print(head);
	delptr = head;
	delptr = delptr->next->next;
	//delptr = delptr->next;
	printf("%d\n",delptr->data);
	remove_single_node(delptr);
	print(head);
	return 0;
}


#include"list.h"

void push_node(struct node ** head, t_type data)
{
	struct node * new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}
int len_list(struct node *head)
{
	int count=0;
	while(head != NULL){
		head = head->next;
		count++;
	}
	return count;
}
void print(struct node *head)
{
	while(head != NULL){
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n");
}

struct node *init_list()
{
	struct node * head = NULL;
	push_node(&head,2);
	push_node(&head,1);
	push_node(&head,3);
//	print(head);
	assert(len_list(head) == 3);
	return head;
}

struct node *init_list_data(t_type data[],int len)
{
	struct node * head = NULL;
	int i=0;
	while(i<len)
		push_node(&head,data[i++]);
//	push_node(&head,data[1]);
//	push_node(&head,data[2]);
//	print(head);
	assert(len_list(head) == len);
	return head;
}

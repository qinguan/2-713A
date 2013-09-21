/*
 * Write code to remove duplicates from an unsorted linked list.
 *
 * FOLLOW UP
 *
 * How would you solve this problem if a temporary buffer is not allowed?
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct Tag{
	int data;
	struct Tag *next;
}Node;

void print(Node *head);

Node * create_link_list(int *a,int len)
{
	Node *head;
	Node *tail;
	head = tail =  malloc(sizeof(Node));

	while(len -- >0)
	{
		tail->data = *a;
		tail->next = malloc(sizeof(Node));
		a++;
		tail = tail->next;
	}
	tail = NULL;
	return head;
}

void add_node_to_list(Node ** head, int data)
{
	Node * temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

Node * build_list(int a[], int len)
{
	Node * head = malloc(sizeof(Node));
	int i;
	for(i=0; i<len; i++)
	{
		add_node_to_list(&head,a[i]);
	}
	return head;
}

void remove_depulicate_node(Node *head)
{
	Node *p,*q,*s,*temp;
	if(head == NULL)
		return;

	q = head;
	while(q)
	{
		s=q; 
		p=q->next;
		while(p)
		{
			if(p->data == s->data)
			{
				temp = p;	
				s->next=p->next;
				p=s->next;
				free(temp);
			}
			else
			{
				s=p;
				p=p->next;
			}
		}
		q=q->next;
		print(q);
	}
}

void print(Node *head)
{
	while(head!=NULL)//the last one is 0, which is excess. why ?
	{
		printf("%d",head->data);
		head = head->next;
	}
	printf("\n");
}


main()
{
	int a[] = {2,3,2,1};
	int i,len;
	
	len = sizeof(a)/sizeof(a[0]);
	Node *b = create_link_list(a,len);
	Node *c = malloc(sizeof(Node));
	//c->data = 1;
	//add_node_to_list(&c,2);
	c=build_list(a,len);
	//print(b);
	//remove_depulicate_node(b);
	print(c);
	//print(b);
}


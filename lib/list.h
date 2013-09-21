#include"basic.h"

void push_node(struct node ** head, t_type data);
int len_list(struct node *head);
void print(struct node *head);

struct node *init_list();
struct node *init_list_data(t_type data[],int len);

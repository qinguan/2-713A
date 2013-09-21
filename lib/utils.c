#include"basic.h"
void swap(t_type *p,t_type *q)
{
	t_type temp = *p;
	*p = *q;
	*q = temp;
}



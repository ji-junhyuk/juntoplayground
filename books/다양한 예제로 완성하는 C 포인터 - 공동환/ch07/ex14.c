#include <stdio.h>
struct _node
{
	int data;
	struct _node *link;
};

int main()
{
	struct _node n5 = {50, NULL}, n4 = {40, NULL}, n3 = {30, NULL}, n2 = {20, NULL}, n1 = {10, NULL};
	struct _node *p = NULL;

	p = &n1;
	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	printf("%p %p %p %p %p %p\n", &p, &n1, &n2, &n3, &n4, &n5);

	printf("%d\n", p->data);	p = p->link;
	printf("%d\n", p->data);	p = p->link;
	printf("%d\n", p->data);	p = p->link;
	printf("%d\n", p->data);	
}

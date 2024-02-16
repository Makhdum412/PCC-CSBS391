#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,power;
	struct node *next;
};
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("(%dx^%d)",head->coef,head->power);
		head=head->next;
        if(head!=NULL)
                printf("+");
	}
}
void addpoly(struct node *head1,struct node *head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->power>head2->power)
		{
			printf("(%dx^%d)",head1->coef,head1->power);
			head1=head1->next;
            if(head1!=NULL)
                printf("+");
		}
		else if(head2->power>head1->power)
		{
			printf("(%dx^%d)",head2->coef,head2->power);
			head2=head2->next;
            if(head2!=NULL)
                printf("+");
		}
		else
	

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct Node *next;
};
struct node *insert(struct node *head,int y)
{	struct node *p=head,*q=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{	q->next=NULL;
		q->info=y;
		return q;
	}
	while(p->next!=NULL)
	{	p=p->next;
	}
	q->next=NULL;
	q->info=y;
	p->next=q;
	return head;
}
struct node *createlist(struct node *head,int size)
{	
	int item,i;
	for(i=1;i<=size;i++)
	{	printf("\nenter element %d=",i);
		scanf("%d",&item);
		head=insert(head,item);
	}
	return head;
}
int length(struct node *head)
{
	int k;
	struct node *p=head;
	if(p==NULL)
	{
		return 0;
	}
	return (1+length(p->next));
}
int main()
{
	int s;
	struct node *head=NULL;
	printf("\nenter the size of list");
	scanf("%d",&s);
	struct node *head1=createlist(head,s);
	printf("\nlength of list is %d",length(head1));
	return 0;
} 

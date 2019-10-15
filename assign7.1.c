#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *insert(struct node *head,int x)
{
	struct node *q=(struct node*)malloc(sizeof(struct node)),*p=head;
	q->next=NULL;
	q->info=x;
	if(head==NULL)
		return q;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	return head;
}
struct node *createlist(struct node *head,int size)
{
	int i,item;
	for(i=1;i<=size;i++)
	{
		printf("\nenter the element ");
		scanf("%d",&item);
		head=insert(head,item);
	}
	return head;
}
struct node *splitmerse(struct node *head,int size)
{
	struct node *p=head;
	int k=1;
	while(k!=((size/2)))
	{
		p=p->next;
		k++;
	}
	struct node *q=p->next;
	struct node *head2=q;
	p->next=NULL;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=head;
	return head2;
}
void display(struct node *head2)
{
	struct node *p=head2;
	if(head2==NULL)
	printf("\nlist is empty");
	else 
	{
		printf("\nsplit and merse list is \n");
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
        }
}
int main()
{
	int s;
	struct node *head=NULL;
	printf("\nenter size of list ");
	scanf("%d",&s);
	head=createlist(head,s);
	struct node *head2=splitmerse(head,s);
	display(head2);
	return 0;
}

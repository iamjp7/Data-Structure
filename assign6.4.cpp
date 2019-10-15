#include<stdio.h>
#include<stdlib.h>
struct node
{
		int info;
		struct node *next;
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
struct node *create(struct node *head,int size)
{	int item,i;
	
	for(i=1;i<=size;i++)
	{	printf("\nenter element %d=",i);
		scanf("%d",&item);
		head=insert(head,item);
	}
	return head;
}
struct node *del(struct node *head)
{	if(head==NULL)
	{
		printf("list is empty");
		return NULL;
	}
	struct node *q,*p=head;
	while(p->next!=NULL)
	{
			q=p->next;
			p->next=q->next;
			free(q);
			
		p=p->next;	
	}
	return head;
}
void display(struct node *head)
{	struct node *p=head;
	while(p!=NULL)
	{	printf("%d ",p->info);
		p=p->next;
	}
}
int main()
{	
	int s;
	printf("\nenter the size of list ");
	scanf("%d",&s);
	struct node *head=NULL;
	struct node *head1=create(head,s);
	struct node *h=del(head1);
	display(h);
	return 0;
}

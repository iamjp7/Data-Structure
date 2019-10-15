#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *insert(struct node *head,int y)
{
	struct node *q=(struct node*)malloc(sizeof(struct node)),*p=head;
	if(head==NULL)
	{
		q->next=NULL;
		q->info=y;
		return q;
	}
	while(p->next!=NULL)
	{
		p=p->next;
	}
	q->next=NULL;
	q->info=y;
	p->next=q;
	
	return head;	
}
struct node *create(struct node *head,int size)
{
	int i,item;
	for(i=1;i<=size;i++)
	{
		printf("\nenter the element %d=",i);
		scanf("%d",&item);
		head=insert(head,item);
	}
	return head;
}
struct node *merge(struct node *head1,struct node *head2,struct node *head3)
{
	struct node *p=head1,*q=head2;
	while(p!=NULL && q!=NULL)
	{
		if(p->info < q->info)
		{
		head3=insert(head3,p->info);
		p=p->next;
		}
		else if(p->info > q->info)
		{
		head3=insert(head3,q->info);
		q=q->next;
		}
		else if(p->info==q->info)
		{
			head3=insert(head3,p->info);
			head3=insert(head3,q->info);
			p=p->next;
			q=q->next;
		}
	}
	
	if(p==NULL)
	{	while(q!=NULL)
		{
		head3=insert(head3,q->info);
		q=q->next;
		}
	}
	if(q==NULL)
	{	while(p!=NULL)
		{
		head3=insert(head3,p->info);
		p=p->next;
		}
	}
	return head3;
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
	int s1,s2;
	printf("\nsize of 1st list ");
	scanf("%d",&s1);
	struct node *head=NULL;
	struct node *head1=create(head,s1); 
	printf("\nsize of 2nd list ");
	scanf("%d",&s2);
	struct node *head2=create(head,s2);
	struct node *head3=NULL;
	head3=merge(head1,head2,head3);
	display(head3);
	return 0;
}

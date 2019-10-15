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
struct node *reverse(struct node *head)
{
	struct node *p=NULL,*q=head,*r;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	return p;
}
void display(struct node *head)
{	struct node *p=head;
	printf("reverse of list is \n");
	while(p!=NULL)
	{	printf("%d ",p->info);
		p=p->next;
	}
}
int main()
{	int s1;
	printf("\nsize of list ");
	scanf("%d",&s1);
	
	struct node *head=NULL;
	struct node *head1=create(head,s1);
	struct node *h=reverse(head1);
	display(h);
	return 0;
}

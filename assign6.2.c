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
struct node *concatenate(struct node *head1,struct node *head2)
{	struct node *p=head1;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2;
	return head1;
}
void display(struct node *head)
{	struct node *p=head;
	printf("concatenate of two list is \n");
	while(p!=NULL)
	{	printf("%d ",p->info);
		p=p->next;
	}
}
int main()
{	int s1,s2;
	printf("\nsize of 1st list ");
	scanf("%d",&s1);
	
	struct node *head=NULL;
	struct node *head1=create(head,s1);
	printf("\nsize of second list ");
	scanf("%d",&s2);
	struct node *head2=create(head,s2);
	struct node *head3=concatenate(head1,head2);
	display(head3);
	return 0;
}

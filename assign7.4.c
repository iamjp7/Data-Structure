#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *push(struct node *head,int x)
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
struct node *pop(struct node *head)
{
	struct node *p=head,*q;
	if(head==NULL)
	{
		printf("\nstack is underflow");
		return NULL;
	}
	if(head->next==NULL)
	{
		printf("\ndeleted element is %d",head->info);
		free(head);
		return NULL;
	}
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	printf("\ndeleted element is %d",p->info);
	q->next=NULL;
	free(p);
	return head;
}
void display(struct node *head)
{
	struct node *p=head;
	if(head==NULL)
	printf("\nstack is under flow");
	else 
	{
		printf("\nelement in stack is\n");
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
        }
}
int main()
{
	struct node *head=NULL;
	int choice,item;
	printf("\n 1 for push");
	printf("\n 2 for pop");
	printf("\n 3 for display");
	printf("\n 4 for quit");
	while(1)
	{
		printf("\nenter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nenter the element to push");
				scanf("%d",&item);
				head=push(head,item);
				break;
			case 2: head=pop(head);
				break;
			case 3: display(head);
			        break;
			case 4: exit(1);
		}
	}
	return 0;
}
				
	
	
			

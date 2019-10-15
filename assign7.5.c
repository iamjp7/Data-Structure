#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *enqueue(struct node *head,int x)
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
struct node *dequeue(struct node *head)
{
	struct node *p=head;
	if(head==NULL)
	{
		printf("\nqueue is empty");
		return NULL;
	}
	printf("\ndeleted element is %d",head->info);
	head=head->next;
	free(p);
	return head;
}
void display(struct node *head)
{
	struct node *p=head;
	if(head==NULL)
	printf("\nqueue is empty");
	else 
	{
		printf("\nelement in queue is\n");
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
	printf("\n 1 for enqueue");
	printf("\n 2 for dequeue");
	printf("\n 3 for display");
	printf("\n 4 for quit");
	while(1)
	{
		printf("\nenter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nenter the element to enqueue ");
				scanf("%d",&item);
				head=enqueue(head,item);
				break;
			case 2: head=dequeue(head);
				break;
			case 3: display(head);
			        break;
			case 4: exit(1);
		}
	}
	return 0;
}

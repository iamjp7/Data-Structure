#include<stdio.h>
#include <stdlib.h>
struct Node{
	int info;
	struct Node* next;
};

typedef struct Node node;

node* insertempty(node* head,int x){
	if(head->next!=NULL){
		printf("List is not empty\n");
		return head;
	}
	node* p = (node*)malloc(sizeof(node));
	p->info=x;
	head->next=p;
p->next=head->next;
return head;
}
node* insertafter(node* head,int x,int n){

if(head->next==NULL){
printf("List is empty inserting at beginning\n");
return insertempty(head,x);
}
node* p =(node*)malloc(sizeof(node));
p->info = x;
node* q=head->next;
while(q->info!=n){
q=q->next;
if(q==head->next){
	printf("%d is not present to insert after\n");
	return head;
}
}
p->next=q->next;
q->next=p;
return head;
}

node* deletegiven(node* head,int n){
	if(head->next==NULL){
		printf("List is empty\n");
		return head;
	}
	node *q=head->next,*p;
	while(q->info!=n){
		p=q;
		q=q->next;
		if(q==head->next){
			printf("Element %d is absent\n",n);
			return head;
		}
	}
	if(head->next->info==n){
		node* temp;
		while(q->next!=head->next)
			q=q->next;
		if(q==head->next){
             temp = head->next;
             head->next = NULL;
             free(temp);
             return head;
		}
		temp = head->next;
		head->next=q->next->next;
		q->next=q->next->next;
		free(temp);
		return head;
	}
	p->next=q->next;
	free(q);
	return head;
}

void display(node* head){
node* p=head->next;
if(p==NULL){
printf("List is empty\n");
return;
}
do{
printf("%d ",p->info);
p=p->next;
}while(p!=head->next);
printf("\n");
}

int main(){
node*  head = (node*)malloc(sizeof(node));
head->next=NULL;
int x;
while(1){
	printf("1.Insert to empty list\n2.Insert after a number\n3.Delete\n4.Display\n5.Exit\n");
	printf("Enter choice: ");
	scanf("%d",&x);
	switch(x){
		case 1:printf("Enter the number: ");
		int a;
		scanf("%d",&a);
		head=insertempty(head,a);
		break;
		case 2:
		printf("Enter the number to insert: ");
		int b,c;
        scanf("%d",&b);
        printf("Enter the number after which to insert: ");
        scanf("%d",&c);
        head=insertafter(head,b,c);
        break;
        case 3:
        printf("Enter the number to delete: ");
        int d;
        scanf("%d",&d);
        head=deletegiven(head,d);
        break;
        case 4:display(head);
        break;
        case 5:exit(1);
        break;
        default:printf("Enter correct choice\n");
	}
}


	return 0;
}
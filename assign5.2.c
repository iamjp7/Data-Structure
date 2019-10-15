#include<stdio.h>
#include<stdlib.h>
struct CNode{
int info;
struct CNode* next;
};

typedef struct CNode node;

node* insertempty(node* head,int x){
	if(head!=NULL){
		printf("List is not empty\n");
		return head;
	}
	node* p = (node*)malloc(sizeof(node));
	p->info=x;
	p->next=p;
	return p;
}

node* insertafter(node* head,int x,int n){
	if(head==NULL){
return insertempty(head,x);
}
node* p =(node*)malloc(sizeof(node));
p->info = x;

node *q=head;
while(q->info!=n){
	q=q->next;
	if(q==head){
		printf("%d is not present to insert after\n",n);
		return head;
	}
}
p->next=q->next;
q->next=p;
return head;
}

node* deletegiven(node* head,int x){
	if(head==NULL){
		printf("List is empty\n");
		return head;
	}
	node *q=head,*p;
	while(q->info!=x){
		p=q;
		q=q->next;
		if(q==head){
			printf("Number %d is absent\n",x);
			return head;
		}
	}
	if(head->info==x){
		while(q->next!=head)
			q=q->next;
		if(q==head){
			free(head);
			return NULL;
		}
		node* temp = head;
		q->next = head->next;
		head=head->next;
		free(temp);
		return head;
	}
	p->next = q->next;
	free(q);
	return head;
}

void display(node* head){
node* p=head;
if(p==NULL){
printf("List is empty\n");
return;
}
do{
printf("%d ",p->info);
p=p->next;
}while(p!=head);
printf("\n");
}

int main(){
node* head = NULL;
int x;
while(1){
	printf("1.Insert to circular list\n2.Insert after a number\n3.Delete\n4.Display\n5.Exit\n");
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

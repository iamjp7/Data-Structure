#include<stdio.h>
#include<stdlib.h>
#define max 10000

struct Node{
int data;
struct Node* next;
};
struct Stack
{
  int arr[max];
  int top;
};

typedef struct Node node;
typedef struct Stack stack;

void push(stack *s,int x){
  if(s->top==max-1){
    printf("Stack overflow\n");
    return;
  }
  s->arr[++s->top]=x;
}

int pop(stack *s){
  if(s->top==-1){
    printf("Stack empty\n");
    return -1;
  }
  return s->arr[s->top--];
}

node* insertafter(node* head,int x,int n){
node* p = (node*)malloc(sizeof(node));
p->data=x;
if(head==NULL){
printf("List is empty inserting at start\n");
p->next=NULL;
return p;
}
if(head->next==NULL){
   if(head->data==n){
      head->next=p;
      p->next=NULL;
      return head;
      }
   else{
     printf("%d not found\n",n);
     return head;
    }
   }
node* q=head;
while(q->data!=n){
q=q->next;
if(q==NULL){
printf("%d not found\n",n);
return head;
}
}
p->next=q->next;
q->next=p;
return head;
}

node* deletegiven(node* head, int n){
if(head==NULL){
printf("List empty\n");
return NULL;
}
node* p=head;
node* q;
while(p->data!=n){
q=p;
p=p->next;
if(p==NULL){
printf("Element not present\n");
return head;
}
}
if(p==head){
head=head->next;
free(p);
return head;
}
q->next=p->next;
free(p);
return head;
}

void display(node* head){
if(head==NULL)
printf("List is empty\n");
else{
node* p=head;
while(p!=NULL){
printf("%d ",p->data);
p=p->next;
}
printf("\n");
}
}

int length(node* head){
node* p=head;
if(p==NULL)
return 0;

return 1+length(p->next);
}

void checkpalindrome(node* head,stack* s){
if(head==NULL||head->next==NULL){
  printf("There must be more than one element in list\n");
  return;
}
node* p=head;
int l=length(p),i,count=0;
if(l%2==0){
  for(i=0;i<l/2;i++){
    push(s,p->data);
    p=p->next;
  }
  for(i=0;i<l/2;i++){
    if(pop(s)!=p->data)
      count++;
    p=p->next;
  }
  if(count>0)
    printf("Not palindrome\n");
  else
    printf("Yes list elements form palindrome\n");
}
else{
 for(i=0;i<l/2;i++){
  push(s,p->data);
  p=p->next;
 }
 p=p->next;
 for(i=0;i<l/2;i++){
  if(pop(s)!=p->data)
    count++;
  p=p->next;
 }
 if(count>0)
    printf("Not palindrome\n");
  else
    printf("Yes list elements form palindrome\n");
}
}


int main(){
node* head=NULL;
stack s;
s.top=-1;
int ch;
printf("1.To insert\n2.To delete an element\n3.To display elements of List\n4.To display its length\n5.To check palindrome\n6.To exit\n");
while(1){
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch){
case 1:printf("Enter element to insert: ");
int a,b;
scanf("%d",&a);
printf("Enter element after which to insert(0 if list is empty): ");
scanf("%d",&b);
head=insertafter(head,a,b);
break;
case 2:printf("Enter the element to delete: ");
int c;
scanf("%d",&c);
head=deletegiven(head,c);
break;
case 3:display(head);
break;
case 4:printf("%d\n",length(head));
break;
case 5:checkpalindrome(head,&s);
break;
case 6:exit(1);
break;
default:printf("Enter valid choice\n");
}

}

return 0;
}
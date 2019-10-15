#include<stdio.h>
#include<stdlib.h>
struct Node 
{
     int data ;
     struct Node* next;
     struct Node* prev;
};
typedef struct Node node;
node* insert_start(node* head,int x)
{
      node* temp = (node* )malloc(sizeof(node));
      temp->data = x;
     
      if(head==NULL)
      { temp->prev = temp;
         temp->next =temp;
      }
      else
      {
         temp->next=head;
         temp->prev=head->prev;
         head->prev->next=temp;
         head->prev = temp;
      }
      return temp;
} 
node* insert_end(node* head,int x)
{
      if(head==NULL)
      return insert_start(head,x);
      node* temp= (node* )malloc(sizeof(node));
      temp->data=x;
      temp->next=head;
      temp->prev=head->prev;
      head->prev->next= temp;
      head->prev= temp;
      return head;
      
}
node* insert_after(node* head,int x,int y)
{
       node *p,*q=head;
       p=(node* )malloc(sizeof(node));
       p->data=y;
       while(q->data!=x)
       q=q->next;
       if(q->next!=NULL)
       q->next->prev=p;
       p->next=q->next;
       p->prev= q;
       q->next=p;
       return head;

}
node* insert_before(node* head,int x,int y)
{
       node *p,*q=head;
       if(head==NULL||head->data==x)
       return insert_start(head,y);
       p= (node* )malloc(sizeof(node));
       p->data=y;
       while(q->data!=x)
       q=q->next;
       p->next=q;
       q->prev->next=p;
       p->prev=q->prev;
       q->prev=p;
       return head;       
}
node* deletegiven(node* head,int x)
{
     if(head==NULL){
      printf("List is empty\n");
      return NULL;
     }
     if(head->data==x){
      free(head);
      return NULL;
     }
     node* p= head;
     while(p->data!=x)
     p=p->next;
     p->prev->next=p->next;
     p->next->prev=p->prev;
     free(p);
     return head;
     
}
void display(node* head)
{
   if(head==NULL)
   {
      printf("List is Empty\n");
      return;
   }
    printf("LIST: ");
    node* temp =head;
   do
   {
    printf("%i ",temp->data);
    temp=temp->next;
   
   }while(temp!=head);
   printf("\n");

}
node* created(int x)
{
     node* temp =(node* )malloc(sizeof(node));
     temp->data=x;
     temp->next=temp;
     temp->prev = temp;
     printf("\nCircular Doubly linked List Created\n");
     return temp;
}
int main()
{
      printf("1. Create a circular doubly linked List\n");
      printf("2. Insert an element at the start\n");
      printf("3. Insert an element at the end \n");
      printf("4. Insert a data before an existing element\n");
      printf("5. Insert a data element after an existing element\n");
      printf("6. Delete a data\n");
      printf("7. Display the link list\n");
      printf("8.Exit\n");
      node* head = NULL;
      int ch;
      while(1)
      {   printf("Enter a choice: \n");
         scanf("%i",&ch);
         int temp1,temp2;
         switch(ch)
         {
             case 1:
             printf("Enter the data of first Element: ");
             scanf("%i",&temp1);
             head = (node* )created(temp1);
             break;
            case 2:
             printf("Enter the data: ");
             scanf("%i",&temp1);
             head = insert_start(head,temp1);
             break;
             case 3:
             printf("Enter the data: ");
             scanf("%i",&temp1);
             head = insert_end(head,temp1);
             break;
             case 4:
             printf("Enter the element and data to be inserted: ");
             scanf("%i %i",&temp1,&temp2);
             head = insert_before(head,temp1,temp2);
             break;
             case 5:
             printf("Enter the element and data to be inserted: ");
             scanf("%i %i",&temp1,&temp2);
             head = insert_after(head,temp1,temp2);
             break;
             case 6:
             printf("Enter the data: ");
             scanf("%i",&temp1);
             head = deletegiven(head,temp1);
             break;
             case 7:
             display(head);
             break;
             case 8:
             exit(1);
             default:printf("Enter valid choice\n");
            }
             
     }
  return 0;    
}
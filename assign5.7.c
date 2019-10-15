#include<stdio.h>
#include<stdlib.h>
struct Node 
{
     int data ;
     struct Node* next;
     struct Node* prev;
};
typedef struct Node node;
void insert_start(node* header,int x)
{
      node* temp = (node* )malloc(sizeof(node));
      temp->data = x;
      temp->next=header->next;
      temp->prev=header;
      header->next= temp;
      header->data++;
} 
void insert_end(node* header,int x)
{
      node* p = header->next;
      if(p==NULL)
      return insert_start(header,x);
      node* temp = (node* )malloc(sizeof(node));
      temp->next = NULL;
      temp->data= x;
      while(p->next!=NULL)
      p=p->next;
      p->next = temp;
      temp->prev= p;
      header->data++;
}
void insert_after(node* header,int x,int y)
{
       node *p,*q=header->next;
       p=(node* )malloc(sizeof(node));
       p->data=y;
       while(q->data!=x)
       q=q->next;
       p->next=q->next;
       p->prev = q;
       if(q->next!=NULL)
       q->next->prev= p;
       q->next=p;
       header->data++;
}
void insert_before(node* header,int x,int y)
{
       node *p,*q=header->next;
       if(q->data==x)
       return insert_start(header,y);
       p= (node* )malloc(sizeof(node));
       p->data=y;
       while(q->data!=x)
       q=q->next;
       p->next=q;
       q->prev->next=p;
       p->prev=q->prev;
       q->prev=p;
       header->data++;       
}
void delete_first(node* header)
{
    if(header->next==NULL)
    { 
        printf("List is empty\n");
        return;
    }
    node* temp =header->next;
    header->next= temp->next;
    if(temp->next!=NULL)
    temp->next->prev=header;
    free(temp);
    header->data--;
}
void delete_last(node* header)
{   node* temp =header->next;
    if(temp==NULL)
    return delete_first(header);
    while(temp->next!=NULL)
    {
          temp=temp->next;
    }
    if(temp->prev==header)
    return delete_first(header);
    temp->prev->next=temp->next;
    free(temp);
    header->data--;
    
}
void delete(node* header,int x)
{
     if(header->next==NULL||header->next->data==x)
     return delete_first(header);
     node* p= header->next;
     while(p!=NULL&&p->data!=x)
     p=p->next;
     p->prev->next=p->next;
     if(p->next!=NULL)
     p->next->prev=p->prev;
     free(p);
     header->data--;
     
}
void display(node* header)
{
   if(header->next==NULL)
   {
      printf("List is Empty\n");
      return;
   }
    printf("LIST: ");
    node* head = header->next;
   while(head!=NULL)
   {
    printf("%i ",head->data);
    head=head->next;
   
   }
   printf("\n");

}
void created(node** header)
{
     node* temp =(node* )malloc(sizeof(node));
     temp->data=0;
     temp->next=NULL;
     temp->prev = NULL;
     *header= temp;
     printf("\nHeader based Doubly linked List Created\n");
}
void display_num(node* header)
{
   printf("\nThe number of nodes is %i \n",header->data);
}
int main()
{
      printf("1.. Create a linked List\n");
      printf("2.. Insert an element at the start\n");
      printf("3.. Insert an element at the end \n");
      printf("4.. Insert an Element before an element\n");
      printf("5.. Insert an element after an element\n");
      printf("6.. Delete the head Node\n");
      printf("7.. Delete the end node\n");
      printf("8.. Delete a specific data\n");
      printf("9.. Display the linked list\n");
      printf("10.. Display the number of nodes in linked list(using header node)\n");
      printf("11..Exit\n");
      node* header = NULL;
      int ch;
      while(1)
      {   printf("Enter a choice: \n");
         scanf("%i",&ch);
         int temp1,temp2;
         switch(ch)
         {
             case 1:
             created(&header);
             break;
             case 2:
             printf("Enter the data: ");
             scanf("%i",&temp1);
             insert_start(header,temp1);
             break;
             case 3:
             printf("Enter the data: ");
             scanf("%i",&temp1);
             insert_end(header,temp1);
             break;
             case 4:
             printf("Enter the element and data to be insrted: ");
             scanf("%i %i",&temp1,&temp2);
             insert_before(header,temp1,temp2);
             break;
             case 5:
             printf("Enter the element and data to be insrted: ");
             scanf("%i %i",&temp1,&temp2);
             insert_after(header,temp1,temp2);
             break;
             case 6:
             delete_first(header);
             break;
             case 7:
             delete_last(header);
             break;
             case 8:
             printf("Enter the data: ");
             scanf("%i",&temp1);
             delete(header,temp1);
             break;
             case 9:
             display(header);
             break;
             case 10:
             display_num(header);
             break;
             case 11:
             exit(1);
             default: printf("Enter valid choice\n");
            }
             
     }
      return 0;
}


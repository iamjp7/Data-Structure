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
      if(header->prev==header)
      header->prev=temp;
      header->next=temp;
      header->data++;
} 
void insert_end(node* header,int x)
{
      if(header->next==header)
      return insert_start(header,x);
      node* temp= (node* )malloc(sizeof(node));
      temp->data=x;
      temp->next=header;
      temp->prev=header->prev;
      header->prev->next= temp;
      header->prev= temp;
      header->data++;
      
}
void insert_after(node* header,int x,int y)
{
       node *p,*q=header->next;
       p=(node* )malloc(sizeof(node));
       p->data=y;
       while(q->data!=x)
       q=q->next;
       q->next->prev=p;
       p->next=q->next;
       p->prev= q;
       q->next=p;
       header->data++;

}
void insert_before(node* header,int x,int y)
{
       node *p,*q=header->next;
       if(q==header||q->data==x)
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
    if(header==NULL||header->data==0)
    { 
      printf("SORRY LIST IS EMPTY\n");
      return ;
    }
    node* temp =header->next;
    header->next = temp->next;
    temp->next->prev=header;
    free(temp);
    header->data--;
}
void delete_last(node* header)
{
    if(header->next==header)
    {
       printf("List is empty\n");
       return ;
    }
    node* temp =header->prev;
    header->prev=temp->prev;
    temp->prev->next=header;
    free(temp);
    header->data--;
    
}
void delete(node* header,int x)
{
     if(header->next==header||header->next->data==x)
     return delete_first(header);
     node* p= header->next;
     while(p->data!=x)
     p=p->next;
     p->prev->next=p->next;
     p->next->prev=p->prev;
     free(p);
     header->data--;
     
}
void display(node* header)
{
   if(header->next==header)
   {
      printf("List is Empty\n");
      return;
   }
    printf("LIST: ");
    node* temp =header->next;
   do
   {
    printf("%i ",temp->data);
    temp=temp->next;
   
   }while(temp!=header);
   printf("\n");

}
void created(node** header)
{
     node* temp =(node* )malloc(sizeof(node));
     temp->data=0;
     temp->next=temp;
     temp->prev = temp;
     *header = temp;
     printf("\nHeader based Circular Doubly linked List Created\n");
}
void show_n(node* header)
{
    printf("\nThe number of nodes in the header based doubly linked list is %i \n",header->data);  
}
int main()
{
      printf("1.. Create a header based circular doubly linked List\n");
      printf("2.. Insert an element at the start\n");
      printf("3.. Insert an element at the end \n");
      printf("4.. Insert a data before an existing element\n");
      printf("5.. Insert a data element after an existing element\n");
      printf("6.. Delete the head Node\n");
      printf("7.. Delete the end node\n");
      printf("8.. Delete a specific data\n");
      printf("9.. Display the link list\n");
      printf("10..Display the number of nodes\n");
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
             printf("Enter the element and data to be inserted: ");
             scanf("%i %i",&temp1,&temp2);
             insert_before(header,temp1,temp2);
             break;
             case 5:
             printf("Enter the element and data to be inserted: ");
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
             show_n(header);
             break;
             case 11:
             exit(1);
            }
             
     }
  return 0;    
}


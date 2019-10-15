#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int info;
    struct NODE *next;
};
struct NODE *insertstart(struct NODE *head,int y)
{
    struct NODE *q=(struct NODE*)malloc(sizeof(struct NODE));
    q->next=head;
    q->info=y;
    return q;
}
struct NODE *insertend(struct NODE *head,int y)
{
    struct NODE *q=(struct NODE*)malloc(sizeof(struct NODE)),*p=head;
    q->next=NULL;
    q->info=y;
    if(head==NULL)
    return q;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    return head;
}
struct NODE *insertbefore(struct NODE *head,int x,int y)
{
    struct NODE *q=(struct NODE*)malloc(sizeof(struct NODE)),*p=head;
    q->info=y;
    if(head->info==x || head==NULL)
    {
        q->next=head;
        return q;
    }
    while(p->next->info!=x && p->next!=NULL)
        p=p->next;

if(p->next==NULL)
{printf("\nelement is not present in list");
return head;}
q->next=p->next;
p->next=q;
return head;
}
struct NODE *insertafter(struct NODE *head,int x,int y)
{struct NODE *q=(struct NODE*)malloc(sizeof(struct NODE)),*p=head;
q->info=y;
if(head==NULL)
{q->next=NULL;
return q;}
while(p->info!=x && p->next!=NULL)
{p=p->next;}
if(p->next==NULL)
{printf("\nelement is not present in list");
return head;
}
q->next=p->next;
p->next=q;
return head;
}
struct NODE *deletefirst(struct NODE *head)
{struct NODE *p=head;
if(head==NULL)
{printf("\nlist is empty");
return head;
}
head=head->next;
free(p);
return head;
}
struct NODE *deletelast(struct NODE *head)
{struct NODE *q,*p=head;
if(head==NULL)
{printf("\nlist is empty");
return NULL;}
if(head->next==NULL)
{free(p);
return NULL;}
while(p->next!=NULL)
{q=p;
p=p->next;}
q->next=NULL;
free(p);
return head;
}
struct NODE *delete(struct NODE *head,int x)
{struct NODE *p=head,*q;
if(head==NULL)
{printf("\nlist is empty");
return NULL;
}
if(head->next==NULL)
{free(p);
return NULL;}
while(p->info!=x && p->next!=NULL)
{q=p;
p=p->next;}
q->next=p->next;
free(p);
return head;
}
void display(struct NODE *head)
{struct NODE *p=head;
if(head==NULL)
printf("\nlist is empty");
printf("\nelement is ");
while(p!=NULL)
{printf("%d ",p->info);
p=p->next;
}
}
int main()
{int s,x,y,i,choice;
printf("\nenter the size of list ");
scanf("%d",&s);
struct NODE *head=NULL;
printf("\nenter the 1. element of list ");
scanf("%d",&y);
head=insertstart(head,y);
for(i=2;i<=s;i++)
{printf("\nenter the %d. element ",i);
scanf("%d",&y);
head=insertend(head,y);
}
printf("\n1.insert at start");
printf("\n2.insert at end");
printf("\n3.insert at before existing element");
printf("\n4.insert at after existing element");
printf("\n5.delete at start");
printf("\n6.delete at end");
printf("\n7.delete element with given information");
printf("\n8.display");
printf("\n9.quit");

while(1)
{
printf("\nenter your choice ");
scanf("%d",&choice);
switch(choice)
{case 1:
       printf("\nenter element to insert at start");
        scanf("%d",&y);
       head= insertstart(head,y);
break;
case 2:printf("\nenter element to insert at end");
        scanf("%d",&y);
        head=insertend(head,y);
break;
case 3:printf("enter the elemet before which want to insert");
scanf("%d",&x);
printf("\nenter element to insert at before ");
        scanf("%d",&y);
        head=insertbefore(head,x,y);
break;
case 4:printf("enter the elemet after which want to insert");
scanf("%d",&x);
printf("\nenter element to insert at after ");
        scanf("%d",&y);
        head=insertafter(head,x,y);
break;
case 5:head=deletefirst(head);
printf("\nelement is deleted");
break;
case 6:head=deletelast(head);
printf("\nelement is deleted");
break;
case 7:printf("\nelement want to delete");
scanf("%d",&x);
head=delete(head,x);
printf("\nelement is deleted");
break;
case 8:display(head);
break;
case 9:exit(1);
break;
}}return 0;}




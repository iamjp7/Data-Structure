#include<stdio.h>
#include<stdlib.h>
struct Queue
{int front,rear,qsize;
int *ar;
};
struct Queue *createqueue(int size)
{struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
q->qsize=size;
q->front=-1;
q->rear=-1;
q->ar=(int*)malloc(q->qsize * sizeof(int));
return q;
}
void insert(struct Queue *q,int item)
{if(q->rear==q->qsize-1)
{printf("\nqueue is overflow");
}
else if(q->front==-1)
   q->front=0;
   q->ar[++(q->rear)]=item;
return;
}
int del(struct Queue *q)
{if(q->front==-1 || q->rear==q->front-1)
{
printf("queue is underflow");
exit(1);}
else return q->ar[q->front++];
}
void display(struct Queue *q)
{int i;
if(q->front==-1 || q->rear==q->front-1)
printf("queue is underflow");
else printf("\nelement of queue is ");
for(i=q->front;i<=q->rear;i++)
printf("%d ",q->ar[i]);
}
void main()
{int n,choice,item;
printf("\nenter the size of queue");
scanf("%d",&n);
struct Queue *queue=createqueue(n);
while(1)
{printf("\nenter 1 to insert");
printf("\nenter 2 to delete");
printf("\nenter 3 to display");
printf("\nenter 4 to quit ");
scanf("%d",&choice);
switch(choice)
{case 1:printf("\nenter the value to insert ");
scanf("%d",&item);
insert(queue,item);
break;
case 2:item=del(queue);
printf("\ndeleted value is %d",item);
break;
case 3:display(queue);
break;
case 4:exit(1);
break;
default:printf("\nenter valid choice");
}
}
}


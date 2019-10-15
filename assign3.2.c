#include<stdio.h>
#include<stdlib.h>
struct QUEUE
{int front,rear,qsize;
int *array;
};
struct QUEUE *createcircularqueue(int size)
{struct QUEUE *queue=(struct QUEUE*)malloc(sizeof(struct QUEUE));
queue->front=-1;
queue->rear=-1;
queue->qsize=size;
queue->array=(int *)malloc(size*sizeof(int));
return queue;
}
void insert(struct QUEUE *q,int item)
{if((q->front==0 && q->rear==q->qsize-1) || q->rear==q->front-1)
printf("\nqueue is overflow");
else if(q->front==-1)
{
q->front=q->rear=0;
q->array[q->rear]=item;
}
else if(q->rear==q->qsize-1)
{
q->rear=0;
q->array[q->rear]=item;
}
else {
q->rear=q->rear+1;
q->array[q->rear]=item;}
return;
}
void del(struct QUEUE *q)
{int a;
if(q->front==-1)
{
printf("\nqueue is underflow");
return;}
else if(q->front==q->rear)
{
a=q->array[q->front];
q->front=q->rear=-1;
}
else if(q->front==q->qsize-1)
{a=q->array[q->front];
q->front=0;
}
else {a=q->array[q->front];
q->front=q->front+1;
}
printf("\ndeleted item is %d",a);
return;}
void display(struct QUEUE *q)
{int i;
if(q->front==-1)
{printf("queue is underflow");
}
else printf("\nelemnt in queue is ");
for(i=q->front;i<=q->rear;i++)
printf(" %d",q->array[i]);
return;
}
void main()
{int s,choice,item;
printf("\nenter the size of circular queue ");
scanf("%d",&s);
struct QUEUE *Queue=createcircularqueue(s);
while(1)
{printf("\nenter 1.insert\n2.delete\n3.display\n4.quit\n");
scanf("%d",&choice);
switch(choice)
{case 1:printf("\nenter the item to insert ");
scanf("%d",&item);
insert(Queue,item);
break;
case 2:del(Queue);
break;
case 3:display(Queue);
break;
case 4:exit(1);
break;
}

}
}

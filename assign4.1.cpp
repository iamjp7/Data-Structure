#include <stdio.h>
#include<stdlib.h>
struct Queue
{
int front,rear,qsize;
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
{printf("\nstack is overflow");
}

else if(q->front==-1)
   q->front=0;
   q->ar[++(q->rear)]=item;
return;
}
int del(struct Queue *q)
{if(q->front==-1 || q->rear==q->front-1)
{
printf("\nstack is underflow");
exit(1);}
else return q->ar[q->front++];
}
void display(struct Queue *q)
{int i;
if(q->front==-1 || q->rear==q->front-1)
printf("\nstack is underflow");
else printf("\nelement of stack is ");
for(i=q->front;i<=q->rear;i++)
printf("%d ",q->ar[i]);
}
int main()
{int n,choice,item;
printf("\nenter the size of stack ");
scanf("%d",&n);
struct Queue *q1=createqueue(n);
struct Queue *q2=createqueue(n);
while(1)
{printf("\nenter 1 to push");
printf("\nenter 2 to pop");
printf("\nenter 3 to display");
printf("\nenter 4 to quit\n");
scanf("%d",&choice);
switch(choice)
{case 1:printf("\nenter the element to push");
scanf("%d",&item);
insert(q1,item);
break;
case 2:while(q1->front!=q1->rear)
{int t=del(q1);
insert(q2,t);
}int a;
a=del(q1);
printf("\ndeleted element is %d",a);
struct Queue *temp;
temp=q1;
q1=q2;
q2=temp;
break;
case 3:display(q1);
break;
case 4: exit(1);
break;
}
}
return 0;
}

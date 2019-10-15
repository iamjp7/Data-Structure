#include <stdio.h>
#include <stdlib.h>
struct pqueue
{
    int* arr;
    int rear,front;
    unsigned size;
};
 typedef struct pqueue pqueue;
 
pqueue* initialize(unsigned size)
{
	pqueue* p = (pqueue*)malloc(sizeof(pqueue));
    p->rear=-1;
    p->front=-1;
    p->size=size;
    p->arr=(int*)malloc(p->size*sizeof(int));
    return p;
}
 
int isempty(pqueue *p)
{
    if(p->rear==-1)
        return(1);
 
    return(0);
}
 
int isfull(pqueue *p)
{
    if((p->rear+1)%p->size==p->front)
        return(1);
 
    return(0);
}
 
void enqueue(pqueue *p, int x)
{
    int i;
    if(isfull(p))
        printf("\nOverflow");
    else
    {
        if(isempty(p))
        {
            p->rear=p->front=0;
            p->arr[0]=x;
        }
        else
        {
            i=p->rear;
 
            while(x>p->arr[i])
            {
                p->arr[(i+1)%p->size]=p->arr[i];
                i=(i-1+p->size)%p->size; 
                if((i+1)%p->size==p->front)
                    break;
            }
            i=(i+1)%p->size;
            p->arr[i]=x;
            p->rear=(p->rear+1)%p->size;
        }
    }
}
 
int dequeue(pqueue *p)
{
    int x;
 
    if(isempty(p))
    {
        printf("\nUnderflow..");
    }
    else
    {
        x=p->arr[p->front];
        if(p->rear==p->front){
        	p->rear=-1;
        	p->front=-1;
		}
        else
            p->front=(p->front +1)%p->size;
    }
 
    return(x);
}
 
void print(pqueue *p)
{
    int i,x;
 
    if(isempty(p))
    {
        printf("\nQueue is empty..");
    }
    else
    {
        i=p->front;
 
        while(i!=p->rear)
        {
            x=p->arr[i];
            printf("\n%d",x);
            i=(i+1)%p->size;
        }
        x=p->arr[i];
        printf("\n%d",x);
    }
}

int main()
{int s;
printf("\nenter the size of Priority Queue ");
scanf("%d",&s);
  pqueue* q = initialize(s);
    int n;
    while(1){
        printf("Choose one option");
        printf("\n1)Insert \n2)Delete \n3)Print \n4)EXIT\n");
        scanf("%d",&n);
        switch (n) {
            case 1: printf("Enter the element to be inserted\n");
                    int x;
                    scanf("%d",&x);
                    enqueue(q,x);
                    break;
 
            case 2:
                    x=dequeue(q);
                    printf("\nDeleted Element=%d",x);
                    break;
 
            case 3: print(q);
                    break;
 
            case 4: printf("Out of queue\n");
                    exit(1);
            default:printf("Enter correct choice\n");
                   break;
        }
}
return  0;
}
 


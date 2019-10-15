#include<stdio.h>
#include<stdlib.h>
struct nqueue{
	int* front;
	int* rear;
	int* dataArray;
	int* nextIndex;
	unsigned size;
	int nextAvailable;
};

typedef struct nqueue nQueue;

nQueue* initialise(unsigned size,int numOfQ){
nQueue* q=(nQueue*)malloc(sizeof(nQueue));
q->nextAvailable=0;
q->size=size;
q->dataArray=(int*)malloc(size*sizeof(int));
q->front=(int*)malloc(numOfQ*sizeof(int));
q->rear=(int*)malloc(numOfQ*sizeof(int));
int i;
for(i=0;i<numOfQ;i++)
   q->front[i]=-1;
q->nextIndex=(int*)malloc(size*sizeof(int));
	for(i=0;i<size-1;i++)
		q->nextIndex[i]=i+1;
	q->nextIndex[size-1]=-1;
	return q;
}

int isFull(nQueue* q){
	if(q->nextAvailable==-1)
		return 1;
	return 0;
}

int isEmpty(nQueue* q,int numOfQ){
	if(q->front[numOfQ]==-1)
		return 1;
	return 0;
}

void dequeue(nQueue* q,int numOfQ){
	if(isEmpty(q,numOfQ)){
		printf("Queue %d is empty\n",numOfQ);
		return;
	}
int currentIndex;
currentIndex = q->front[numOfQ];
q->front[numOfQ]=q->nextIndex[currentIndex];
q->nextIndex[currentIndex]=q->nextAvailable;
q->nextAvailable=currentIndex;
printf("%d popped from queue no %d",q->dataArray[currentIndex],numOfQ);
}

void enqueue(nQueue* q,int numOfQ,int data){
	if(isFull(q)){
		printf("Queue is full\n");
		return;
	}
   int currentIndex;
   currentIndex = q->nextAvailable;
   q->nextAvailable=q->nextIndex[currentIndex];
   if(isEmpty(q,numOfQ))
   	 q->front[numOfQ]=currentIndex;
   	else
   		q->nextIndex[q->rear[numOfQ]]=currentIndex;
   	q->nextIndex[currentIndex]=-1;
   	q->rear[numOfQ]=currentIndex;
   	q->dataArray[currentIndex]=data;
}

int main(){
    unsigned size;
	int n,k;
	printf("Enter the no of queues you want to implement: ");
	scanf("%d",&n);
	printf("Enter the size of array to use: ");
	scanf("%d",&size);
	nQueue* q = initialise(size,n);
	printf("Choose your option:\n");
	while(1){
     printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
     scanf("%d",&k);
     switch(k)
     {
     	case 1:printf("Enter queue no: ");
     	       int no;
     	       scanf("%d",&no);
     	       printf("Enter the element to enqueue: ");
     	       int e;
     	       scanf("%d",&e);
     	       enqueue(q,no,e);
     	       break;
     	case 2:printf("Enter queue no to dequeue: ");
     	       int num;
     	       scanf("%d",&num);
     	       dequeue(q,num);
     	       break;
     	case 3:exit(1);
     	default:printf("enter valid number\n");
     }
	}
	

	return 0;
}
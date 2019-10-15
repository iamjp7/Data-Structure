#include<stdio.h>
#include<stdlib.h>
struct dequeue{
	int front,rear;
	unsigned size;
	int* arr;
};
struct dequeue* construct(unsigned size){
	struct dequeue* d = (struct dequeue*)malloc(sizeof(struct dequeue));
	d->front=-1;
	d->rear=-1;
	d->size=size;
	d->arr= (int*)malloc(size*sizeof(int));
}

void enqueueatFront(struct dequeue* q,int x){
	if(q->front==0&&q->rear==q->size-1||q->front==q->rear+1)
	 printf("Full\n");
	else{
		if(q->front==-1){
			q->front=0;
			q->rear=0;
			q->arr[q->front]=x;
		}
		else if(q->front==0){
			q->front=q->size-1;
			q->arr[q->front]=x;
		}
		else{
			q->arr[--q->front]=x;
		}
	}
}
void enqueueatRear(struct dequeue* q,int x){
	if(q->front==0&&q->rear==q->size-1||q->front==q->rear+1)
	 printf("Full\n");
	else{
			if(q->front==-1){
			q->front=0;
			q->rear=0;
			q->arr[q->rear]=x;
		}
		else if(q->rear==q->size-1){
			q->rear=0;
			q->arr[q->rear]=x;
		}
		else{
			q->arr[++q->rear]=x;
		}
	}
}
void dequeueFront(struct dequeue* q){
	if(q->front==-1)
	  printf("Empty queue\n");
	else{
		printf("%d removed from DEqueue\n",q->arr[q->front]);
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}
		else if(q->front==q->size-1){
			q->front=0;
		}
		else
		   q->front=q->front+1;
	}
}
void dequeueRear(struct dequeue* q){
	if(q->front==-1)
	printf("Empty queue\n");
	else{
			printf("%d removed from DEqueue\n",q->arr[q->rear]);
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}
		else if(q->rear==0){
			q->rear=q->size-1;
		}
		else
		 q->rear=q->rear-1;
	}
}
void display(struct dequeue* q){
	int f,r,i=0;
		f=q->front;
		r=q->rear;
	if(q->front==-1)
	 printf("Empty\n");
	else{
		if(q->front<=q->rear){

		while(f<=r)
		printf("%d ",q->arr[f++]);
		}
		else{
		while(f<q->size)
		printf("%d ",q->arr[f++]);
		while(i<=r)
		printf("%d ",q->arr[i++]);
		}
	}
}

int main(){
	int s;
	printf("enter the size of Dequeue ");
	scanf("%d",&s);
	struct dequeue* q = construct(s);
	int n;
while(1){
	printf("Enter command:\n");
	printf("1.To insert at front\n2.To insert at rear\n3.To dequeue from front\n4.To dequeue from rear\n5.To display\n6.To exit\n");
	scanf("%d",&n);
	switch(n){
		case 1:printf("Enter number to insert\n");
		int a;
		scanf("%d",&a);
		enqueueatFront(q,a);
		break;
		case 2:printf("Enter number to insert\n");
		int b;
		scanf("%d",&b);
		enqueueatRear(q,b);
		break;
		case 3:
	    dequeueFront(q);
		break;
		case 4:
		dequeueRear(q);
		break;
		case 5:display(q);
		break;
		case 6:printf("out of Dequeue\n");
		exit(1);
		default:printf("Enter valid number\n");
	}
}
	return 0;
}

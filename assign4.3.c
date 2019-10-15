#include<stdio.h>
#include<stdlib.h>
struct nstack{
	int* stackData;
	int* nextIndex;
	int* topOfStack;
	int nextAvailable;
	unsigned size;
};

typedef struct nstack nStack;

nStack* initialise(unsigned size,int n){
	nStack* s=(nStack*)malloc(sizeof(nStack));
	s->size=size;
	s->nextAvailable=0;
	s->topOfStack=(int*)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
		s->topOfStack[i]=-1;
	s->stackData=(int*)malloc(size*sizeof(int));
	s->nextIndex=(int*)malloc(size*sizeof(int));
	for(i=0;i<size-1;i++)
		s->nextIndex[i]=i+1;
	s->nextIndex[size-1]=-1;
	return s;
}

int isFull(nStack* s){
	if(s->nextAvailable==-1)
		return 1;
	return 0;
}

int isEmpty(nStack* s,int n){
if(s->topOfStack[n]==-1)
	return 1;
return 0;
}

void push(nStack* s,int stack,int value){
 if(isFull(s)){
 	printf("Stack overflow\n");
 	return;
 }
 int currentIndex;
 currentIndex=s->nextAvailable;
 s->nextAvailable=s->nextIndex[currentIndex];
 s->stackData[currentIndex] = value;
 s->nextIndex[currentIndex] = s->topOfStack[stack];
 s->topOfStack[stack]= currentIndex; 
}
void pop(nStack* s,int stack){
	if(isEmpty(s,stack)){
		printf("Stack %d is empty\n",stack);
		return;
	}
	int currentIndex;
	currentIndex = s->topOfStack[stack];
	int value;
	value = s->stackData[currentIndex];
	s->topOfStack[stack]=s->nextIndex[currentIndex];
	s->nextIndex[currentIndex]=s->nextAvailable;
	s->nextAvailable=currentIndex;
	printf("%d popped from stack no %d\n",value,stack);
}


int main(){
	unsigned size;
	int n,k;
	printf("Enter the no of stacks you want to implement: ");
	scanf("%d",&n);
	printf("Enter the size of array to use: ");
	scanf("%d",&size);
	nStack* s = initialise(size,n);
	printf("Choose your option:\n");
	while(1){
     printf("1.Push\n2.Pop\n3.exit\n");
     scanf("%d",&k);
     switch(k)
     {
     	case 1:printf("Enter stack no: ");
     	       int no;
     	       scanf("%d",&no);
     	       printf("Enter the element to push: ");
     	       int e;
     	       scanf("%d",&e);
     	       push(s,no,e);
     	       break;
     	case 2:printf("Enter stack no to pop: ");
     	       int num;
     	       scanf("%d",&num);
     	       pop(s,num);
     	       break;
     	case 3:exit(1);
     	default:printf("enter valid number\n");
     }
	}
   

	return 0;
}
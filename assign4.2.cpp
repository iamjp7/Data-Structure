#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
	int top;
	unsigned size;
	int* array;
};
struct Stack* createStack(unsigned size)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (int*) malloc(stack->size * sizeof(int));
	return stack;
}
int isFull(struct Stack* stack)
{ return stack->top == stack->size - 1 ;}
int isEmpty(struct Stack* stack)
{ return stack->top == -1; }
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
}
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
{
		printf("queue is empty");
	return NULL;}
	else return stack->array[stack->top--];
}
void Display(struct Stack* stack)
{if(isEmpty(stack))
printf("queue is empty");
int i;
printf("\nelement of queue is ");
for(i=stack->top;i>=0;i--)
{printf("%d  ",stack->array[i]);
}}
int main()
{int choice,item,t,s;
printf("\nenter the size of queue ");
scanf("%d",&s);
struct Stack* s1= createStack(s);
struct Stack* s2= createStack(s);
while(1)
{printf("\n1.insert\n");
printf("2.delete\n");
printf("3.Display\n");
printf("4.for exit");
printf("\nenter your choice ");
scanf("%d",&choice);
switch(choice)
{case 1:printf("\nenter the element to insert");
scanf("%d",&item);
push(s1,item);
break;
case 2:while(s1->top!=-1)
{t=pop(s1);
push(s2,t);
}t=pop(s2);
printf("\ndeleted element is %d ",t);
struct Stack* temp;
temp=s1;
s1=s2;
s2=temp;
break;
case 3:Display(s1);
break;
case 4:exit(1);
break;
}}
return 0;}

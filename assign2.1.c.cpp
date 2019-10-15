
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
	printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
{
		printf("stack is empty");
	return NULL;}
	else return stack->array[stack->top--];
}
void Display(struct Stack* stack)
{if(isEmpty(stack))
printf("stack is empty");
int i;
printf("\nelement of stack is ");
for(i=stack->top;i>=0;i--)
{printf("%d  ",stack->array[i]);
}}
int main()
{
	struct Stack* stack = createStack(100);
int choice,item;
while(1)
{printf("\n1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("4.for exit");
printf("\nenter your choice ");
scanf("%d",&choice);
switch(choice)
{case 1:
printf("\nenter the item to push ");
scanf("%d",&item);
push(stack,item);
break;
case 2:
item=pop(stack);
printf("\npop item is %d",item);
break;
case 3:
Display(stack);
case 4:
exit(1);

	return 0;
}}}


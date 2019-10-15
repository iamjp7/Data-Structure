#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define size  101
typedef struct stack{
int arr[size];
int top1 ;
int top2 ;
}Stack;
void push1(Stack* s,int x)
{
  if(s->top1<s->top2-1)
  {
    s->arr[++(s->top1)]=x;
  }
  else
  {
     printf("STACK OVERFOW \n");
  }
}
void push2(Stack* s,int x)
{
  if(s->top2>s->top1+1)
  {
    s->arr[--(s->top2)]=x;
  }
  else
  {
     printf("STACK OVERFLOW \n");
  }
}
int pop1(Stack* s)
{
   if(s->top1>-1)
   {
      int tmp= s->arr[s->top1--];
      return tmp;
   }
   else{printf("STACK UNDERFLOW\n");
   return INT_MAX;
   }
}
int pop2(Stack* s)
{
   if(s->top2<size)
   {
      int tmp= s->arr[s->top2++];
      return tmp;
   }
   else{printf("STACK UNDERFLOW\n");
   return INT_MAX;
   }
}
void display1(Stack* s)
{printf("STACK1:\n");
int i;
for(i=0;i<=s->top1;i++)
{
  printf("%i ",s->arr[i]);
}
printf("\n");
}
void display2(Stack* s)
{printf("STACK2:\n");
int i;
for(i=size-1;i>=s->top2;i--)
{
  printf("%i ",s->arr[i]);
}
printf("\n");
}

void main()
{
  Stack* s= (Stack* )malloc(sizeof(Stack));
  s->top1=-1;
  s->top2=size;
  push1(s,100);
  printf("The max Size of stack is : %i\n",size);
  printf("Pushing 100 elements to stack1 and 1 element to stack 2:\n");
  int i=100;
  while(i--)
  {
  push1(s,i);
  if(i==1)
  break;
  }
  push2(s,200);
  display1(s);
  display2(s);
   printf("Trying to push another element to stack1\n");
   push1(s,900);
  printf("Trying to push another element to stack2\n");
   push2(s,900);
   printf("Pop the only element in stack2:\n");
   printf("The element %i was popped\n",pop2(s));
   printf("trying to Pop stack2 again:\n");
   pop2(s);





}

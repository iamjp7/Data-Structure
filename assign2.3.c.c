#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define stk_size  100001
int pow(int a, int b)
{
 if(b==1)
 return a;
 if(b==0)
 return 1;
 return pow(a,b-1)*a;
}
struct stack
{
 int arr[stk_size];
 int top_index;
};
typedef struct stack Stack;
void push(Stack* s,int x)
{
   if(s->top_index ==stk_size-1)
   printf("stack Overflow\n");
   else{
       s->top_index++;
 s->arr[s->top_index]=x;
   }
}
int pop(Stack* s)
{
  if(s->top_index==-1)
  {
 printf("Stack Underflow");
  return INT_MAX;}
  else
  {
     int tmp= s->arr[s->top_index--];
     return tmp;

  }
}
void display(Stack* s)
{  printf("STACK :\n");
int i;
   for( i=0;i<=s->top_index;i++)
   {
     printf("%i ",s->arr[i]);


   }
   printf("\n");

}
int solve(char* exp)
{
  Stack* s= (Stack* )malloc(sizeof(Stack));
  s->top_index=-1;
  int i=0;
  while(exp[i])
  {
    if(isdigit(exp[i]))
    {
        push(s,exp[i]-'0');
    }
    else
    {  int a = pop(s);
       int b = pop(s);
     switch(exp[i])
     {
       case '+':
         push(s,a+b);break;
       case '*':
        push(s,a*b);break;
        case '-':
        push(s,b-a);break;
        case '/':
        push(s,b/a);break;
        case '^':
        push(s,pow(b,a));break;

     }

    }
    i++;
  }
  return pop(s);
}
void main()
{

  printf("ENTER THE POSTFIX EXPRESSION\n");
  char* exp= (char *)malloc(stk_size*sizeof(char));
  scanf("%s",exp);
  int result = solve(exp);
  printf("\nThe result is : %i\n",result);
}

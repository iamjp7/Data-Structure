#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define stk_size  1001
#define col 1001;
struct stack
{
 char arr[stk_size];
 int top_index;
};
typedef struct stack Stack;
void push(Stack* s,char x)
{
   if(s->top_index ==stk_size-1)
   printf("stack Overflow\n");
   else{
       s->top_index++;
 s->arr[s->top_index]=x;
   }
}
char pop(Stack* s)
{
  if(s->top_index==-1)
  {
 printf("Stack Underflow\n");
  return '0';}
  else
  {
     char tmp= s->arr[s->top_index--];
     return tmp;

  }
}
char peek(Stack* s)
{  if(s->top_index!=-1)
  return s->arr[s->top_index];

}
int isOperand(char c)
{
   return (c>='a' && c<='z') || (c>='A'&& c<='Z');
}
int Prec(char c)
{
  switch(c)
  {
  case '+':
  case '-':
  return 1;
  case '*':
  case '/':
  return 2;
  case '^':
  return 3;


  }
  return -1;
}
void rev(char* str,int len,int index)
{
    char tmp = str[index];
    str[index]=str[len-index];
    str[len-index]=tmp;

    if(index==len/2)
    return;
    rev(str,len,index+1);

}
int in_to_post(Stack* s,char* str)
{
   int k=-1;
   int i;
   for( i=0;str[i];i++)
   {
     if(isOperand(str[i]))
               str[++k]=str[i];
     else if (str[i] == '(')
            push(s, str[i]);
     else if (str[i] == ')')
        {
            while ((s->top_index!=-1) && peek(s) != '(')
                str[++k]=pop(s);
            if (s->top_index==-1  ||peek(s) != '(')
                return -1;
            else
                pop(s);
        }
       else
        {
            while (s->top_index!=-1&& Prec(str[i]) <=  Prec(peek(s)))
                str[++k]=pop(s);
            push(s, str[i]);
        }

   }
   while (s->top_index!=-1)
       str[++k]=pop(s);
       str[++k]='\0';
   return 1;

}
int in_to_pre(Stack* s,char* str)
{
   rev(str,strlen(str)-1,0);
   int i;
   for(i=0;i<strlen(str);i++)
   {
     if(str[i]==')')
    str[i]='(';
    else if(str[i]=='(')
    str[i]=')';
   }
   in_to_post(s,str);
   rev(str,strlen(str)-1,0);
}

void main()
{
  Stack* s= (Stack* )malloc(sizeof(Stack));
  s->top_index=-1;
  char str[1000];
  while(1)
  {  
      printf("1->INFIX TO POSTFIX\n");
      printf("2->INFIX TO PREFIX\n");
      printf("3->EXIT\n");
      printf("Choose one:\n");
      int ch;
      scanf("%i",&ch);
      switch(ch)
          {
          case 1:
            printf("Enter the Expression:\n");
            scanf("%s",str);
            in_to_post(s,str);
            printf("RESULT : %s\n",str);
            break;
          case 2:
            printf("Enter the Expression:\n");
            scanf("%s",str);
            in_to_pre(s,str);
            printf("RESULT : %s\n",str);
            
            break;
          case 3:
            exit(0);
          }

  }


}

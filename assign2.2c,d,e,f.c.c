#include<stdio.h>
#include<string.h>
#define row 10001
#define col 10001
#define sz col
char stack[row][col];
int top =-1;
void push(char* str)
{
   if(top==sz-1)
   {
   printf("Stack Overflow\n");
   return;
   }
   int i=0,j=0;
   ++top;
   for(;str[i];i++)
   {
      stack[top][i]=str[i];
   
   }
   stack[top][i]='\0';



}
char* pop()
{
if(top==-1)
printf("Stack Underflow\n");
return stack[top--];


}

int isOperand(char c)
{
if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
return 1;
return 0;


}
void postin(char* str)
{
char p[sz];
int i;
   while(str[i])
  {
    if(isOperand(str[i]))
    {
       p[0]=str[i];
       p[1]='\0';
       push(p);
    }
    else
    {
      char* op2= pop();
      char* op1=pop();
      int k=0;int j=0;
      p[k++]='(';
      while(op1[j])
      {
         p[k++]=op1[j++];
      
      
      }
      p[k++]=str[i];
      j=0;
       while(op2[j])
      {
         p[k++]=op2[j++];
      
      
      }
      p[k++]=')';
      p[k]='\0';
      
      push(p);
    }
      i++;
   }
 }
void prein(char* str)
 { char p[sz];
  int i=strlen(str)-1;
  for(;i>=0;i--)
  {
       if(isOperand(str[i]))
    {
       p[0]=str[i];
       p[1]='\0';
       push(p);
    }
    else
    {
      char* op1= pop();
      char* op2=pop();
      int k=0;int j=0;
      p[k++]='(';
      while(op1[j])
      {
         p[k++]=op1[j++];
      
      
      }
      p[k++]=str[i];
      j=0;
       while(op2[j])
      {
         p[k++]=op2[j++];
      
      
      }
      p[k++]=')';
      p[k]='\0';
      
      push(p);
    }
  
  
  
  
  
  
  }
  
}
void post_pre(char *str)
{

char p[sz];
int i=0;
  for(;str[i];i++)
  {
       if(isOperand(str[i]))
    {
       p[0]=str[i];
       p[1]='\0';
       push(p);
    }
    else
    {
      char* op2= pop();
      char* op1=pop();
      int k=0;int j=0;
      p[k++]=str[i];
      while(op1[j])
      {
         p[k++]=op1[j++];
      
      
      }
      j=0;
       while(op2[j])
      {
         p[k++]=op2[j++];
      
      
      }
      p[k]='\0';
      
      push(p);
    }
  }
}
void pre_post(char* str)
{
   char p[sz];
  int i=strlen(str)-1;
  for(;i>=0;i--)
  {
       if(isOperand(str[i]))
    {
       p[0]=str[i];
       p[1]='\0';
       push(p);
    }
    else
    {
      char* op1= pop();
      char* op2=pop();
      int k=0;int j=0;
      while(op1[j])
      {
         p[k++]=op1[j++];
      
      
      }
      j=0;
       while(op2[j])
      {
         p[k++]=op2[j++];
      
      
      }
      p[k++]=str[i];
      p[k]='\0';
      
      push(p);
    }
  
  
  
  
  
  
  }
  
}
 
void main()
 {
 char str[sz];
 int ch;
 do{printf("ENTER ONE CHOICE:\n");
 printf("1->POSTFIX TO INFIX\n");
  printf("2->POSTFIX TO PREFIX\n");
   printf("3->PREFIX TO INFIX\n");
    printf("4->PREFIX TO POSTFIX\n");
    printf("5->EXIT\n");
 
      scanf("%i",&ch);
      printf("ENTER THE EXP:\n");
      scanf("%s",str);
      switch(ch)
      {
        case 1:
        postin(str);
        break;
        
        case 2:
        post_pre(str);
        break;
        
        case 3:
        prein(str);
        break;
        
        case 4:
        pre_post(str);
        break;
      }
      int i=0;
      while(stack[top][i])
      {
      printf("%c",stack[top][i++]);
      }
      top--;
      printf("\n");
      
      
       }
      while(ch!=5);
}
  
 

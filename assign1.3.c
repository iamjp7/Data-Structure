#include<stdio.h>
void firstswap(int,int);
void secondswap(int,int);
void thirdswap(int,int);
void main()
{int a,b;
printf("enter the two value");
scanf("%d%d",&a,&b);
firstswap(a,b);
secondswap(a,b);
thirdswap(a,b);
}
void firstswap(int x,int y)
{x=x+y;
y=x-y;
x=x-y;
printf("\nswap value is %d and %d",x,y);
}
void secondswap(int x,int y)
{x=x*y;
y=x/y;
x=x/y;
printf("\nswap value is %d and %d",x,y);
}
void thirdswap(int x,int y)
{x=x^y;
y=y^x;
x=x^y;
printf("\nswap value is %d and %d",x,y);
}

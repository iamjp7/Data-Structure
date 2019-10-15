#include<stdio.h>
void swapcbv(int,int);
void swapcbr(int*,int*);
void main()
{int a,b;
printf("enter two no.");
scanf("%d%d",&a,&b);
swapcbv(a,b);
printf("\nswap value in main by cbv is %d and %d",a,b);
swapcbr(&a,&b);
printf("\nswap value in main by cbr is %d and %d",a,b);
}
void swapcbv(int x,int y)
{int z;
z=x;
x=y;
y=z;
printf("\nswap value in call fn by cbv is %d and %d",x,y);
}
void swapcbr(int* x,int* y)
{int z;
z=*x;
*x=*y;
*y=z;
printf("\nswap value in call fn by cbr is %d and %d",*x,*y);
}


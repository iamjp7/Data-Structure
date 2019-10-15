#include<stdio.h>
void main()
{int i,j,n,k,l,num,ar[500][500];
printf("enter the size of matrix(odd value)");
scanf("%d",&n);
j=n/2;
i=0;
for(num=1;num<=n*n;num++)
{ar[i][j]=num;
i--;
j--;
if(num%n==0)
{	i=i+2;
	j++;
}
else if(i==-1)
	i=n-1;
	else if(j==-1)
	j=n-1;
	else if(i==n)
	i=0;
	else if(j==n)
	j=0;
}
printf("the magic square matrix is\n");
for(k=0;k<n;k++)
{for(l=0;l<n;l++)
	{
printf("%d ",ar[k][l]);

	}
	printf("\n");
}

}

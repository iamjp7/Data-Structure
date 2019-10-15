#include<stdio.h>
int main()
{
	int k=0,i,j,r,c,p;
	printf("\nenter the row and column of sparse matrix ");
	scanf("%d%d",&r,&c);
	int sp[r][c];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("\nenter %d row %d column element of sparse matrix ",i,j);
			scanf("%d",&sp[i][j]);
		}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(sp[i][j]!=0)
				k++;
		}
	int ar[k+1][3];
	ar[0][0]=r,ar[0][1]=c,ar[0][2]=k;
	for(p=1;p<k+1;p++)
	{
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				if(sp[i][j]!=0)
				{
					ar[p][0]=i,ar[p][1]=j,ar[p][2]=sp[i][j];
				}
			break;}
	}

	for(i=0;i<k+1;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",ar[i][j]);
		}
		printf("\n");
		}
return 0;
}

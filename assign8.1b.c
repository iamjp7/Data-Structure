#include<stdio.h>
#include<stdlib.h>
struct mlnode
{
	int row,col,val;
	struct mlnode *nextrow,*nextcol;
};
struct mlnode *create(struct mlnode *head,int r,int c,int sp[r][c])
{
	int i,j;
	struct mlnode *p=head;
	for(i=0;i<c;i++)
	{
		struct mlnode *q=(struct mlnode*)malloc(sizeof(struct mlnode));
		p->nextcol=q;
		q->nextcol=head;
		q->nextrow=q;
		q->row=-1;
		q->col=i;
		p=q;
	}	
	for(i=0;i<r;i++)
        {
                struct mlnode *q=(struct mlnode*)malloc(sizeof(struct mlnode));
                p->nextrow=q;
                q->nextcol=q;
                q->nextrow=head;
                q->row=i;
                q->col=-1;
                p=q;
        }
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(sp[i][j]!=0)
				insert(head,i,j,sp[i][j]);
		}

}
struct mlnode *above(struct mlnode *head,int r,int c)
{
	struct mlnode *p=head->nextcol,*q;
	while(p->col!=c)
	p=p->nextcol;
	do
	{
		q=p;
		p=p->nextrow;
	}while(p->row<r && p->row!=-1);
	return q;
}
struct mlnode *left(struct mlnode *head,int r,int c)
{
        struct mlnode *p=head->nextrow,*q;
        while(p->row!=r)
        p=p->nextrow;
        do
        {
                q=p;
                p=p->nextcol;
        }while(p->col<c && p->col!=-1);
        return q;
}
void insert(struct mlnode *head,int r,int c,int k)
{
	struct mlnode *p=(struct mlnode*)malloc(sizeof(struct mlnode));
	struct mlnode *a=above(head,r,c);
	struct mlnode *l=left(head,r,c);
	p->val=k;
	p->nextrow=a->nextrow;
	p->nextcol=l->nextcol;
	a->nextrow=p;
	l->nextcol=p;
	
}
void display(struct mlnode *head)
{
	struct mlnode *p=head->nextrow,*q;
	while(p!=head)
	{
		do
		{
			q=p->nextcol;
		}while(q!=p);
		p=p->nextrow;
	}
}
int main()
{
	int i,j,r,c;
	printf("\nenter the row and column of sparse matrix\n");
	scanf("%d%d",&r,&c);
	int sp[r][c];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("\nenter %d row %d column element of sparse matrix\n",i,j);
			scanf("%d",&sp[i][j]);
		}
	struct mlnode *head=(struct mlnode*)malloc(sizeof(struct mlnode));
	head->row=-1;
	head->col=-1;
	head->nextrow=head;
	head->nextcol=head;
	create(head,r,c,sp);
	display(head);
}

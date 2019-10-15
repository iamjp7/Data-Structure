#include<stdio.h>
#include<stdlib.h>

struct btnode
{
struct btnode* lchild;
struct btnode* rchild;
int data;
};

typedef struct btnode node;

node* createBtnode(int info)
{
    node *p=(node*)malloc(sizeof(node));
    p->lchild=NULL;
    p->rchild=NULL;
    p->data=info;
    return p;
}
void preorder(node* root)
{
    if(root)
    {
       printf("%4d",root->data);
       preorder(root->lchild);
       preorder(root->rchild); 
    }
return;
}

int search(int* arr, int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
}

node* buildTree(int *in,int *post,int start,int end,int *pIndex)
{
    if(start>end)
        return NULL;
    node* p=createBtnode(post[*pIndex]);
    (*pIndex)--;
    if(start==end)
        return p;
    int iIndex=search(in,start,end,p->data);
    p->rchild=buildTree(in,post,iIndex+1,end,pIndex);
    p->lchild=buildTree(in,post,start,iIndex-1,pIndex);
    return p;

}
int main()
{
    int in[]={4,2,5,1,6,7,3,8};
    int post[]={4,5,2,6,7,8,3,1};
    int n=sizeof(in)/sizeof(in[0]);
    int pIndex=n-1;
    node* root=buildTree(in,post,0,n-1,&pIndex);
    preorder(root);
return 0;
}

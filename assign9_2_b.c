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
void postorder(node* root)
{
    if(root)
    {
       
       postorder(root->lchild);
       postorder(root->rchild);
       printf("%4d",root->data); 
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
node* buildTree(int *in,int *pre,int start,int end,int *pIndex)
{
    if(start>end)
        return NULL;
    node* p=createBtnode(pre[*pIndex]);
    (*pIndex)++;
    if(start==end)
        return p;
    int iIndex=search(in,start,end,p->data);
    p->rchild=buildTree(in,pre,start,iIndex-1,pIndex);
    p->lchild=buildTree(in,pre,iIndex+1,end,pIndex);
    return p;

}
int main()
{
    int in[]={4,2,5,1,6,7,3,8};
    int pre[]={1,2,4,5,3,7,6,8};
    int n=sizeof(in)/sizeof(in[0]);
    int pIndex=0;
    node* root=buildTree(in,pre,0,n-1,&pIndex);
    postorder(root);
return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct btnode
{
struct btnode* lchild;
struct btnode* rchild;
int data;
};

typedef struct btnode node;

node *root1=NULL,*root2=NULL,*ptr;
node* add(int val)
{
ptr=(node*)malloc(sizeof(node));
ptr->data=val;
ptr->lchild=NULL;
ptr->rchild=NULL;
return ptr;
}
bool equalTree(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1!=NULL && root2!=NULL)
        return 
        (
            root1->data==root2->data&&
            equalTree(root1->lchild,root2->lchild)&&
            equalTree(root1->rchild,root2->rchild)
        );
return false;       
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
int main()
{
    root1=add(50);
    root1->lchild=add(20);
    root1->rchild=add(30);
    root1->lchild->lchild=add(70);
    root1->lchild->rchild=add(80);
    root1->lchild->lchild->lchild=add(10);
    root1->lchild->lchild->rchild=add(40);
    root1->lchild->rchild->rchild=add(60);
    preorder(root1);
    printf("\n");
    root2=add(50);
    root2->lchild=add(20);
    root2->rchild=add(30);
    root2->lchild->lchild=add(70);
    root2->lchild->rchild=add(80);
    root2->lchild->lchild->lchild=add(10);
    root2->lchild->lchild->rchild=add(40);
    root2->lchild->rchild->rchild=add(60);
    preorder(root2);
    if(equalTree(root1,root2))
        printf("\nGiven trees are equal");
    else
        printf("\nGiven trees are not equal");


   
    return 0;      
}

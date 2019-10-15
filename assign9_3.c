#include<stdio.h>
#include<stdlib.h>
struct btnode
{
	int info;
	struct btnode *lchild,*rchild; 
};

typedef struct btnode node;

node* insert(node* root,int x)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->info = x;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else if(x < root->info)
		root->lchild = insert(root->lchild,x);
	else if(x > root->info)
		root->rchild = insert(root->rchild,x);
	return root;
}
node* minval(node* root)
{
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
    return root;
}
node* Delete(node* root,int x)
{
	if(root == NULL)
	{
		printf("Tree is empty\n");
		return NULL;
	}
	if(x < root->info)
		root->lchild = Delete(root->lchild,x);
	else if(x > root->info)
		root->rchild = Delete(root->rchild,x);
	else
	{
		if(root->lchild == NULL)
		{
			node* temp = root->rchild;
			free(root);
			return temp;
		}
		else if(root->rchild == NULL)
		{
			node* temp = root->lchild;
			free(root);
			return temp;
		}
		else
		{
            		node *temp=minval(root->rchild);
            		root->info=temp->info;
            		Delete(root->rchild,temp->info);
        	}
	}
	return root;
}

void inorder(node* root)
{
    	if(root)
    	{
       		inorder(root->lchild);
       		printf("%4d",root->info);
       		inorder(root->rchild); 
    	}
	return;
}

int count(node* root)
{
	if(root == NULL)
		return 0;
	return (1+count(root->lchild)+count(root->rchild));
}

int countleaf(node* root)
{
	if(root == NULL)
		return 0;
	if(root->lchild == NULL && root->rchild == NULL)
		return 1;
	return countleaf(root->lchild)+countleaf(root->rchild);
}

int height(node* root)
{
		if(root==NULL)
        	return 0;
    	else
	    {
			int lheight=height(root->lchild);
			int rheight=height(root->rchild);
			if(lheight>rheight)
			    return(lheight+1);
			else
			    return(rheight+1);
	    }
}

int isStBt(node* root)
{
	int ans = 0;
	if(root == NULL)
		ans = 1;
	else if((root->lchild == NULL && root->rchild == NULL)||(root->lchild != NULL && root->rchild != NULL))
	{
		isStBt(root->lchild);
		isStBt(root->rchild);
		ans = 1;
	}
	else if((root->rchild == NULL && root->lchild != NULL) || (root->rchild != NULL && root->lchild == NULL))
		ans = 0;
	return ans;
}

int main()
{
	int ch,x;
	node* root = NULL;
	printf("\t::BINARY SEARCH TREE::\n");
	printf("1.Insert a node\n2.Delete a node\n3.Display inorder traversal\n4.Count no of nodes\n5.Count the number of leaf nodes in a binary tree\n6.Count the number of non-leaf nodes in a binary tree\n7.Calculate the height of the binary tree\n8.Check whether the tree is a strict binary tree or not\n9.Exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the value of node to insert: ");
				scanf("%d",&x);
				root = insert(root,x);
				break;
			case 2:printf("Enter the value of node to delete: ");
				scanf("%d",&x);
				root = Delete(root,x);
				break;
			case 3:inorder(root);
				break;
			case 4:x = count(root);
				printf("Total nodes present are %d",x);
				break;
			case 5:x = countleaf(root);
				printf("Total leaf nodes present are %d",x);
				break;
			case 6:x = count(root) - countleaf(root);
				printf("Total non leaf nodes present are %d",x);
				break;
			case 7:x = height(root);
				printf("Height of the tree is %d",x);
				break;
			case 8:x = isStBt(root);
				if(x)
					printf("YES");
				else
					printf("NO");
				break;
			case 9:exit(1);
				break;
			default:printf("Enter valid choice\n");		
		}
	}
	return 0;
}

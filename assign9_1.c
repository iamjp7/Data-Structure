#include<stdio.h>
#include<stdlib.h>
struct btnode
{
	int info,count;
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
		root->count = 1; 
	}
	else if(x < root->info)
		root->lchild = insert(root->lchild,x);
	else if(x > root->info)
		root->rchild = insert(root->rchild,x);
	else
		root->count++;
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

void preorder(node* root)
{
    	if(root)
    	{
       		printf("%4d",root->info);
       		preorder(root->lchild);
       		preorder(root->rchild); 
    	}
	return;
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

void postorder(node* root)
{
    	if(root)
    	{
       		 postorder(root->lchild);
      		 postorder(root->rchild);
       		printf("%4d",root->info); 
    	}
	return;    
}

int main()
{
	int ch,x;
	node* root = NULL;
	printf("\t::BINARY SEARCH TREE::\n");
	printf("1.Insert a node\n2.Delete a node\n3.Display preorder traversal\n4.Display inorder traversal\n5.Display postorder traversal\n6.Exit");
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
			case 3:preorder(root);
				break;
			case 4:inorder(root);
				break;
			case 5:postorder(root);
				break;
			case 6:exit(1);
				break;
			default:printf("Enter valid choice\n");		
		}
	}
	return 0;
}

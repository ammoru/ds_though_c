#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *left;
	struct Node *right;
	int data;
};
typedef struct Node NODE;
NODE *queue[100],*NN,*root=NULL;
NODE *newnode(int val)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->left=NULL;
	NN->right=NULL;
	return NN;
}
NODE *create_tree(int *arr,int n)
{
	int front=0,rear=0,i=0;
	NN=newnode(arr[0]);
	queue[rear]=NN;
	while(1)
	{
		if (2*i+1>n)
		{
			return queue[0];
		}
		if(arr[2*i+1])
		{
			NN=newnode(arr[2*i+1]);
			queue[++rear]=NN;
			queue[front]->left=NN;
		}
		if(2*i+2<n && arr[2*i+2])
		{
			NN=newnode(arr[2*i+2]);
			queue[++rear]=NN;
			queue[front]->right=NN;
		}
		i++;
		front++;
	}
}
void inorder(NODE *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d \t",root->data);
		inorder(root->right);
	}
		printf("\n ***");
	
}
void preorder(NODE *root)
{
	if (root)
	{
		preorder(root->left);
		printf("%d \t",root->data);
		inorder(root->right);
	}
	
	printf("\n ***");
}
void postorder(NODE *root)
{
	if (root)
	{
		postorder(root->left);
		printf("%d \t",root->data);
		inorder(root->right);
	}
	printf("\n ***");
}
int main()
{
	
	int arr[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	root=create_tree(arr,n);
	inorder(root);
	preorder(root);
	postorder(root);
}

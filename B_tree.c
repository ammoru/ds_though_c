#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node * left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL,*temp,*NN,*par,*dn;

	NODE *newnode(int val)
	{
		NN=(NODE*)malloc(sizeof(NODE ));
		NN->data=val;
		NN->left=NULL;
		NN->right=NULL;
		return NN;
	}
	NODE *deletekey(int key)
	{
		if (root==NULL)
		{
			return NULL;
		}
	  temp=root;
	  par=NULL;
	  while( temp && temp->data!=key)
	  {
	  	if ( temp->data>key)
	  	{
	  		par=temp;
	  		temp=temp->left;
		}
		else if ( temp->data<key)
		{
			par=temp;
			temp=temp->right;
		}
	  }
	  if (temp==NULL)
	  {
	  	return NULL;
	  }
	  if (temp->left==NULL && temp->right== NULL)
	  {
	  	dn=temp;
	  	if (par->right!=NULL && par->right->data==key)
	  	{
	  		par->right=NULL;
		  }
		 else if (par->left!=NULL && par->left->data==key)
	  	{
	  		par->left=NULL;
		} 
		return dn;
	  }
	  else if(temp->left==NULL)
	  {
	  	dn=temp;
	  	// single child
	  	if( par->left!=NULL && par->left->data==key)
	  	{
	  		par->left=temp->right;
		}
		else if( par->right!=NULL && par->right->data==key)
	  	{
	  		par->right=temp->right;
		}
		return dn;
	  }
	  
	  else if(temp->right==NULL)
	  {
	  	 dn=temp;
	  	if( par->left!=NULL && par->left->data==key)
	  	{
	  		par->left=temp->left;
		}
		else if( par->right!=NULL && par->right->data==key)
	  	{
	  		par->right=temp->left;
		}
	  return dn;
	  }
	  	if ( temp->left!=NULL & temp->right!=NULL)
	  	{
	  		NODE *p,*t;
	  		int val;
	  		t=temp->right;
	  		p=NULL;
	  		while(t->left)
	  		{
	  		  	p=t;
	  		  	t=t->left;
			}
			if( p!=NULL)
			{
				dn=t;
				val=t->data;
				t->data=temp->data;
				temp->data=val;
				p->left=t->right;
				return dn;
			}
			else
			{
				dn=t;
				val=t->data;
				t->data=temp->data;
				temp->data=val;
				temp->right=t->right;
				return dn;
				
			}
		}
	  	 
	}
	
	void insert( int val)
	{
		NN=newnode(val);
		temp=root;
		if (root==NULL)
		{
			root=NN;
			return;
		}
		while(1)
		{
			if (temp->data==NN->data)
			{
				printf(" ele is already in treee\n");
				return;
			}
			 else if( temp->data>NN->data)
			{
				if ( temp->left!=NULL)
				{
					temp=temp->left;
				}
				else
				{
					temp->left=NN;
					return;
				}
			}
			 else if ( temp->data < NN->data)
			{
				if ( temp->right!=NULL)
				{
					temp=temp->right;
				}
				else
				{
					temp->right=NN;
					return;
				}
			}
		}
	}
	int search(int key){
		temp=root;
		if(root==NULL)
			{
				return 0;
			}
		while(temp)
		{
	       	
		    if(temp->data==key)
			{
				return 1;
    		}
			else if(temp->data >key)
			{
				temp=temp->left;
			}
			else if( temp->data<key)
			{
				temp=temp->right;
			}	
		}
		return 0;
		
	}
   
	void inorder(NODE *root)
	{
		if( root!=NULL)
		{
			inorder(root->left);
			printf("%d ",root->data);
			inorder(root->right);
		}
	}

	void preorder(NODE *root)
	{
		if( root!=NULL)
		{
			printf("%d ",root->data);	
			preorder(root->left);
			preorder(root->right);
		}
	}
	void postorder(NODE *root)
	{
		if( root!=NULL)
		{
			postorder(root->left);
			postorder(root->right);
			printf("%d ",root->data);
		}
	}
int main()
{
	int ch ,val,key,i,n;
	scanf("%d",&n);
	for( i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
	
	while(1)
	{
		
		printf(" 1.insert,2.delete, 3.search, 4.inorder, 5.preorder,6.postorder,7.leverorder,exit");
		scanf("%d",&ch);
		if (ch==1)
		{
			//insert 
			scanf("%d",&val);
			insert(val);
			
		}  
		else if(ch==2)
		{
			//del
			scanf("%d",&key);
			dn=deletekey(key);
			if (dn)
			{
			printf("%d\n",dn->data);
			free(dn);	
			}
			else
			{
				printf( "ele not found\n");
			}
			
		}
		else if(ch==3)
		{
			//sec
			scanf("%d",&key);
			if(search(key))
			{
				printf("ele found \n");
			}
			else
			{
				printf("Not Found\n");
			}
		}
		else if(ch==4)
		{
			//inorder
			inorder(root);
		}
		else if(ch==5)
		{
			//preorder
			preorder(root);
		}
		else if (ch==6)
		{
			//postorder
			postorder(root);
		}
		else if( ch==7)
		{
			//lever order 
		}
		else{
			break;
		}
	
	}
}
/* 
13
50 40 80 30 45 70 90 25 35 42 48  65 100
*/

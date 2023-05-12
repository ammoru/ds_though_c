#include<stdio.h>
#include<stdlib.h>
struct Node {
	int c;
	int r;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *temp,*head=NULL,*tail=NULL,*NN;
NODE *newnode(int r,int c,int val)
{
  NN= (NODE*)malloc(sizeof(NODE));
  NN->c=c;
  NN->r=r;
  NN->data=val;
  NN->next=NULL;
  return NN;
}
void insert(NODE *head,NODE *tail,NODE *NN)
{
	if (head==NULL && tail==NULL)
	{ head=NN;
	tail=NN;
	}
	else
	{
		tail->next=NN;
		tail=NN;
	}
}
void display()
{
	temp=head;
	while(temp)
	{
		printf("%d %d %d\n",temp->r,temp->c,temp->data);
		temp=temp->next;
	}
}
int main()
{
	int mat[100][100],r,c,i,j;
	scanf("%d %d",&r,&c);
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			NN=newnode(i,j,mat[i][j]);
			insert(head,tail,NN);
		}
	}
	display();
	
}
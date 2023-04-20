#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};
typedef  struct Node NODE;
NODE *NN,*head=NULL,*tail=NULL,*temp,*res,*res1;
NODE *newnode(int val)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->next=NULL;
	NN->prev=NULL;
}
void insert_tail(NODE *NN)
{
	if (head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		
	}
	else
	{
		temp=tail;
		tail->next=NN;
		tail=NN;
		tail->prev=temp;
		tail->next=NULL;
	}
}
void insert_head(NODE *NN)
{
	 if (head==NULL && tail==NULL)
	 {
	 	head=NN;
	 	tail=NN;
	 }
	 else
	 {
	 	NN->next=head;
	 	head->prev=NN;
	 	head=NN;
	 }
}
void insert_pos(NODE *NN,int pos)
{
	temp=head;
	int i;	
	for(i=1;i<pos-1;i++)
	{
		if (temp->next=NULL)
		{
			printf("not possible");
		}
		temp=temp->next;
	}
	res=temp->next;
	NN->next=temp->next;
	temp->next=NN;
	res->prev=NN;
	NN->prev=temp;
	
}
void display_head_to_tail()
{
	if (head==NULL && tail==NULL)
	{
		printf("no nodes");
	}
	temp=head;
	while(temp)
	{
		printf(" %d\n",temp->data);
		temp=temp->next;
	}
}
void display_tail_to_head()
{
	temp=tail;
	while(temp)
	{
		printf("%d\n",temp->data);
		temp=temp->prev;
	}
}
NODE*delete_tail()
{
	if (head==NULL && tail==NULL)
	{
	return NULL;
	}
	temp=head;
	while(temp->next->next)
	{
		temp=temp->next;
	}
	res=temp->next;
	temp->next=NULL;
	res->prev=NULL;
	tail=temp;
	return res;
}
NODE*delete_head()
{
	if (head==NULL && tail==NULL)
	{
	return NULL;
	}
	else
	{
		res=head;
		temp=head;
		head=temp->next;
		temp->next=NULL;
		head->prev=NULL;
		return res;
	}
}
NODE *delete_pos(int pos)
{
	temp=head;
	int p;
	for (p=1;p<pos-1;p++)
	{
		if (temp->next==NULL)
		{
			return NULL;
		}
		temp=temp->next;
	 } 
	 res=temp->next;
	 res1=temp->next->next;
	 temp->next=res->next;
	 res->prev=NULL;
	 res->next=NULL;
	 res1->prev=temp;
	 return res;
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert_tail,2.insert_head,3.inser_pos, 4.display_head_to_tail,5.display_tail_to_head,6.delete_tail,7.delete_head,8.delete_pos");
		scanf("%d",&ch);
		if (ch==1)
		{
			scanf("%d",&val);
			NN=newnode(val);
			insert_tail(NN);
		}
		else if (ch==2)
		{
			//insert head
			scanf("%d",&val);
			NN=newnode(val);
			insert_head(NN);
		}
		else if (ch==3)
		{
			//insert pos
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=newnode(val);
			insert_pos(NN,pos);
		}
		else if (ch==4)
		{
			display_head_to_tail();
		}
		else if (ch==5)
		{
			display_tail_to_head();
		}
		else if (ch==6)
		{
			res=delete_tail();
			if (res==NULL)
			{
				printf("empty\n");
			}
			else
			{
				printf("%d\n",res->data);
			}
		}
		else if (ch==7)
		{
			///delete head 8
			 res=delete_head();
				if (res==NULL)
			{
				printf("empty\n");
			}
			else
			{
				printf("%d\n",res->data);
			}
		}
		else if (ch==8)
		{
			scanf("%d",&pos);
			res=delete_pos(pos);
				if (res==NULL)
			{
				printf("empty\n");
			}
			else
			{
				printf("%d\n",res->data);
			}
		}
		else {
			break;
		}
	}
}
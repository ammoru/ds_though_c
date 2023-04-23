#include<stdio.h.>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *NN,*temp,*res,*head=NULL,*tail=NULL;
NODE *newnode(int val)
{
		    NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			return NN;
}
void insert_tail(NODE *NN)
{
	if (head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		tail->next=NN;
	}
	else
	{
		tail->next=NN;
		tail=NN;
		tail->next=head;
	}
}
void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("empty ....\n");
	}
	else
	{
	  temp=head;
	  while(temp->next!=head)
	  {
	  	printf("%d ",temp->data);
	  	temp=temp->next;
	  }	
	  printf("%d \n",temp->data);
	}
}
void insert_head(NODE *NN)
{
	if (tail==NULL && head==NULL)
	{
		head=NN;
		tail=NN;
		tail->next=head;
	}
	else
	{
		NN->next=head;
		head=NN;
		tail->next=head;
	}
}
NODE *delete_tail()
{
	if (tail==NULL && head==NULL)
	{
		return NULL;
	}
	else
	{
		NODE *dn;
		temp=head;
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
	    	dn=temp->next;
			temp->next=head;
			return dn;
		//printf("%d",temp->data);
	}
}
NODE *delete_head()
{
	int dn;
	if (head==NULL && tail==NULL)
	{
		return NULL;
	}
	else
	{
		 temp=head;
		 head=temp->next;
		 tail->next=head;
		 return temp;
		 temp->next=NULL;
	}
}
void insert_pos(NODE *NN,int pos)
{
	int p;
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		if (temp->next==head)
		{
			printf("not possible");
			return;
			}
	  temp=temp->next;	
	}
	NN->next=temp->next;
	temp->next=NN;
}
NODE *delete_pos(int pos)
{
	int p;
	NODE *dn;
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		if (temp->next==head)
		{
			printf("not possible");
			return NULL;
		}
		temp=temp->next;
	}
	dn=temp->next;
	temp->next=temp->next->next;
	dn->next=NULL;
	return dn;
	
}
int main()
{
   int ch,val,pos;
   while(1)
   {
   	printf("1.insert tail2.display,3.insert_head,4.delet_tail ,5.delete head,6.insert pos,7.delete_pos");
   	scanf("%d",&ch);
   	if (ch==1)
	   {
			//NN->next=NULL;
			scanf("%d",&val);
			NN=newnode(val);
			insert_tail(NN);
		}
		else if(ch==2)
		{
			display();
		}
		else if (ch==3)
		{
			scanf("%d",&val);
		    NN=newnode(val);
			insert_head(NN);	
		}
		else if (ch==4)
		{
			res=delete_tail();
			if (res==NULL)
			{
				printf("NO nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
			}	
		}
		else if (ch==5)
		{
			res=delete_head();
			if (res==NULL)
			{
				printf("NO nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
			}	
		}
		else if (ch==6)
		{
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=newnode(val);
			insert_pos(NN,pos);
		}
		else if (ch==7)
		{
			scanf("%d",&val);
			res=delete_pos(val);
			if (res==NULL)
			{
				printf("NO nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
			}	
		}
		else
		{
			break;
		}
	}
}
                                 
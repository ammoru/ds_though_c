#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

typedef struct node NODE;
NODE *head=NULL,*tail=NULL;
void insert(NODE*NN)
{
	if (head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else {
		tail->next=NN;
		tail=NN;
	}
}
NODE* delete()
{
	NODE * temp,*dn;
	if (head==NULL && tail==NULL)
	{
		return NULL;
	}
	if (head==tail)
	{
		dn=head;
		head=NULL;
		tail=NULL;
		return dn;
	}
	temp=head;
	while(temp->next->next)
	{
		temp=temp->next;	
	}
	temp->next=NULL;
	dn=tail;
	tail=temp;
	return dn;
	
}
void display()
{
	NODE *temp=head;
	if (head==NULL && tail==NULL)
	{
		printf("NO NODES\n");
	}
	else{
		while(temp)
		{
		printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;
		}
	}
}
void  reverse(int cnt)
{
	int arr[cnt],i;
	NODE *temp=head;
	for (i=0;i<cnt;i++)
	{
	  arr[i]=temp->data;
	  temp=temp->next;	
    }
    for(i=cnt-1;i>=0;i--)
    {
    	printf("%d\n",arr[i]);
	}
}
int search(int se)
{
	
	NODE *temp=head;
	int cnt=0;
	while (temp)
	{
		if (temp->data==se)
		{
			cnt+=1;
		}
		temp=temp->next;
		
	}
	return cnt;
}
	
int count()
{
	NODE *temp=head;
	int cnt=0;
	if (head==NULL && tail==NULL)
	{
		return cnt;
	}
    while(temp)
   {
   	   cnt+=1;
   	   temp=temp->next;
   }
	return cnt;   	
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
	 	head=NN;
	 }
 }
 NODE *delete_head()
 {
 	NODE *temp;
 	if (head==NULL && tail==NULL)
 	{
 		return NULL;
	 }
	 else if (head==tail)
	 {
		 	temp=head;
		 	head=NULL;
		 	tail=NULL;
		 	return temp;
	 }
	 else
	 {
	 	temp=head;
	 	head=head->next;
	 	temp->next=NULL;
	 }
 }
int main()
{
	int ch,val;
	NODE *NN,*res;
	while(1)
	{
		printf("1.insert 2.delete 3.display 4.count ,5.insert at  head 6.delete head ,7.search , 8.reverse,,exit");
		scanf("%d",&ch);
		if (ch==1)
		{
			//insert
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert(NN);			
		}
		else if (ch==2)
		{
			//delete
			res=delete();
			if (res==NULL)
			{
				printf("NO NODES\n");
			}
			else{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if (ch==3)
		{
			display();
		}
		else if (ch==4)
		{
			//count 
			printf("%d\n",count());
		}
		else if(ch==5)
		{
		    scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_head(NN);		
		}
		else if (ch==6)
		{
		 	res=delete_head();
			if (res==NULL)
			{
				printf("NO NODES\n");
			}
			else{
				printf("%d\n",res->data);
				free(res);
			}
		}	
		else if (ch==7)
		
		{
			scanf("%d",&val);
			printf("%d\n",search(val));
		}
		else if (ch==8)
		{
			reverse(count());
		}else 
		{
		
    	}
}}
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
 typedef struct Node NODE;
  NODE *NN,*head=NULL,*tail=NULL,*temp;
  
  void display()
  {
  	if (head==NULL && tail==NULL)
   {
   	printf("no node\n");
   }
   else{
	   temp=head;
	   while(temp)
	   {
	   	 printf("%d %d %d\n",temp,temp->data,temp->next);
	   	 temp=temp->next;
	   }
      }
  }
void insert(NODE *NN)
  {
  	if (head==NULL && tail==NULL)
  	{
  		head=NN;
  		tail=NN;
	  }
	  else
	  {
	  	
	  	tail->next=NN;
	  	tail=NN;
	  }
  }
NODE *delet()
  {
  	NODE *dn;
  	if (head==NULL && tail==NULL)
  	{
  		return NULL;
	  }
	 else if(head==tail)
	 {
	 	dn=head;
	 	head=NULL;
	 	tail=NULL;
	 	return dn;
	 }
	 else
	 {
	 	temp=head;
	 	while(temp->next->next)
	 	{
	 		temp=temp->next;
		 }
		 temp->next=NULL;
		 return tail;
		 temp=tail;
	 }
	  
  }
void insert_head(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;	
	}
	else{
     	NN->next=head;
     	head=NN;
	}
}
NODE *delet_head(){
	
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
int  count()
{
	temp=head;
	int cnt=0;
	while(temp)
	{
		cnt+=1;
		temp=temp->next;
	}
	return cnt;
}
void reverse(int cnt)
{
	temp=head;
	 int arr[1000],i;
	for(i=0;i<cnt;i++)
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
	temp=head;
	int cnt=0;
	while(temp)
	{
		 if (temp->data==se)
		 {
		 	cnt+=1;
		 }
		 temp=temp->next;
	}
	return cnt;
}
void insert_position(NODE *NN,int place)
{
	int cnt=0;
	temp=head;
	while(temp)
	{
		if(cnt<place)
		{
			cnt+=1;
		}
		temp=temp->next;
	}
	NN->next=temp->next;
	temp->next=NN;
}
void reverse_list()
{
	if (head==NULL && tail==NULL)
	{
		printf("no nodes\n");
	}
	else if(head==tail)
	{
		printf("its contains single node\n");
	}
	else
	{
		NODE *cur,*prev,*next;
		 tail=head;
		 cur=head;
		 prev=NULL;
		 next=NULL;
		 while(cur)
		 {
		 	next=cur->next;
		 	cur->next=prev;
		 	prev=cur;
		 	cur=next;
		 }
		 head=prev;
	}
}

 int main()
 {
 	int ch,val;
 	NODE *res;
 	while(1)
 	{
 		printf("1.insert,2.delete,3.display,4.insert_head,5.delete _head,6.count,7.reverse,8.search,.9.insert_posti,10.reverse_list,exit");
 	    scanf("%d",&ch);
	   if (ch==1)
	   {
	   	 scanf("%d",&val);
	   	 NN=(NODE *)malloc(sizeof(NODE));
	   	 NN->data=val;
	   	 NN->next=NULL;
	   	 insert(NN);
	   }
	   else if(ch==2)
	   {
	   	 res=delet();
	   	 if (res==NULL)
	   	 {
	   	 	printf("NO nodes");
			}
			else
			{
				printf("%d",res->data);
			}
	   }
	   else if (ch==3)
	   {
	   	display();
	   }
	   else if (ch==4)
	   {
	   	scanf("%d",&val);
	   	 NN=(NODE *)malloc(sizeof(NODE));
	   	 NN->data=val;
	   	 NN->next=NULL;
	   	 insert_head(NN);
	   }
	   else if (ch==5)
	   {
	   	res=delet_head();
	   	if (res==NULL)
	   	{
	   		printf("no nodes");
		  }
		  else
		  {
		  	printf("%d\n",res->data);
		  }
	   }
	   else if (ch==6)
	   {
	   	printf("%d\n",count());
	   }
	   else if(ch==7)
	   {
	   	reverse(count());
	   }
	   else if (ch==8)
	   {
	   	scanf("%d",&val);
	   	printf("%d\n",search(val));
	   }
	   else  if (ch==9)
	   {
	   	scanf("%d",&val);
	   	NN=(NODE *)malloc(sizeof(NODE));
	   	NN->data=val;
	   	NN->next=NULL;
	   	insert_position(NN,val);
	   }
	   else if(ch==10)
	   {
	   	reverse_list();
	   }
	   else 
	   {
	   	break;
	   }
	}
 	
  }

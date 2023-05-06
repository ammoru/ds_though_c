#include<stdio.h>
#include<stdlib.h>
struct Node {
	int co ,pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE  *head1 =NULL,*head2=NULL,*head3=NULL;
NODE  *temp,*temp1,*temp2,*temp3,*NN;

NODE *newnode(int co,int pow)
{
	NN=(NODE *)malloc(sizeof( NODE));
	NN->co=co;
	NN->pow=pow;
	NN->next=NULL;
	return NN;
}
NODE *createpoly(NODE *head)
{
	int co,pow;
	char ch='Y';
	while(ch!='N')
	{
		scanf("%d%d",&co,&pow);
		NN=newnode(co,pow);
	    if (head==NULL)
	    {
	    	head=NN;
		}
		else
		{
			temp=head;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=NN;
		}
		printf("DO you want enter  (Y/N):");
		scanf(" %c",&ch);
		
	}
	
}
void display( NODE *head)
{
	temp=head;
	while(temp)
	{
		printf("%dx%d\t ",temp->co,temp->pow);
		temp=temp->next;
	}
	printf("\n");
}
NODE *addpoly(NODE *head1,NODE *head2,NODE *head3)
{
	temp1=head1;
    temp2=head2;
    while(temp1 && temp2)
    {
    	NN=newnode(0,0);
    	if(head3==NULL)
    	{
    		head3=NN;
		}else
		{
			temp=head3;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=NN;
		}
		if (temp2->pow ==temp1->pow)
		{
			NN->co=temp1->co+temp2->co;
			NN->pow=temp1->pow+temp2->pow;
			temp1=temp1->next;
			temp2=temp->next;
		}
		else if( temp1->pow  > temp2->pow )
		{
			NN->pow=temp1->pow;
			NN->pow=temp2->pow;
			temp1=temp1->next;
		}
	}
}
int main()
{
  head1=createpoly(head1);
  head2=createpoly(head2);
  head3=addpoly(head1,head2,head3);
  display(head1);
  display(head2);
  display(head3);
}

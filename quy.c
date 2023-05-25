/*
QUEUE
first in first  out 
last in last out

rear , front=-1

en queue 
de queue
display f--r

*/
#include<stdio.h>
int queue[100],rear=-1,front=-1,size;
void enque(int val)
{
	if (rear==size-1)
	{
		printf("Queue is full\n");
		return;
	}
	else if (front==-1&&rear==-1)
	{
		front=0;
	}
	else
	{	
		rear++;
		queue[rear]=val;
	}
}
void display()
{
	int i;
	if (rear==-1&&front==-1)
	{
		printf("Queue is empty\n");
	}
	else 
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d",queue[i]);
		}
		printf("\n");
	}
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.enque 2.deque 3.display 4.exit");
		scanf("%d",&ch);
		if (ch==1)
		{
			//enque operation
			scanf("%d",&val);
			enque(val);
		}
		else if (ch==2)
		{
			//deque operation 
			scanf("%d",&val);
		
		}
		else if(ch==3)
		{
			//display operation
			scanf("%d",&val);
			display();
		}
		else {
			break;
		}
	}
}
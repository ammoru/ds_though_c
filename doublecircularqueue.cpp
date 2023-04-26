#include<stdio.h>
int queue[100],size,rear=-1,front=-1;
void enque_rear(int val)
{
	if(front==0&&rear==size-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==front-1)
	{
		printf("Queue is full\n");
	}
	else if (rear==-1 && front==-1)
	{
		rear=0;
		front=0;
		queue[rear]=val;
	}
	else 
	{
		rear=(rear+1)%size;
		queue[rear]=val;
	}
}
 void enque_front( int val)
 {
 	if(front==0&&rear==size-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==front-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==-1 && front==-1)
	{
			rear=0;
		front=0;
		queue[rear]=val;
		
	}
	
	 else if(front==0)
	{
		front=size-1;
		queue[front]=val;
	}
	else 
	{
		front=(front-1)%size;
		queue[front]=val;
	}
 }
void display()
{
	int i=front;
	if (rear==-1&&front==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	while(i!=rear)
	{
		printf("%d ",queue[i]);
		i=(i+1)%size;
	}
	printf("%d\n",queue[i]);
}
 int deque_front()
 {
 {
  	int val;
  	if (rear==-1 && front==-1)
  	{
  		return -1;
	  }
	if (front==rear)
	  {
	   val=queue[front];
	   rear=-1;
	   front=-1;
	   return val;	
	  }
	  val=queue[front];
	  front++;
	  return val;
     }
 }
 int deque_rearend()
 {
 	int val;
 	if (rear==-1 && front==-1)
 	{
 		return -1;
	 }
	  if  (rear==front)
	 {
	 	val=queue[rear];
	 	front=-1;
	 	rear=-1;
	 	return val;
	 }
	 if(rear==0)
	 {
	 	val=queue[rear];
	 	rear=size-1;
	 	return val;
	 }
val=queue[rear];
	 
	 
 }

int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.enque at rear ,2.deque at front,3.displa,n4.enque at front ,5.get rear ,6.front, 7.deque at reear ,8.exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enque at rear
			scanf("%d",&val);
			enque_rear(val);
		}
		else if (ch==2)
		{
		   val=deque_front();
		   	if(val==-1)
				{
					printf("full");
				}
				else
				{
					printf("%d\n",val);
				}
			}
		else if (ch==3)
		{
			//display
			display();
		}
		else if (ch==4)
		{
			scanf("%d",val);
			enque_front(val);
		}
		else if (ch==5)
		{
			printf("%d\n",rear);
		}
		else if (ch==6)
		{
			printf("%d\n",front);
		}
		else if (ch==7)
		{
			//DEQUE AT REARval
		  val=deque_rearend();
				if(val==-1)
				{
					printf("full");
				}
				else
				{
					printf("%d\n",val);
				}
			}
		 else 
		{
			break;
		}
	}
}
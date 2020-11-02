#include <stdio.h>
#include <conio.h>
//function prototypes start
int isempty();
int isfull();
void insert(int,int);
int gethighestpriority();
int deletehighestpriority();
void display();
//function prototypes end


//global variable declare
struct priorityqueue
{
	int ele;
	int priority;
}pq[5];
int rear=-1;
//global variable end

//main function start
main()
{
	int ch,p,ele;
	do
	{
		printf("\n 1.Insert \n 2.gethighestpriority \n 3.deletehighestpriority \n 4.Display \n 5.Exit");
		printf("\n Enter your choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			if (isfull())
				printf("\n Priority Queue is Full");
			else
			{
				printf("\n Enter element to insert :-");
				scanf("%d",&ele);
				printf("\n Enter priority :-");
				scanf("%d",&p);
				insert(ele,p);
			}
			
			break;
			case 2:
			if(isempty())
				printf("\n Priority Queue is Empty");
			else
			{
				p=gethighestpriority();
				printf("\n Highest priority = %d",p);
			}
			break;
			case 3:
			if(isempty())
				printf("\n Priority Queue is Empty");
			else
			{
				ele=deletehighestpriority();
				printf("\n %d is Deleted",ele);
			}
			break;
			case 4:
			if(isempty())
				printf("\n Priority Queue is Empty");
			else
				display();
			break;

			
		}

	}while(ch!=5);
}
//main function end


//user defined function start
int isempty()
{
	if(rear==-1)
		return 1;
	else 
		return 0;
}
int isfull()
{
	if(rear==4)
		return 1;
	else
		return 0;
}
void insert(int ele,int p)
{
	rear=rear+1;
	pq[rear].ele=ele;
	pq[rear].priority=p;
}
int gethighestpriority()
{
	int i,p=-1;
	if(!isempty())
	{
		for(i=0;i<=rear;i++)
		{
			if(pq[i].priority>p)
				p=pq[i].priority;
		}
	}
	return p;
}
int deletehighestpriority()
{
	int i,j,p,ele;
	p=gethighestpriority();
	for(i=0;i<=rear;i++)
	{
		if(pq[i].priority == p)
		{
			ele=pq[i].ele;
			break;

		}
	}
	if(i<rear)
	{
		for(j=i;j<rear;j++)
		{
			pq[j].ele=pq[j+1].ele;
			pq[j].priority=pq[j+1].priority;
		}
	}
	rear=rear-1;
	return ele;
}
void display()
{
	int i;
	printf("\n Priority Queue =");
	for(i=0;i<=rear;i++)
		printf("ele =%d - priority=%d |",pq[i].ele,pq[i].priority);

}



//user defined function end












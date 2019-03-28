//3.1 Circular Queue, front->enqueue, rear->dequeue, simple array, compromising one place (0th index at start)
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int rear=0,front=0;

void enqueue(int a[],int e)
{
	if((rear+1)%SIZE==front)
	{
		printf("Queue Full\n");
	}
	else
	{
		rear = (rear+1)%SIZE;
		a[rear]=e;
		printf("%d Enqueued\n",e);
	}
}

void dequeue(int a[])
{
	if(rear==front)
	{
		printf("Queue Empty\n");
	}
	else
	{
		front = (front+1)%SIZE;
		printf("%d Dequeued\n",a[front]);
	}
}

void display(int a[])
{
	int i,flag;
	printf("Elements in the Queue : ");
	flag = (rear+1)%SIZE;
	i=front+1;
	while(i!=flag)
	{
		printf("%d ",a[i]);
		i=(i+1)%SIZE;
	}
	printf("\n");
}

int main()
{
	int a[SIZE],i,n,e;
	do
	{
		printf("Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :\n ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("Enter element : ");
				scanf("%d",&e);
				enqueue(a,e);
				break;
			case 2:dequeue(a);
				break;
			case 3:display(a);
				break;
			case 4:
				exit(0);
           		default:
                    printf("Wrong Input -_- ! Please Enter the Correct Choice \n");
                    break;
		}
	}while(1);
	return 0;
}
/*
sayali@sayali:~/Desktop/ds$ cc cirQfr.c
sayali@sayali:~/Desktop/ds$ ./a.out
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 12
12 Enqueued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 3
3 Enqueued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 4
4 Enqueued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 5
5 Enqueued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 6
Queue Full
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 12 3 4 5 
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
12 Dequeued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 3 4 5 
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
3 Dequeued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 4 5 
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 567
567 Enqueued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 4 5 567 
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
4 Dequeued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
5 Dequeued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
567 Dequeued
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
Queue Empty
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 4
sayali@sayali:~/Desktop/ds$ */
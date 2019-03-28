//10.1 Static Implementation of Deque i.e. Doubly Ended Queue in a circular fashion
//Deque means Insertion and Deletion is possible from both ends front and rear
//This Circular Fashion sacrifices a position in the array (i.e. Index 0 at the start)

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int rear=0,front=0;

void enqueuer(int a[],int e)
{
    if((rear+1)%SIZE == front)
    {
        printf("Queue Full\n");
    }
    else
    {
        rear    = (rear+1)%SIZE;
        a[rear] = e;
        printf("%d Inserted in Queue\n",e);
    }
}

void enqueuef(int a[],int e)
{
    if((SIZE+front-1)%SIZE == rear)
    {
        printf("Queue Full\n");
    }
    else
    {
        a[front] = e;
        printf("%d Enqueued\n",a[front]);
        front    = (SIZE+front-1)%SIZE;
        printf("Front %d\n",front);
    }
}

void dequeuer(int a[])
{
    if(front == rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("%d Dequeued\n",a[rear]);
        rear = (SIZE+rear-1)%SIZE;
        if (front == rear)
            front=0,rear=0;
    }   
}

void dequeuef(int a[])
{
    if(front == rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        front = (front+1)%SIZE;
        printf("%d Dequeued\n",a[front]);
        if (front == rear)
            front=0,rear=0;
    }   
}

void display(int a[])
{
	int i,flag;
    printf("Front %d\n",front);
	printf("Elements in the Queue : ");
	flag = (rear+1)%SIZE;
	i = (front+1)%SIZE;
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
		printf("1:Enqueue at Rear\n2:Enqueue at Front\n3:Dequeue at Rear\n4:Dequeue at Front\n5:Display\n6:Exit\nEnter choice : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
                printf("Enter element : ");
				scanf("%d",&e);
				enqueuer(a,e);
				break;
            case 2:
                printf("Enter element : ");
				scanf("%d",&e);
				enqueuef(a,e);
				break;
			case 3:dequeuer(a);
				break;
            case 4:dequeuef(a);
				break;
			case 5:display(a);
				break;
			case 6:
				exit(0);
           	default:
                    printf("Wrong Input -_- ! Please Enter the Correct Choice \n");
                    break;
		}
	}while(1);
	return 0;
}

/*
sayali@sayali:~/Repositories/Data-Structures$ cc staticDeq.c 
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 1
Enter element : 12
12 Inserted in Queue
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 2
Enter element : 11
11 Enqueued
Front 4
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 5
Front 4
Elements in the Queue : 11 12 
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 1
Enter element : 56
56 Inserted in Queue
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 5
Front 4
Elements in the Queue : 11 12 56 
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 2
Enter element : 10
10 Enqueued
Front 3
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 5
Front 3
Elements in the Queue : 10 11 12 56 
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 2
Enter element : 43
Queue Full
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 1
Enter element : 56
Queue Full
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 5
Front 3
Elements in the Queue : 10 11 12 56 
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 3
56 Dequeued
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 1
Enter element : 2
2 Inserted in Queue
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 5
Front 3
Elements in the Queue : 10 11 12 2 
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 3
2 Dequeued
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 4
10 Dequeued
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 4
11 Dequeued
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 4
12 Dequeued
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 4
Queue Empty
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 3
Queue Empty
1:Enqueue at Rear
2:Enqueue at Front
3:Dequeue at Rear
4:Dequeue at Front
5:Display
6:Exit
Enter choice : 6
sayali@sayali:~/Repositories/Data-Structures$*/

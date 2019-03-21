//3.2 Circular Queue, front->enqueue, rear->dequeue, simple array, not compromising one place
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define SIZE 5
int rear=-1,front=0, count=0;

void enqueue(int a[],int e)
{
	if(count==SIZE)
	{
		printf("Queue Full\n");
	}
	else
	{
		rear = (rear+1)%SIZE;
		a[rear]=e;
        count++;
		printf("%d Enqueued count=%d front=%d rear=%d\n",e,count,front,rear);
	}
}

void dequeue(int a[])
{
	if(count==0)
	{
		printf("Queue Empty\n");
	}
	else
	{
        printf("%d Dequeued count=%d front=%d rear=%d\n",a[front],count,front,rear);
        front = (front+1)%SIZE;
        count--;
        if(count == 0)
        {
            front = 0;
            rear  = -1;
        }
        
	}
}

void display(int a[])
{
    if(count!=0)
    {
        int i;
	    printf("Elements in the Queue : ");
	    i=front;
	    while(i!=rear)
	    {
		    printf("%d ",a[i]);
		    i=(i+1)%SIZE;
        }
        printf("%d\n",a[i]);
    }
    else
    {
        printf("Queue Empty\n");
    }
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
                printf("Thankyou!\n");
				exit(0);
           		default:
                    printf("Wrong Input -_- ! Please Enter the Correct Choice \n");
                    break;
		}
	}while(1);
	return 0;
}

/*
sayali@sayali:~/Desktop/ds$ cc cirQNotSac.c
sayali@sayali:~/Desktop/ds$ ./a.out
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 12
12 Enqueued count=1 front=0 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 13
13 Enqueued count=2 front=0 rear=1
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 14
14 Enqueued count=3 front=0 rear=2
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 15
15 Enqueued count=4 front=0 rear=3
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 12 13 14 15
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
12 Dequeued count=4 front=0 rear=3
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 13 14 15
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 16
16 Enqueued count=4 front=1 rear=4
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 17
17 Enqueued count=5 front=1 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 13 14 15 16 17
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
13 Dequeued count=5 front=1 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
14 Dequeued count=4 front=2 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
15 Dequeued count=3 front=3 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Elements in the Queue : 16 17
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
16 Dequeued count=2 front=4 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
17 Dequeued count=1 front=0 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
Queue Empty
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 2
Queue Empty
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 3
Queue Empty
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 1
Enter element : 23
23 Enqueued count=1 front=0 rear=0
Enter choice 1:Enqueue 2:Dequeue 3:Display 4:Exit :
 4
Thankyou!
sayali@sayali:~/Desktop/ds$
 */

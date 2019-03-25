//8.2 Queue using Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node;
typedef struct
{
    Node *rear;
    Node *front;
}Q;

void enqueue(Q *q,int ele)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
    p->prev = NULL;
	if(q->rear==NULL)
	{
		q->rear=p;
        q->front=p;
	}
	else
	{
        q->rear->next=p;
        p->prev = q->rear;  
        q->rear=p;
	}
}

void dequeue(Q *q)
{
	if(q->front==NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{
		printf("%d Dequeued\n",q->front->data);
		q->front       = q->front->next; 
        if(q->front == NULL)
            q->rear=NULL;
        else
            q->front->prev = NULL;  //This condition is missing in llqueue.c
	}
}

void display(Q q)
{
	if(q.front==NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{
		while(q.front!=NULL)
		{
			printf("%d\n",q.front->data);
			q.front=q.front->next;
		}	
	}	
}

int main()
{
    Q q;
    q.rear=NULL;
    q.front=NULL;
    int op,ele;
    do
    {
        printf("1:Enqueue Element\n2.Dequeue Element\n3.Display\n5.Exit\nEnter Choice : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                   printf("Enter Element : ");
                   scanf("%d",&ele);
                   enqueue(&q,ele);
                   break;
            case 2:
                   dequeue(&q);
                   break;
            case 3:
                    display(q);
                    break;
            case 5:
                    printf("Thank You!");
                    exit(0);
            default:
                    printf("Wrong Input -_- ! Please Enter the Correct Option\n");
                    break;
        }
    }while(1);
    return 0;
}

/* sayali@sayali:~/Repositories/Data-Structures$ cc DLLQueue.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :1
Enter Element : 12
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :1
Enter Element : 13
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :1
Enter Element : 14
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :3
12
13
14
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :2
12 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :2
13 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :2
14 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :2
Queue Empty
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice :5
Thank You!sayali@sayali:~/Repositories/Data-Structures$*/

//6.2 Dynamic Queue
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
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
	if(q->rear==NULL)
	{
		q->rear=p;
        q->front=p;
	}
	else
	{
        q->rear->next=p;
        q->rear=p;
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

void dequeue(Q *q)
{
	if(q->front==NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{
		printf("%d Dequeued\n",q->front->data);
		q->front=q->front->next;
        if(q->front == NULL)
            q->rear=NULL;
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
                    printf("Thank You!\n");
                    exit(0);
            default:
                    printf("Wrong Input -_- ! Please Enter the Correct Option\n");
                    break;
        }
    }while(1);
    return 0;
}

/*
sayali@sayali:~/Desktop/ds$ cc llqueue.c
sayali@sayali:~/Desktop/ds$ ./a.out
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :1
Enter Element : 12
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :1
Enter Element : 13
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :1
Enter Element : 14
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :3
12
13
14
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :2
12 PoppedEnter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :2
13 PoppedEnter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :2
14 PoppedEnter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :2
Stack Underflow
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :1
Enter Element : 45
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :2
45 PoppedEnter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :1
Enter Element : 56
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :3
56
Enter Choice 1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit :5
Thank You!sayali@sayali:~/Desktop/ds$*/
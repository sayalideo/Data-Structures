//6.2 Dynamic Queue
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
        q->rear=p;
	}
}

void display(Q q)
{
	if(q.front==NULL)
	{
		printf("Stack Underflow\n");
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
		printf("Stack Underflow\n");
	}
	else
	{
		printf("%d Popped",q->front->data);
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
        printf("Enter Choice 1:Enqueue Element\n2.Dequeue Element\n3.Display\n5.Exit :");
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


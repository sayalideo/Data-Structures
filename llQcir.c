//7.2 Queue using Circular Linked List
//Only rear is used
//rear->next is front
//Enqueues at rear->next and rear becomes newly added
//Dequeues at rear->next i.e. front
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
}Q;

void enqueue(Q *q,int ele)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
	if(q->rear==NULL)
	{
        p->next = p;
        q->rear = p;
	}
	else
	{
        p->next = q->rear->next;
        q->rear->next=p;
        q->rear=p;
	}
}

void display(Q q)
{
    Node *temp;
	if(q.rear==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
        temp=q.rear->next;
        printf("Elements in Queue : ");
		do
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=q.rear->next);	
        printf("\n");
	}	
}

void dequeue(Q *q)
{
	if(q->rear==NULL)
	{
		printf("Stack Underflow\n");
	}
    else if(q->rear->next == q->rear)    //When single node is deleted
    {
        printf("%d Popped",q->rear->data);
        q->rear=NULL;
    }    
	else
	{
		printf("%d Popped",q->rear->next->data);
		q->rear->next=q->rear->next->next;
	}
}

int main()
{
    Q q;
    q.rear=NULL;
    int op,ele;
    do
    {
        printf("1:Enqueue Element\n2.Dequeue Element\n3.Display\n4.Exit\nEnter Choice :");
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
            case 4:
                    printf("Thank You!");
                    exit(0);
            default:
                    printf("Wrong Input -_- ! Please Enter the Correct Option\n");
                    break;
        }
    }while(1);
    return 0;
}
/*
sayali@sayali:~/Repositories/Data-Structures$ cc llQcir.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :1
Enter Element : 12
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :1
Enter Element : 13
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :1
Enter Element : 14
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :3
Elements in Queue : 12 13 14 
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :2
12 Popped1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :2
13 Popped1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :2
14 Popped1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :2
Stack Underflow
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :3
Stack Underflow
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :6
Wrong Input -_- ! Please Enter the Correct Option
1:Enqueue Element
2.Dequeue Element
3.Display
4.Exit
Enter Choice :4
Thank You!sayali@sayali:~/Repositories/Data-Structures$ */

//9 Priority Queue using LL
//Priority of the element is decided in ascending order i.e. lowest valued element has highest priority
//Insert Operation takes O(n) time... to insert in terms of priority
//Delete Operation takes O(1) time... to delete the first element 
//Using only front pointer to point to the first element. Last element is identified by 'NULL' in its next part
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
    Node *front;
}PQ;

void enqueue(PQ *q,int ele)
{
    Node *this,*prev;
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = ele;
    p->next = NULL;
    int count = 0;
    this = q->front;
    prev = NULL;
    while(this!=NULL) 
    {
        count = count+1;
        if(p->data < this->data)
            break;
        prev = this;
        this = this->next;
        printf("Count : %d\n",count);
    }
    if(prev!=NULL)
    {
        prev -> next = p;
        p->next = this;
    }
    else
    {
        p->next = this;
        q->front = p;
    }  
}

void dequeue(PQ *q)
{
    if(q->front==NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{
		printf("%d Dequeued\n",q->front->data);
		q->front=q->front->next;
	}
}

void display(PQ q)
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
    PQ q;
    q.front = NULL;
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
sayali@sayali:~/Repositories/Data-Structures$ cc priorityQ.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 12
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 56
Count : 1
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 2
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 43
Count : 1
Count : 2
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 3
2
12
43
56
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 1
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 3
1
2
12
43
56
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 47
Count : 1
Count : 2
Count : 3
Count : 4
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 1
Enter Element : 88
Count : 1
Count : 2
Count : 3
Count : 4
Count : 5
Count : 6
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 3
1
2
12
43
47
56
88
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
1 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
2 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
12 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
43 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
47 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
56 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
88 Dequeued
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 2
Queue Empty
1:Enqueue Element
2.Dequeue Element
3.Display
5.Exit
Enter Choice : 5
Thank You!
sayali@sayali:~/Repositories/Data-Structures$*/

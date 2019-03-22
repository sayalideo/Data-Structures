//8.1 Stack using Doubly Linked List 
//Tos is always the newly added Element
//First inserted element has NULL in its next part 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;
typedef struct
{
    Node *tos;
}S;

void push(S *s,int ele)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
    p->prev = NULL;
	if(s->tos==NULL)
	{
		s->tos=p;
	}
	else
	{
		p->prev=s->tos;
        s->tos->next=p;
		s->tos=p;
	}
}

void display(S s)
{
	if(s.tos==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		while(s.tos!=NULL)
		{
			printf("%d\n",s.tos->data);
			s.tos=s.tos->prev;
		}
        printf("\n");	
	}	
}

void pop(S *s)
{
	if(s->tos==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("%d Popped",s->tos->data);
		s->tos=s->tos->prev;
	}
}

void peek(S s)
{
	if(s.tos==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("%d is at TOS\n",s.tos->data);
	}
} 

int main()
{
    S s;
    s.tos=NULL;
    int op,ele;
    do
    {
        printf("1:Push Element\n2.Pop Element\n3.Peek TOS\n4.Display\n5.Exit\nEnter Choice :");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                   printf("Enter Element : ");
                   scanf("%d",&ele);
                   push(&s,ele);
                   break;
            case 2:
                   pop(&s);
                   break;
            case 3:
                    peek(s);
                    break;
            case 4:

                    display(s);
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

/*sayali@sayali:~/Repositories/Data-Structures$ cc DLLStack.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :1
Enter Element : 45
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :1
Enter Element : 67
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :1
Enter Element : 89
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :4
89
67
45

1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :3
89 is at TOS
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
89 Popped1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
67 Popped1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
45 Popped1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
Stack Underflow
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :4
Stack Underflow
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :5
Thank You!
sayali@sayali:~/Repositories/Data-Structures$ */
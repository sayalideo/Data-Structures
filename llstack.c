//6.1 Dynamic Stack
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
    Node *tos;
}S;

void push(S *s,int ele)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
	if(s->tos==NULL)
	{
		s->tos=p;
	}
	else
	{
		p->next=s->tos;
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
			s.tos=s.tos->next;
		}	
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
		s->tos=s->tos->next;
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
        printf("Enter Choice 1:Push Element\n2.Pop Element\n3.Peek TOS\n4.Display\n5.Exit :");
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
                    printf("Thank You!");
                    exit(0);
            default:
                    printf("Wrong Input -_- ! Please Enter the Correct Option\n");
                    break;
        }
    }while(1);
    return 0;
}

/*sayali@sayali:~/Desktop/ds$ cc llstack.c
sayali@sayali:~/Desktop/ds$ ./a.out
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :1
Enter Element : 112
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :1
Enter Element : 13
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :1
Enter Element : 14
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :1
Enter Element : 15
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :4
15
14
13
112
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :3
15 is at TOS
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :2
15 PoppedEnter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :2
14 PoppedEnter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :2
13 PoppedEnter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :2
112 PoppedEnter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :2
Stack Underflow
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :3
Stack Underflow
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :4
Stack Underflow
Enter Choice 1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit :5
Thank You!sayali@sayali:~/Desktop/ds$*/

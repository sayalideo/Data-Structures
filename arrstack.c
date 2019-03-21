//1.1 Stack array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5										//size of array
struct Stack
{
	float a[SIZE];
	int tos;									//top of stack
};
void push(struct Stack *,float);
float pop(struct Stack *);
float peek(struct Stack);
void display(struct Stack);
int main()
{
	struct Stack s1;								//variable declaration of struct stack
	float ele,data;
	int op;
	s1.tos=-1;
	do
	{
		printf("Enter 1:push 2:pop 3:peek 4:display 5:exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:printf("Enter element to be pushed:");
		       	scanf("%f",&ele);
		       	push(&s1,ele);
		       	break;
	        	case 2:data=pop(&s1);
		       	printf("Popped element:%f\n",data);
		       	break;
			case 3:data=peek(s1);
		       	printf("Required peek element:%f\n",data);
		       	break;
			case 4:display(s1);
			break;
			case 5:exit(0);
		       	break;
			default:printf("Please Enter Correct Choice\n");
			break;
		}
	}while(1);
	return 0;
}
void push(struct Stack *s,float ele)
{
	if(s->tos==SIZE-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		s->tos++;
		s->a[s->tos]=ele;
	}
}
float pop(struct Stack *s)
{
	if(s->tos==-1)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		return (s->a[s->tos--]);
	}
}
float peek(struct Stack s)
{
	return s.a[s.tos];
}
void display(struct Stack s)
{
	int i=s.tos;
	printf("Elements in the stack are:\n");
	for(;i>=0;i--)
	{
		printf("%f\n",s.a[i]);
	}
}

/*output
bash-3.2$ cc stackstatic.c
bash-3.2$ ./a.out
Enter 1:push 2:pop 3:peek 4:display 5:exit
1
Enter element to be entered:12
Enter 1:push 2:pop 3:peek 4:display 5:exit
113
Please Enter Correct Choice
Enter 1:push 2:pop 3:peek 4:display 5:exit
2
Required pop element:12.000000
Enter 1:push 2:pop 3:peek 4:display 5:exit
1
Enter element to be entered:40
Enter 1:push 2:pop 3:peek 4:display 5:exit
3
Required peek element:40.000000
Enter 1:push 2:pop 3:peek 4:display 5:exit
4
Elements in the stack are:
40.000000
Enter 1:push 2:pop 3:peek 4:display 5:exit
5
bash-3.2$
*/

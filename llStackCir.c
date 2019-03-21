//7.2 Stack using Circular Linked List
//TOS points to the latest Element inserted
//First inserted Element points to TOS
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
    Node *temp;
    p->data = ele;
    if(s->tos == NULL)
    {
        s->tos = p;
        p->next = p;
    }
    else
    {
        temp = s->tos;
        while(temp->next!=s->tos)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = s->tos;
        s->tos = p;
        printf("%d Pushed\n",ele);
    }
}

void pop(S *s)
{
    Node *temp;
    if(s->tos == NULL)
    {
        printf("Stack Underflow\n");
    }
    else if(s->tos->next == s->tos)
    {
        printf("%d Popped\n",s->tos->data);
        s->tos = NULL;
    }
    else
    {
        temp = s->tos;
        while(temp->next!=s->tos)
        {
            temp = temp->next;
        }  
        printf("%d Popped\n",s->tos->data);
        temp->next = s->tos->next;
        s->tos = s->tos->next;      
    }
}

void peek(S s)
{
    if(s.tos==NULL)
        printf("Stack Underflow\n");
    else
    {
        printf("%d is at TOS\n",s.tos->data);
    }
    

}

void display(S s)
{
    Node *temp = s.tos;
    if(s.tos == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Stack Elements : ");
       do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        } while (temp!=s.tos);
        printf("\n");
    }
}

int main()
{
    S s;
    s.tos = NULL;
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

/*sayali@sayali:~/Repositories/Data-Structures$ cc llStackCir.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :1
Enter Element : 12
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :1
Enter Element : 13
13 Pushed
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :1
Enter Element : 56
56 Pushed
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :4
Stack Elements : 56 13 12 
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :3
56 is at TOS
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
56 Popped
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :3
13 is at TOS
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
13 Popped
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :2
12 Popped
1:Push Element
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
Enter Choice :3
Stack Underflow
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :6
Wrong Input -_- ! Please Enter the Correct Option
1:Push Element
2.Pop Element
3.Peek TOS
4.Display
5.Exit
Enter Choice :5
Thank You!
sayali@sayali:~/Repositories/Data-Structures$*/

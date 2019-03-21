//1.2 Two stacks
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int tos1 = -1;
int tos2 = SIZE;

void push1(int a[],int e)
{
    if(tos1 == tos2 - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        tos1++;
        a[tos1] = e;
        printf("%d Inserted\n",e);
    }
}

void push2(int a[],int e)
{
    if(tos2 == tos1 + 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        tos2--;
        a[tos2] = e;
        printf("%d Inserted\n",e);
    }
}

void pop1(int a[])
{
    if(tos1 == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d Popped\n",a[tos1]);
        tos1--;
    }
}

void pop2(int a[])
{
    if(tos2 == SIZE)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d Popped\n",a[tos2]);
        tos2++;
    }
}

void display(int a[])
{
    int i;
    if(tos1 != -1)
    {
        printf("Stack1 : ");
        for(i=0;i<=tos1;i++)
        {
            printf("%d ",a[i]);
        }
    }
    if(tos2 != SIZE)
    {
        printf("\nStack2 : ");
        for(i=SIZE-1;i>=tos2;i--)
        {
            printf("%d ",a[i]);
        }
    }
    printf("\n");
}

int main()
{
    int a[SIZE],i=0,flag=1,ele,ch;
    while(flag)
    {
        printf("1. Push in Stack1\n2. Push in Stack2\n3. Pop from Stack1\n4.Pop from Stack2\n5. Display\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1 : 
                printf("Enter Element : ");
                scanf("%d",&ele);
                push1(a,ele);
                break;
            case 2 : 
                printf("Enter Element : ");
                scanf("%d",&ele);
                push2(a,ele);
                break;
            case 3 :
                pop1(a);
                break;
            case 4 :
                pop2(a);
                break;
            case 5 :
                display(a);
                break;
            case 6 :
                printf("\nThank You!");
                flag=0;
                break;
        
            default:
                printf("Wrong Input -_-! Re - Enter");
                break;
        }
    }
    return 0;
}
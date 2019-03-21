//4 Implementation of Circular Linked List. Assume pt points to the last Node of LL.
//This is to ensure insert at beg and end does not require traversal of whole list.
//Thus, insertion at the end and beginning is the same
// Last Node contains next=first node
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
    Node *pt;
}LL;

void insert(LL *l,int ele)
{
    Node *temp;
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
	if(l->pt==NULL)
	{
		l->pt=p;
	}
	else
	{
        p->next=l->pt->next;
        l->pt->next=p;
	}
}

void insertBefore(LL *l,int ele,int s) //inserts ele before search element s
{
    Node *temp,*rev;
    int flag = 0;
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
	if(l->pt==NULL)
	{
		printf("Search Element %d Not Found\n",s);
	}
	else if(l->pt->data == s)
	{
        rev = l->pt;
        while(rev->next != l->pt)
        {
            if(rev->next->data == s)
                break;
            else
            {
                rev=rev->next;
            }
        }
        p->next = l->pt; 
    }
    else
    {
        temp = l->pt->next;
        rev = l->pt;
        while(temp->next!=l->pt)
        {
            if(temp->data == s)
            {
                flag = 1;
                
            }
        }
        
    }
}

void deleteBeg(LL *l)
{
	if(l->pt==NULL)
	{
		printf("Stack Underflow\n");
	}
    else if(l->pt->next == NULL)
    {
        printf("%d Deleted\n",l->pt->data);
        l->pt = NULL;
    }
	else
	{
		printf("%d Deleted\n",l->pt->data);
        l->pt = l->pt->next;
	}
}

void deleteEnd(LL *l)
{
    Node *temp;
	if(l->pt==NULL)
	{
		printf("Stack Underflow\n");
	}
    else if(l->pt->next == NULL)
    {
        printf("%d Deleted\n",l->pt->data);
        l->pt = NULL;
    }
	else
	{
        temp = l->pt;
        while(temp->next->next!=NULL)
            temp=temp->next;
		printf("%d Deleted\n",temp->next->data);
		temp->next = NULL;
	}
}

void display(LL l)
{
	if(l.pt==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		while(l.pt!=NULL)
		{
			printf("%d ",l.pt->data);
			l.pt=l.pt->next;
		}
        printf("\n");	
	}	
}

int main()
{
    LL l;
    l.pt=NULL;
    int op,ele;
    do
    {
        printf("1:InsertBeg Element\n2.InsertEnd Element\n3.Delete Beg\n4.Delete End\n5.Display\n6.Exit\nEnter Choice : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                   printf("Enter Element : ");
                   scanf("%d",&ele);
                   insertBeg(&l,ele);
                   break;
            case 2:
                   printf("Enter Element : ");
                   scanf("%d",&ele);
                   insertEnd(&l,ele);
                   break;
            case 3: 
                   deleteBeg(&l);
                   break;
            case 4:
                   deleteEnd(&l);
                   break;
            case 5:
                    display(l);
                    break;
            case 6:
                    printf("Thank You!\n");
                    exit(0);
            default:
                    printf("Wrong Input -_- ! Please Enter the Correct Option\n");
                    break;
        }
    }while(1);
    return 0;
}

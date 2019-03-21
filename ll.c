//4 Implementation of Linked List. Assume pt points to the first Node of LL. Last Node contains next=NULL
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

void insertEnd(LL *l,int ele)
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
        temp = l->pt;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = p;
	}
}

void insertBeg(LL *l,int ele)
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
        p->next=l->pt;
        l->pt = p;
    }
}

void deleteBeg(LL *l)
{
	if(l->pt==NULL)
	{
		printf("List Empty\n");
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
		printf("List Empty\n");
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
		printf("List Empty\n");
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

void reverse(LL *l)
{
    Node *this,*prev,*frwd,*temp;
    if(l->pt == NULL)
        printf("List Empty\n");
    else if(l->pt->next == NULL)
        printf("List Reversed\n");
    else
    {
        prev = l->pt;
        this = l->pt->next;
        frwd = this->next;
        if(frwd == NULL)
        {
            prev->next = NULL;
            this->next = prev;
            l->pt = this;
        }
        else
        {
            prev->next = NULL;
            while(frwd!=NULL)
            {
                this->next = prev;
                temp=frwd->next;
                frwd->next = this;
                prev = this;
                this = frwd;
                frwd = temp;
            }
            l->pt = this;
        }
        printf("List Reversed\n");
    }
    
}

int main()
{
    LL l;
    l.pt=NULL;
    int op,ele;
    do
    {
        printf("1:InsertBeg Element\n2.InsertEnd Element\n3.Delete Beg\n4.Delete End\n5.Reverse List\n6.Display\n7.Exit\nEnter Choice : ");
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
                    reverse(&l);
                    break;
            case 6:
                    display(l);
                    break;
            case 7:
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
sayali@sayali:~/Repositories/Data-Structures$ cc ll.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 1
Enter Element : 12
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 2
Enter Element : 13
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 1
Enter Element : 11
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
11 12 13 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 5
List Reversed
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
13 12 11 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 1
Enter Element : 15
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
15 13 12 11 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 5
List Reversed
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
11 12 13 15 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 3
11 Deleted
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 3
12 Deleted
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
13 15 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 5
List Reversed
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
15 13 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 4
13 Deleted
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 5
List Reversed
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 6
15 
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 3
15 Deleted
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 5
List Empty
1:InsertBeg Element
2.InsertEnd Element
3.Delete Beg
4.Delete End
5.Reverse List
6.Display
7.Exit
Enter Choice : 7
Thank You!
sayali@sayali:~/Repositories/Data-Structures$ */
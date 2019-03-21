//4 Implementation of Circular Linked List. Assume pt points to the last Node of LL.
//This is to ensure insert at beg and end does not require traversal of whole list.
//Thus, insertion at the end and beginning is the same
// Last Node contains next=first node
//Assumng that l->pt does not change in insert Before and After functions
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

void insertBeg(LL *l,int ele)   //Same as insertEnd, just don't update l->pt
{
    Node *temp;
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
	if(l->pt==NULL)
	{
		l->pt=p;
        p->next=p;
	}
	else
	{
        p->next=l->pt->next;
        l->pt->next=p;
	}
}

void insertEnd(LL *l,int ele)   //Same as insertBeg, just update l->pt
{
    Node *temp;
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ele;
	p->next = NULL;
	if(l->pt==NULL)
	{
		l->pt=p;
        p->next=p;
	}
	else
	{
        p->next=l->pt->next;
        l->pt->next=p;
        l->pt = p;          //Points to new node as it is the end of list now
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
    else
    {
        temp = l->pt;
        do
        {
            if(temp->next->data == s)
            {
                flag = 1;
                p->next=temp->next;
                temp->next = p;
                break;
            }
            temp = temp->next;
        } while (temp!=l->pt);
        if(flag == 0)
        {
            printf("Search Element %d not found\n",s);
        }
    }
}

void insertAfter(LL *l,int e,int s)     //Inserts after element s
{
    Node *temp;
    int flag = 0; 
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    if(l->pt == NULL)
    {
        printf("Search Element %d not found\n",s);
    }
    else
    {
        temp = l->pt;
        do
        {
            if(temp->data == s)
            {
                flag = 1;
                p->next=temp->next;
                temp->next = p;
                break;
            }
            temp = temp->next;
        } while (temp!=l->pt);
        if(flag == 0)
        {
            printf("Search Element %d not found\n",s);
        }
    }
}

void delete(LL *l,int ele)
{
    Node *temp;
    int flag=0;
	if(l->pt==NULL)
	{
		printf("Stack Underflow\n");
	}
    else if((l->pt->next == l->pt)&&(l->pt->data == ele))   //If single node is to be deleted
    {
        l->pt = NULL;
        printf("%d Deleted\n",ele);
    }
	else    //Deletes all types of elements, even if it is at l->pt
	{
		temp = l->pt;
        do
        {
            if(temp->next->data == ele)
            {
                flag = 1;
                if(temp->next==l->pt)
                    l->pt = temp;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        } while (temp!=l->pt);
        if(flag == 0)
        {
            printf("Element to be Deleted %d not found\n",ele);
        }
	}
}

void display(LL l)
{
    Node* temp;
	if(l.pt==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
        printf("l->pt %d\n",l.pt->data);
        temp=l.pt->next;
		while(temp!=l.pt)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
        printf("%d ",l.pt->data);
        printf("\n");	
	}	
}

int main()
{
    LL l;
    l.pt=NULL;
    int op,ele,s;
    do
    {
        printf("1:Insert at the Beginning Element\n2.Insert at the End Element\n3.Insert Before an Element\n4.Insert After an Element\n5.Delete Element\n6.Display\n7.Exit\nEnter Choice : ");
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
                    printf("Enter Element to be Inserted : ");
                    scanf("%d",&ele);
                    printf("Enter Search Element before which %d is to be Inserted : ",ele);
                    scanf("%d",&s);
                    insertBefore(&l,ele,s);
                    break;
            case 4:
                    printf("Enter Element to be Inserted : ");
                    scanf("%d",&ele);
                    printf("Enter Search Element after which %d is to be Inserted : ",ele);
                    scanf("%d",&s);
                    insertAfter(&l,ele,s);
                    break;
            case 5:
                    printf("Enter Element to be Deleted : ");
                    scanf("%d",&ele);
                    delete(&l,ele);
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

/*sayali@sayali:~/Repositories/Data-Structures$ cc llcir.c
sayali@sayali:~/Repositories/Data-Structures$ ./a.out
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 1
Enter Element : 133
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 2
Enter Element : 566
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 2
Enter Element : 4
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 3
Enter Element to be Inserted : 58
Enter Search Element before which 58 is to be Inserted : 4
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 4
Enter Element to be Inserted : 78
Enter Search Element after which 78 is to be Inserted : 4
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 6
l->pt 4
78 133 566 58 4 
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 5
Enter Element to be Deleted : 4
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 6
l->pt 58
78 133 566 58 
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 5
Enter Element to be Deleted : 78
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 6
l->pt 58
133 566 58 
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 5
Enter Element to be Deleted : 566
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 6
l->pt 58
133 58 
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 5
Enter Element to be Deleted : 58
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 6
l->pt 133
133 
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 5
Enter Element to be Deleted : 133
133 Deleted
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 6
Stack Underflow
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 8
Wrong Input -_- ! Please Enter the Correct Option
1:Insert at the Beginning Element
2.Insert at the End Element
3.Insert Before an Element
4.Insert After an Element
5.Delete Element
6.Display
7.Exit
Enter Choice : 7
Thank You!
sayali@sayali:~/Repositories/Data-Structures$*/

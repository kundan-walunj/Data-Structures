#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};
struct node *head;


void create(int item)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));//allocate memory in heap( data type and size to allocate)
    struct node *temp;
    ptr->data=item;
    if(head==NULL)//for first element
    {
        ptr->next=NULL;
        head=ptr;
    }
    else// not first element
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;//temp nextrdf points to new node
        ptr->next=NULL;//new node pointer becomes null
    }
}
void display()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("link list empty\n");
    }
    else
    {
        printf("Elements of link list are:\n");
        while(ptr!=NULL)
        {
            printf("\t%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}
int length()
{
    int count=0;
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        printf("length of link list is:\n");
        printf("%d\n",count);
        return;

}

void insertion(int item,int pos)
{
   struct node *ptr=(struct node*)malloc(sizeof(struct node));
   struct node *temp;
   int i;
   ptr->data=item;
   temp=head;
   for(i=0;i<pos-1;i++)
   {
       temp=temp->next;
       if(temp==NULL)
       {
           printf("can't insert\n");
           return;
       }
   }//temp point to one position less
   ptr->next=temp->next;//temp next contain next location add is stored in new node next
   temp->next=ptr;//temp next(pev node) address of new node(ptr) is stored

   printf("Node inserted\n");
}
void delete(int pos)
{
   struct node *ptr1,*ptr2;
   ptr1=head;
   for(int i=0;i<pos;i++)
   {
       ptr2=ptr1;//ptr2 points to previous node and ptr1 to delete node
       ptr1=ptr1->next;
       if(ptr1==NULL)
       {
           printf("There are less elements than %d\n",pos);
           return;
       }
   }
   ptr2->next=ptr1->next; //address of front node is stored in previous node
   free(ptr1); //deallocate memory
   printf("Deleted %d node\n",pos);
}
void sortList() {
                       //Node current will point to head
        struct node *current = head, *index = NULL;
        int temp;

            while(current != NULL) {
                                                //Node index will point to node next to current
                index = current->next;

            while(index != NULL) {
                                              //If current node's data is greater than index's node data, swap the data between them
            if(current->data > index->data) {
            temp = current->data;
            current->data = index->data;
            index->data = temp;
            }
            index = index->next;
            }
            current = current->next;
            }
        printf("The sorted list is:\n");
        display();
        }
void reverse()
{
    struct node *p, *q, *r;

    p = q = r =head;
    p = p->next->next;//points to third pos
    q = q->next;//points to second pos
    r->next = NULL;
    q->next = r;//q next point to prev node

    while (p != NULL)
    {
        r = q;//inc r
        q = p;//inc q
        p = p->next;//inc p
        q->next = r;
    }
    head = q;
    display();
}

int main()
{
int p,num,num1,p1,del,m1,m2,merge;
int choice,ch;
printf("---OPERATION ON LINKLIST---\n");
printf(" 1.Insert\n 2.Display\n 3.Length\n 4.Insert(Position)\n 5.Delete(Position)\n 6.Sorting\n 7.reverse\n 8.merge link list\n 9.Exit\n");
 do
    {
        printf("Enter the Choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the element to insert:\n");
                scanf("%d",&num);
                create(num);
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                length();
                break;
            }
            case 4:
                {
                 printf("Enter the element to insert:\n");
                 scanf("%d",&num1);
                 printf("Enter the position:\n");
                 scanf("%d",&p1);
                 insertion(num1,p1);
                 break;
                }
            case 5:
                {
                 printf("Enter the position to delete:\n");
                 scanf("%d",&del);
                 delete(del);
                 break;
                }
            case 6:
                {
                    sortList();
                    break;
                }
            case 7:
                {
                    reverse();
                    break;
                }

            case 9:
            {
                printf(" EXIT \n THANK YOU\n");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice\n");
            }

        }
    }
    while(choice!=9);
}






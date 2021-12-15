#include <stdio.h>
#include <stdlib.h>
//pizza order by queue
struct pizza
{
    int id,qty;
    char name[20];
    char address[30];

};
int rear=-1;
int front=-1;
int id=1;

int q_empty()
{
    if(rear==front)
        return 1;
    else
        return 0;
}
void place_order(struct pizza p[],int n)
{
    rear++;
    if(rear<n){
    p[rear].id=id++;
    printf("Enter the name:\n");
    scanf(" %s",&p[rear].name);
    printf("Enter the address:\n");
    scanf("%s",&p[rear].address);
    printf("Enter quantity:\n");
    scanf(" %d",&p[rear].qty);
    }
    else//if rear is greater than n
    printf("Order is full");
}
void dispatch_order(struct pizza p[])
{
    if(q_empty()==0)
    {
        front++;
        printf("dispatched order is:\n");
        printf("ID:%d\n",p[front].id);

    }
    else//front==rear
        printf("no more orders to be dispatched\n");

}

void display(struct pizza p[])
{
      int i;
      if(q_empty()==1){
        printf("No orders pending");
      }
      else{
    printf("Pending orders are:\n");
    for(i=front+1;i<=rear;i++){
    printf("ID:%d\t--\t",p[i].id);
    printf("Name:%s\t--\t",&p[i].name);
    printf("No of Pizza:%d\n",p[i].qty);
    }
    }

}
int main()
{
int choice;
 int n;
 struct pizza p[n];
 printf("\nEnter the max no of orders:\t");
 scanf("%d",&n);
 printf("\n PIZZA PARLOR");
    printf("\n 1.PLACE ORDER \n 2.DISPATCH ORDER\n 3.PENDING ORDERS \n 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                place_order(p,n);
                break;
            }
            case 2:
            {
                dispatch_order(p);
                break;
            }
            case 3:
            {
                display(p);
                break;
            }
            case 4:
                {
                 printf("THANK YOU\n");
                 break;
                }

            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(choice!=4);
}




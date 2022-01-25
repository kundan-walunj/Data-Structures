#include <stdio.h>
#include <stdlib.h>
//pizza order by circular queue
struct pizza
{
    int id,qty;
    char name[20];
    char address[30];

};
int rear=0;
int front=0;
int id=1;

int q_full(int n,struct pizza p[])
{
    if(rear==n-1 && front==0)
    return 1;
    else
    return 0;

}
int q_empty()
{
    if(front==rear)
        return 1;
    else
        return 0;
}
void place_order(struct pizza p[],int n)
{
    if(((rear+1)%n)==front){
    printf("Order is full");
    }
    else{
    rear=(rear+1)%n;
    p[rear].id=id++;
    printf("Enter the name:\n");
    scanf(" %s",&p[rear].name);
    printf("Enter the address:\n");
    scanf("%s",&p[rear].address);
    printf("Enter quantity:\n");
    scanf(" %d",&p[rear].qty);
    }

}
void dispatch_order(struct pizza p[],int n)
{
    if(q_empty()==0)
    {
        printf("dispatched order is:\n");
        printf("ID:%d\n",p[front].id);
        front=(front+1)%n;

    }
    else
        printf("no more orders to be dispatched\n");

}

void display(struct pizza p[],int n)
{
    printf("Pending orders are:\n");
    if(rear>=front){
    for(int i=front+1;i<=rear;i++){
    printf("ID:%d\t--\t",p[i].id);
    printf("Name:%s\t--\t",&p[i].name);
    printf("No of Pizza:%d\n",p[i].qty);
    }
    }
    else{
        for(int i=front+1;i<=n;i++){
    printf("ID:%d\t--\t",p[i].id);
    printf("Name:%s\t--\t",&p[i].name);
    printf("No of Pizza:%d\n",p[i].qty);
        }

}}
int main()
{
int choice;
 int n;
 struct pizza p[n];
 printf("\nEnter the max no of orders:\t");
 scanf("%d",&n);
 printf("\n PIZZA PARLOR USING CIRCULAR QUEUE");
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
                dispatch_order(p,n);
                break;
            }
            case 3:
            {
                display(p,n);
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

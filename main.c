//infix to postfix useing stack
#include<stdio.h>
#include<string.h>
char stack[100],x,stack1[50][50];
int choice,n,i,top=-1;
void push(char x)
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");

    }
    else
    {
        top++;
        stack[top]=x;
    }
}
char pop()
{
    char k;
    if(top<=-1)
    {
        printf("\n\t Stack is EMPTY");
    }
    else
    {   k=stack[top];
        top--;
    }
    return k;
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%c",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }

}
int icp(char ch){
if(ch=='+'|| ch=='-')
    return 1;
if(ch=='*'|| ch=='/')
    return 2;
if(ch=='^')
    return 4;
if(ch=='(')
    return 5;
else
    return 0;
}
int isp(char ch){
if(ch=='+'|| ch=='-')
    return 1;
if(ch=='*'|| ch=='/')
    return 2;
if(ch=='^')
    return 3;
else
    return 0;
}

int postfix(char infix_input[])
{
char postfix[50],token,elem;
int i=0,k=0;
push('#');
while( (token=infix_input[i++]) != '\0')
    {
        if( token == '(') push(token);
        else
            if(token>='a'&&token<='z') postfix[k++]=token;//operand
            else
                if( token == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    elem=pop();
                }
                else
                { //operator
                    while( isp(stack[top]) >= icp(token))
                        postfix[k++]=pop();
                    push(token);
                }
    }
    while( stack[top] != '#')
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("\nPostfix Expression =  %s\n",postfix);
}
//postfix to infix
void push1(char str1[50]){
top++;
strcpy(stack1[top],str1);
}
char *pop1()
{
    char* temp=stack1[top];
    top--;
    return(temp);
}
void post_infix(char tkn[30])
{
	char str1[20],str[20],op1[20],op2[20],str2[20];
	int i,l;
	for(i=0;tkn[i]!='\0';i++)
	{
		if(tkn[i]=='+'||tkn[i]=='-'||tkn[i]=='*'||tkn[i]=='/')
		{
			strcpy(op1,pop1());//operand 1 in op1
			strcpy(op2,pop1());//operand 2 in op2
			str2[0]='\0';
			str2[0]='(';   //bracket at first index of str2
			str2[1]='\0';
			strcat(str2,op2); //concat  str2 and first oprand
			l=strlen(str2);   //store length of str2 in l
			str2[l]=tkn[i];   //store operator at lth position
			str2[l+1]='\0';
			strcat(str2,op1); //concat str2 and second oprand
			l=strlen(str2);   //store length of str2
			str2[l]=')';      //store bracket at index position l
			str2[l+1]='\0';
			push1(str2);
		}
		else
		{
			str1[0]='\0';
			str1[0]=tkn[i]; //store operand in str1
			str1[1]='\0';
			push1(str1);
		}
	}
	strcpy(str1,pop1());
	printf("\nInfix Expression is: %s\n",str1);
}
int main()
{
    char infix_input[100];
    char exp[100];
    printf("\n Enter the size of STACK:");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS ");
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.INFIX TO POSTFIX\n 5.POSTFIX TO INFIX\n 6.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
               printf(" Enter a character to be pushed:");
               scanf(" %c",&x);
                push(x);
                break;
            }
            case 2:
            {
                char o;
                o=pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
                {
                 printf("enter the expression:\n");
                 scanf(" %s",infix_input);
                 postfix(infix_input);
                 break;
                }
            case 5:
                {
                 printf("enter the expression:\n");
                 scanf(" %s",exp);
                 post_infix(exp);
                 break;
                }
            case 6:
            {
                printf("\n EXIT \n THANK YOU");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(choice!=6);
}

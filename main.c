#include <stdio.h>
#include <stdlib.h>

int main()
{
 int i=0,j=0;
 int count=1;
char s[100];
char *ptr1;
ptr1=s;
char s1[100],s2[100];
char *ptrs1;
char *ptrs2;
ptrs1=s1;
ptrs2=s2;
char str1[100],str2[100],str3[100];
char *ps1;
char *ps2;
char *ps3;
ps1=str1,ps2=str2,ps3=str3;
while(count!=0)
    {
    int ch;
 printf(" operation on string :\n");
 printf(" 1.length\n 2.copy\n 3.conccatenate\n 4.exit\n ");
printf("enter the choise\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 {
    printf("enter the string:\n");
    scanf("%s",&s);
    while(*ptr1!='\0')
    {
        ptr1++;
        i++;
    }
    printf("length of the string:%d\n",i);
    break;
 }
 case 2:
 {
    printf("enter the string:\n");
    scanf("%s",&s1);
    while(*ptrs1!='\0'){
        *ptrs2=*ptrs1;
        ptrs1++;
        ptrs2++;
    }
    ptrs2='\0';
     printf("string s2 is:%s\n",s2);
     break;
 }
 case 3:
{
      printf("enter the first string:\n");
      scanf("%s",&str1);
       printf("enter the second  string:\n");
       scanf("%s",&str2);

    while (*ps1!='\0') {
            *ps3=*ps1;
        ps3++;
        ps1++;
    }
    while (*ps2!='\0') {
        *ps3=*ps2;
        ps3++;
        ps2++;
    }
    *ps3='\0';
    printf("\nConcatenated string: %s\n", str3);
   break;
 }
 case 4:
 {
    printf("thank you");
    count=0;
    break;
 }
 default:
 {
    printf("invalid input\n");
    break;
 }
}
}
}

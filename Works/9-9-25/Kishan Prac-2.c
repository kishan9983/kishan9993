#include<stdio.h>
#include<conio.h>
void main()
{
   int marks;
   printf("Enter Your Marks");
   scanf("%d",&marks);
   if(marks>35)
   {
       printf("Pass");
   }
   else
   {
       printf("Fail");
   }
   
    getch();
}
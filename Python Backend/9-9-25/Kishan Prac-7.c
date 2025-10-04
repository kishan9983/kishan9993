#include<stdio.h>
#include<conio.h>
void main()
{
   int num;
   printf("Enter Your Number");
    scanf("%d",&num);
    switch(num)
    {
       case 1 : printf("Your Selected language is English"); 
       break;
       case 2 : printf("Your Selected language is Hindi"); 
       break;
       case 3 : printf("Your Selected language is Gujarati"); 
       break;
       default: printf("Invalid Number");
       break;
          }
    getch();
}
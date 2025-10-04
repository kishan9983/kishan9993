#include<stdio.h>
#include<conio.h>
void main()
{
   int num;
printf("Enter Your Number");
    scanf("%d",&num);
 if(num==1)
    {
        printf("\n Your Selected Language is Gujarati");     
    }
    else if(num==2)
    {
           printf("\n Your Selected Language is Hindi");     
    }
    else if(num==3)
    {
           printf("\n Your Selected Language is English");     
    }
    else
    {
         printf("\n Invalid Number");  
    }
   getch();
}
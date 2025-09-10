#include<stdio.h>
#include<conio.h>
void main()
{
    int year;
    printf("Enter Year");
    scanf("%d",&year);
    
    if(year%4==0)
    {
        printf("leap year");
    }
    else
    {
        printf("not leap year");
    }
   getch();
}
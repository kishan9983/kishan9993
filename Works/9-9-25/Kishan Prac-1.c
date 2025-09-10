#include<stdio.h>
#include<conio.h>
void main()
{
    int pri,year;
    float roi;
printf("Enter Princi");
    scanf("%d",&pri);
   printf("Enter ROI");
    scanf("%f",&roi);
   printf("Enter Year");
    scanf("%d",&year);
    
    float intrest = pri*roi*year/100;
    printf("intrest is %f",intrest);
    
    float total = intrest+pri;
     printf("\n total amount is %f",total);
    getch();
}
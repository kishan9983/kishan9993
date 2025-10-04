#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>//exit
int main()
{
    int choice,m=0,l=0,d=0;
   
    while(true)
    {
         printf("\n Enter 1 For Mobile \n Enter 2 For Laptop \n Enter 3 for Desktop");
         scanf("%d",&choice);
         
          switch(choice)
        {
            case 1: m++;
            printf("Total : %d",m);
            break;
            
            case 2: l++;
            printf("Total : %d",l);
            break;
            
            case 3: d++;
            printf("Total : %d",d);
            break;
            
            case 4:exit(0);
            break;
            
            default:printf("Invalid choice");
            break;
        
        }
         
    }
    return 0;
}
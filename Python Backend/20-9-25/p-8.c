#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,space=0;
    
    for(i=1;i<=5;i++)
    {
        for(space=0;space<=5-i;space++)
        {
            printf(" ");
        }
        
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}

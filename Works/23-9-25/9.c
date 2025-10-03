#include<stdio.h>
#include<conio.h>
int main()
{
    int size;
    printf("Enter Total Subjects");
    scanf("%d",&size);
    
    
    int marks[size],total=0;
    float per;
    
    for(int i=0;i<size;i++)
    {
        printf("Enter Marks for Subject %d:",i+1);
        scanf("%d",&marks[i]);
    }
     for(int i=0;i<size;i++)
    {
        total+=marks[i];
    }
    
    per = total/7;
    
    printf("\n Total is %d",total);
    printf("\n Percentage is %f",per);
   
    if(per>=35)
    {
        printf("\n Pass");
    }
    else
    {
        printf("\n Fail");
    }
   
    return 0;
}






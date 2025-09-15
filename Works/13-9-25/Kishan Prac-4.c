#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    
    char fruit[50] = "mango";
    char ans[50];
    
    do
    {
        printf("Guess the fruit name?");
        scanf("%s",&ans);
    }
    while(strcmp(fruit,ans)!=0);
    
    printf("You are correct");
    
    
    
    
 

    return 0;
}
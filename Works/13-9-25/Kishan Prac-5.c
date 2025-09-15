#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char name[50];
    char name2[50];
    
    printf("Enter 1st name");
    scanf("%s",&name);
    
    printf("Enter 2nd name");
    scanf("%s",&name2);
    
    printf("%d",strcmp(name,name2));

    return 0;
}
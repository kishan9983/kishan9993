#include<stdio.h>
#include<conio.h>
#include<string.h>


int main()
{
    char ch[50];
    
    printf("Enter String");
    scanf("%s",&ch);
    
    printf("%s",strlwr(ch));
    //printf("%s",strupr(ch));

    return 0;
}
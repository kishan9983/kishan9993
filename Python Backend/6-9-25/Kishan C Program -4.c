#include<stdio.h>
#include<conio.h>
void main()
{
    int a = 6;
    int b = 3;
    
    a+=b;//a=a+b//6+3=9
    printf("\n %d",a);
    a-=b;//a=a-b//9-3=6
    printf("\n %d",a);
    a*=b;//a=a*b
    printf("\n %d",a);
    a/=b;//a=a/b
    printf("\n %d",a);
    a%=b;
    printf("\n %d",a);
    getch();
}
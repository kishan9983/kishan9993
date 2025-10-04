#include<stdio.h>
#include<conio.h>
void main()
{
    float pi = 3.14;
    int r;
    printf("Enter Radius");
    scanf("%d",&r);
    float ans = pi*r*r;
    printf("%f",ans);
    getch();
}
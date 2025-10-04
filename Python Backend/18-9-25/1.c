#include<stdio.h>
#include<conio.h>


int main()
{
   int a = 4;
   int b = 2;
   
   printf("\n Before swaping value of a is %d",a);
   printf("\n Before swaping value of b is %d",b); 
    
    a=a+b;
    b=a-b;
    a=a-b;
    
   printf("\n After swaping value of a is %d",a);
   printf("\n After swaping value of b is %d",b);  
    

    return 0;
}
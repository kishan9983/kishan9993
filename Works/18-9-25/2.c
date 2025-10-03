//without using third variable
#include<stdio.h>
#include<conio.h>

int swap(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
    
   printf("\n After swaping value of a is %d",a);
   printf("\n After swaping value of b is %d",b);  
}

int main()
{
   int a = 4;
   int b = 2;
   
   printf("\n Before swaping value of a is %d",a);
   printf("\n Before swaping value of b is %d",b); 
    
   swap(a,b);
   swap(6,7);    
  
    

    return 0;
}
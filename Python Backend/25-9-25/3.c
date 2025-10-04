#include<stdio.h>

int main()
{
      int n, sum = 0, i = 0;
      
      printf ("Enter a number") ;
      scanf ("%d",&n);//5
      
      tops:
      i++;
      sum+=i;
      
      if(i<n)
      {
          goto tops;
      }
      
      printf("sum of all digits are: %d",sum);

    return 0;
}
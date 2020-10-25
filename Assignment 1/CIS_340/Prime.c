#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n,i;
  int d2, count; //used a comma, not a semicolon (fixed)
  double d1;

  while(1)
  {
    printf("Enter a number (0 to quit): ");
    scanf("%d",&n);
    if (n == 0)
      break;
    count = 0;
    for(i=1; i<n; i++)
    {
      d1 = (double)n/(double)i; //divide by zero (fixed)
      d2=n/i;
      if (fabs(d1-(double)d2) < 0.00001)
        count++;
    }
    if (count == 1) //changed to one to fix never finding prime
      printf("%d is prime\n",n);
    else
      printf("%d is not prime\n",n);
  }

}

/*
the code is missing a semicolon after the count variable declaration.
The program crashes as line 19 because of dividing by zero.
Needed to change the if(count == 2) to if(count == 1) to fix it not finding any primes.
*/

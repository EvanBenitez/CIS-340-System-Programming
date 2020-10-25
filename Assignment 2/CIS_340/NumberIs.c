#include <stdio.h>
#include <string.h>

int main()
{
  char n[10];
  int x;
  int i;
  printf("Enter a three-digit nonegative number: ");
  scanf("%s",n);
  i = strlen(n) - 1;

  x = 0;
  int multiplier = 1;
  while(i>=0)
  {
    x += (n[i]-48) * multiplier;
    i--;
    multiplier *= 10;
  }

  printf("The number is %d\n",x);
}

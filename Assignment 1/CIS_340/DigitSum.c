#include <stdio.h>

int main()
{
  long in;
  int sum = 0;
  printf("Enter a integer number (no more than 10 digits):");
  scanf("%ld", &in);
  while(in != 0)
  {
    sum += in % 10;
    in /= 10;
  }
  printf("Sum is %d", sum);
  return 0;
}

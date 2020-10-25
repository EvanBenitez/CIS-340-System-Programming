#include <stdio.h>

int main()
{
  int target;
  int dist;
  int previous;
  int count = -1;

  printf("Enter a positive integer:");
  scanf("%d", &target);

  dist = target;
  do {
    count++;
    previous = dist;
    dist = target - count * count;
    if(dist < 0)
      dist *= -1;
  } while(dist <= previous);
  count--;
  printf("%d",count * count);
}

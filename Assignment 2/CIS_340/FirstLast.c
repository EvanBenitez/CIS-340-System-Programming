#include <stdio.h>

int main()
{
  char name[50],first[25],last[25];
  printf("What is your name? ");
  scanf("%s",name);

  int i=0;
  do
  {
    first[i] = name[i];
    i++;
  } while(name[i] >= 'a' && name[i] <= 'z');
  first[i]=0;

  int j = 0;
  while(name[i] != 0)
  {
    last[j] = name[i];
    j++;
    i++;
  }
  last[j] = 0;

  printf("First name: %s\n",first);
  printf("Last name: %s\n",last);
}

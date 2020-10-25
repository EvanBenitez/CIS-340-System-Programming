#include <stdio.h>
#include <string.h>

int main()
{
  char words[10][20];
  printf("Please enter 10 words:\n");

  int i;
  for(i = 1; i <= 10; i++)
  {
    printf("word %d:", i);
    scanf("%s",words[i-1]);
  }

  for(i = 1; i < 10; i++)
  {
    int j;
    char temp[20];
    strcpy(temp,words[i]);
    for(j = i-1; j >= 0; j--)
    {
      if(strcmp(words[j],temp) > 0)
      {
        strcpy(words[j+1],words[j]);
      }
      else
      {
        strcpy(words[j+1],temp);
        j = -1;
      }
      if(j == 0)
        strcpy(words[j],temp);
    }
  }

  for(i = 0; i < 10; i++){
    printf("%s\n",words[i]);
  }
}

#include <stdio.h>

//wasn't sure if I should include the name of the program in the arguments.
//since the name of the program is given with the file path, I decided
//not to incude it in the six argmument requirment or the output.
int main(int argc,char *argv[])
{
  if(argc > 2 && argc < 8)
  {
    int i;
    for(i=1;i<=argc-1;i++){
      printf("%c ",argv[i][(i-1)%2]);
    }
  }
  else
  {
    printf("This program requires at least 2, but no more than 6 arguments.");
  }
}

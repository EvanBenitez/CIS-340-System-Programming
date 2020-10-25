#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char dup[argc-1];      //keeps track of duplicate arguments
  int i,j;

  //initialize array
  for(i=0;i<argc-1;i++)
    dup[i] = 0;

  for(i=1; i<argc; i++)              //cycle through all arguments
  {
    char found = 0;                  //flag for a match found
    if(dup[i-1] == 0)              //checks whether duplicate argument has already been accounted for
    {
      for(j=i+1; j<argc; j++)          //cycle through all i+1 arguments
      {
          if(strcmp(argv[i],argv[j]) == 0)    //checks if args ar the same
          {
            dup[j-1] = 1;              //Set dup flag
            if(found == 0)              //checks if first occurence of duplicate found
            {
              printf("'%s' occurenced at indices: %d,%d",argv[i],i-1,j-1);
              found++;                  //set found flag
            }
            else
            {
              printf(",%d",j-1);
            }
          }
      }
    }
    if(found == 1)
      printf("\n");
  }
}

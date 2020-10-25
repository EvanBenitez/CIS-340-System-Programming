#include <stdio.h>

static char last = 'W';    //W fore World(); H for Hello(); Default W

//Prints Hello if World was the last thing printed
//Returns 1 if printed, 0 if not printed
int Hello(){
  if(last == 'W'){
    printf("Hello ");
    last = 'H';
    return 1;
  }
  return 0;
}

//Prints World if Hello was the last thing printed
//Returns 1 if printed, 0 if not printed
int World(){
  if(last == 'H'){
    printf("World ");
    last = 'W';
    return 1;
  }
  return 0;
}

#include <stdio.h>
#include "world.h"

int main(){
  if(!World()){
    printf("Must call Hello() first\n");
  }

  printf("\n");

  if(!Hello()){
    printf("Must proceed a call to World()\n");
  }

  printf("\n");

  if(!Hello()){
    printf("Must proceed a call to World()\n");
  }

  printf("\n");

  if(!World()){
    printf("Must proceed a call to Hello()\n");
  }

}

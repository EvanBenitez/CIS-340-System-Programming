#include <stdio.h>

int main(){
  char input[50];
  char *ptr;
  ptr = &input[0];

  int vowels = 0;
  int consonants = 0;

  printf("Input String: ");
  scanf("%s",input);

  do {
   if(((*ptr) >= 'a' && (*ptr) <= 'z') || ((*ptr) >= 'A' && (*ptr) <= 'Z')){
      if((*ptr) == 'a' || (*ptr) == 'e' || (*ptr) == 'i' || (*ptr) == 'o' || (*ptr) == 'u' || (*ptr) == 'A' || (*ptr) == 'E' || (*ptr) == 'I' || (*ptr) == 'O' || (*ptr) == 'U'){
         vowels++;
       }
      else{
        consonants++;
      }
    }
  } while(*(++ptr) != 0);

  printf("Number of vowels: %d\n",vowels);
  printf("Number of consonants: %d\n",consonants);
}

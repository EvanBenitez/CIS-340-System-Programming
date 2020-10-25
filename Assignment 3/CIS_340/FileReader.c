#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void sizer(char [], char [], int);

int main(int argc,char *argv[]){
  if(argc != 2){
    printf("please specify text file.");
    exit(1);
  }

  int file;

  if((file = open(argv[1], O_RDONLY)) == -1){
    perror("Cannot open file");
    exit(1);
  }

  char input[20];
  printf("Enter a compare entry: ");
  scanf("%s",input);

  char word[20];
  int i = 0;
  int end = 1;
  while(end == 1){
    end = read(file,&word[i],1);
    if(end == 0)
      word[i] = 0; //set word[i] to a value that will trigger the else clause
    if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
      i++;
    }
    else{
      word[i] = 0;
      if(strlen(input)<= i){
        char compare[strlen(input)+1];     //a string for comparison without disturbing the original
        sizer(word,compare,strlen(input));
        if(strcasecmp(input,compare) == 0)
          printf("%s\n",word);
      }
      i = 0;
    }
  }
  printf("Done.");
}

//trim in string to the lenght of len and puts it in out.
void sizer(char in[], char out[], int len){
  int i;
  for(i=0; i<len; i++){
    out[i] = in[i];
  }
  out[i] = 0;
}

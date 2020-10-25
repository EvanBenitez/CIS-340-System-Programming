#include <stdio.h>

int main(){
  int count;

  printf("How many numbers do you want to sort? ");
  scanf("%d",&count);

  int array[count];
  int i;
  for(i = 0; i<count; i++){
    printf("Enter integer %d: ", i+1);
    scanf("%d",&array[i]);
  }

  int *a, *b;

  //sort using bubble sort algorithm
  for(i=0;i<count-1;i++){
    a = &array[0];
    b = &array[1];
    int j;
    for(j=0;j<count-i-1;j++){
      if(*a > *b){
        int temp = *a;
        *a = *b;
        *b = temp;
      }
      a++;
      b++;
    }

  }

  for(i=0;i<count;i++){
    printf("%d\n",array[i]);
  }

}

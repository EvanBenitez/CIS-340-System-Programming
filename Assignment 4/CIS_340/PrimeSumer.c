/*The following code displays the sum of all the prime numbers entered into it.
it will ask for a number and if it is prime, it will add it to the total. After
every iteration, it will display the current sum of primes.
*/
#include <stdio.h>

//returns 1 if num is prime, and 0 if not prime
int is_prime(int num){
  int factors = 0;  //counts number of factors
  int i;  //counter variable
  for(i=1; i<=num; i++){
    if(num%i == 0){ //check if num is divisable by i
      factors++;  //add to factor count
    }
  }
  if(factors == 2 || num == 1){ //check if prime
    return 1; //if prime
  }
  else{
    return 0; //if not prime
  }
}

int main(){
  int prime_sum, input;

  prime_sum = 0;  //initial sum is 0.
  do{
    printf("%d\n",prime_sum); //display prime_sum

    printf("Enter an integer (Enter 0 to exit): ");
    scanf("%d",&input); //retrieve user input

    if(input != 0){ //don't execute if user input is 0
      if(is_prime(input)){
        prime_sum += input; //add input to prime_sum if it is prime
      }
    }
  }while(input != 0); //continue until input == 0
}

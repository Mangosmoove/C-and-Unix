/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/12/2021
 */


/* OBSERVATIONS FOR N > 10:
 * It appears that the value at n alternates with each increase to n. For example, n = 11 returns 1 which means the value at n = 11 is prime, but at n = 12 it returns
 * 0 and then for n = 13 it returns 1 and for n = 14 it returns 0. So if n is prime, then n+1 and n-1 is not prime.
 *
 */
#include<stdio.h>

int is_fib_prime(int);
int is_prime(int);

void main(void){
  int n = 14;
  printf("Number at n = %d is prime: %d\n", n, is_fib_prime(n));
}

int is_fib_prime(int n){
  if(n >= 3 && n <=10){
    if(is_prime(n) == 0)
      return 1; //not prime
    else
      return 0; //is prime
  }
  //create variables to act as indices
  int firstInd; 
  int secInd = 1;
  int sumOfTwo;

  //create a variable to hold actual value
  int fibNum;
  
  //create a variable for looping
  int i;
  
  for(i = 0; i < n; i++){
    fibNum = firstInd;
    sumOfTwo = firstInd + secInd;
    firstInd = secInd;
    secInd = sumOfTwo;
  }
  //printf("Number: %d\n", fibNum); //testing
  
  if (is_prime(fibNum) == 0)
    return 1; //not prime
  else 
    return 0; //is prime 
}

int is_prime(int n){
  int i;
  int count = 0; //to prevent a floating point error, assigned count to 0
  for (i = 1; i <= n; i++){
    if (n % i == 0)
      count++;
  }
  // printf("Count: %d\n", count); testing
  if (count > 2) //if the count is greater than 2, that means there are more than 2 factors other than 1 and n --> n != prime
    return 0;
  else
    return 1;
}

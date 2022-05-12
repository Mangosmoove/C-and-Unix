/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/6/2021
 */

// The factorial of an integer is the product of the number with all
// the positive integers below it.

// For example: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

// Number of errors/bugs = 7

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>

int factorial(int);

int main(void) {
  int n, fact; 
  printf("Debugging Practice 1 - Quiz 3, Q3\n\n");
  printf("Please enter the number whose factorial you wish to find: ");
  scanf(" %d", &n); //included the &, %f -> %d
  while (n < 0){ //made a case to avoid taking -numbers
    printf("Please enter a positive number: ");
    scanf(" %d", &n);
  }
  fact = factorial(n);
  printf("The factorial of %d is %d\n", n, fact); //%c --> %d
}

int factorial(int number) { //float --> int for parameter
  if(number <= 1)
    return 1; //returned 1 rather than number-1
  return number * factorial(number-1);//+ --> -
}

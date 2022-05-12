/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/8/2021
 */


// Program to check if the given number is a palindrome
// Number of errors/bugs = 15

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>
#include<stdbool.h> //included bool package
bool func(int x); //changed return type to bool, changed parameter type to int

void main() {
  int num = 1001; //changed char to int        
  bool return_value_function; //created bool variable
  return_value_function = func(num); //fixed typo with function name (func4), gave proper parameter
  
  if (return_value_function){
    printf("It is not a palindrome \n");
  }
  else{
    printf("It is a palindrome \n");
  }
  return; //added semi-colon, removed 0
}

//the return value of your func should be true / false only
bool func(int n){ //changed return type to bool, removed char argument
  int given_number = n; //assigned n to given_number
  int remainder;
  int temp; //declared temp variable
  while (n != 0) { //changed == to !=
    remainder = n % 10; //changed / to modulus
    n /= 10; //changed -= to /=
    temp = (temp*10) + remainder; //changed to * from +10                   
  }
  if(given_number == temp){
    return false;
  }
  else{
    return true;
  }
}

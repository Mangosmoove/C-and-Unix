/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/8/2021
 */
// Program to count the input characters. 
// It reads the input from the keyboard until user hits ENTER
// and then prints it on screen.  
// Number of errors/bugs = 13
//
// TODO: Fix the bugs and make sure the program runs as expected.
// Provide a brief comment identifying each bug fixed.
//
#include<stdio.h>
int main(void) { //main isn't reading an int from cmd line, void main(int) --> int main(void) 
  int i; //declare int i
  int count; //char --> int
  char c; //declared a char variable

  for (i=0; c = getchar() != '\n'; i++){ //post increment instead of preincrement, changed terminating character to newline character
    putchar(c);//j --> c
    count++; //incrementing instead of decrementing, moved line to end of loop 
  }

  printf("\nnum of chars including spaces: %d\n", count);// /m --> /n, %s --> %d, : --> ,
  return 1;
}

/* 
 * Arinah Karim
 * CSCI-C 291 / Spring 2021
 * Assignment 1 
 * 1/25/2021, 3:13 pm
 * 
*/

#include <stdio.h>

int main(void) {
 // printf("(Karim, Arinah) 0019\n");
  /*
  int myNumber = 0;
  printf("Hello: Welcome to C291!\n");
  printf("Please enter a number and press ENTER: ");
  scanf("%d", &myNumber);  
  printf("Here is the number yor entered: %d\n",myNumber);
  return(0); 
  */
  printf("\"*****{Welcome to C291 Spring 2021 @ IU}, %%%%%% Golden Rule: Start working on everything as early as possible %%%%%% Thanks *****\"\n");
  int count = 100;
  int i;
  int period = 1;
  while (1){
    if (period){
      printf("%04d", count);
      for (i = 0; i < 5; i++){
        sleep(1);
        printf(".");
        fflush(stdout);
      }
      printf("\n");
      period = 0;
    }
    else { 
      printf("%04d\n", count);
      period = 1;
    }
    count--;
  } 
}

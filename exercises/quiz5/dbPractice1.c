/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/22/2021
 */
// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.
// Number of errors/bugs = 12


#include <stdio.h>
void display(int Matrix[][2][2],int size); //added necessary [], changed 3 to 2
int main(void) {
  int size=3;
  int Matrix[size-1][size-1][size-1]; //added depth []
  printf("Enter 8 elements of the matrix:\n");
  int i; //added semicolon
  int j;
  int k; //added variable k for depth
  //int elements = 9;
  //int m = 0;
  for (i = 0; i < size - 1; i++){ //fixed indentation, changed to size -1 instead of size, changed commas to semi-colons
    for (j = 0; j < size - 1; j++){ //added j to first statement of for loop, changed size to size - 1
      for (k = 0; k < size - 1; k++){
        scanf("%d", &Matrix[i][j][k]); //changed colon to semi-colon, changed %f to %d
      }
    }   
  }
  display(Matrix,3); //got rid of ampersand
  return 0;
}


void display(int Matrix[][2][2], int size) { //changed type float to int, changed char to int, added necesary [], changed 3 to 2
  int i; //declared i
  int j; //declared j
  int k; //made a new variable k for depth iteration

  printf("\n");
  for (i = 0; i < size-1; ++i){ //changed post increment to pre increment
    for (j = 0; j < size-1; ++j){ //changed post incement to pre increment
      for (k = 0; k < size-1; ++k){ //added for loop, changed post increment to pre increment
        printf("%d,", Matrix[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }  
}

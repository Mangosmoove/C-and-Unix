/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/15/2021
 */

//This program allocated memory for an NxM integer array dynamicaly 
//The program then prints the 2D array in a matrix form using a combination of * and [] operators
//Note: You can't use ** or [][] for printing the values (use a combination of * and [] only.

#include <stdio.h>
#include <stdlib.h>
int main() {
  int N = 3, M = 5;
  int i, j;
  int**d_array = (int**) malloc( N * sizeof(int*) );       //Allocating memory for 2D array (N rows)
  for(i=0; i< N; i++)
    d_array[i] = (int*) malloc(M * sizeof(int) );  //Allocating memory for each row with M columns)
    //Initializing 2D array using [ ][ ] notation
  printf("Initializing array values!\n");
  for(i=0; i< N; i++) {
    for(j=0; j < M; j++) {
      *(*(d_array+i)+j) = i+j;
      //printf("%d ", *(*(d_array+i)+j));
    }
    //puts("\n");
  }
    
  //Accessing 2D array using a combination of * and [] notation
  printf("\n");
  for(i=0; i< N; i++) {
    for(j=0; j < M; j++) {
      printf("%d ",*(d_array[i]+j));
    }
    printf("\n");
  }
  
  //Deallocating 2D array
  for(i=0; i< N; i++)
    free(*(d_array+i));
  free(d_array);
}

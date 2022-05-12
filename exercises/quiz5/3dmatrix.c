/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/22/2021
 */

// Program to read 3-dimensional matrix and display the elements as 1x9 matrix
// Review the slide titled "Mmeory Organization of Arrays in Ch6" for more details
// TODO
// User may specify any number of rows, columns and depth. Use those to create matrix
// initize matrix using update_ed method
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
// 

#include <stdio.h>
int size;

void update_3d(double matrix_3d[][size][size], int); 
void display_1d(const double Matrix_3d[][size][size], int); 

int main(void) {
  //prompt the use to enter appropriate dimensions and initializ the matrix accordingly
  printf("Enter a number for the size of the row, column, and depth:\n");
  scanf(" %d", &size);
  int s = size;

  double Matrix_3d[s][s][s];
  //initialize the array to non-zero values (use scanf or random numbers generator)
  update_3d(&Matrix_3d, size);
  //display the values
  int i, j, k;

  for ( i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      for (k = 0; k < size; ++k) {
        printf("%f", Matrix_3d[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }
  display_1d(Matrix_3d, size);
  return 0;
}

void update_3d(double matrix[][size][size], int size) {
  int numElements = size * size * size;
  printf("Enter %d elements of the matrix:\n", numElements);
  int i;
  int j;
  int k;
  for (i = 0; i < size; i++){
    for (j = 0; j < size; j++){
      for (k = 0; k < size; k++){
        scanf("%f", &matrix[i][j][k]); 
      }
    }
  }
  printf("\nupdate completed\n");
}


//update as needed. 1 for loop only with 1 iterator to print all values with addresses
//must not be able to update the array.
//Share any observations.
void display_1d(const double matrix[][size][size], int size) {
  int i;
  int j = 0;
  int k = 0;
  for (i=0; i < size; i++) {
    if (j < size){
     if (k < size){
       printf("%p (%0.2f) ", &matrix, matrix[i][j][k]);
       j++;
       k++;
     }
    }
    j++;
    k++;
    printf("\n");
  }
  //go through levels of depth
  //print out elements in each row n column but as 1x9
}

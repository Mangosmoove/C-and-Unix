/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/7/2021
 */
#define SIZE 5
#include<stdbool.h>
#include<stdio.h>
bool myswap(int* xPtr, int* yPtr); 
int main(void){
  puts("Question 1");
  puts("(A)A point variable contains as its value the MEMORY ADDRESS of another variable.");
  puts("(B)The three values that can be used to initalize a pointer are 0, NULL, and A MEMORY ADDRESS.");
  puts("(C)The only integer that can be assigned to a pointer is 0");

  puts("\nQuestion 2");
  puts("(A)The address operator (&) can be applied only to constants, to expressions, and to variables declared with the storage-class register");
  puts("\tFalse: & cannot be used on variables declared with the storage-class register");
  puts("(B)A pointer that's declared to be void can be dereferenced");
  puts("\tFalse: void pointer does not have a type");
  puts("(C)Pointers of different types may not be assigned to one another without a cast operation"); 
  puts("\tFalse: All pointer types can be assigned to a pointer to void and a pointer to void can be assigned to a pointer of any type.");
  
  puts("\nQuestion 3");
  puts("(A)Defining array numbers of type short...");
  short int numbers[SIZE] = {1, 2, 3, 4, 5};
  
  puts("(B)Defining pointer nPtr of type short...");
  short int* nPtr;
  
  puts("(C)Printing out elements of numbers array...");
  int i;
  for (i = 0; i < SIZE; i++){
    printf("%.1d ", numbers[i]);
  }

  puts("\n(D)Variations of assigning last element's address to pointer variable...\n");
  nPtr = &numbers[SIZE-1];
  printf("1st way of assignment using pointer(&numbers[SIZE-1]): \n\t%p\n", nPtr);
  nPtr = &numbers[0];
  nPtr += SIZE-1;
  printf("2nd way of assignment (adding SIZE-1): \n\t%p\n", nPtr);

  nPtr = &numbers;
  puts("\n(E)Printing elements of array using nPtr..."); 
  for(i = 0; i < SIZE; i++){
    printf("%d ", *(nPtr + i));
  }  
  
  puts("\n(F)Printing elements of array using array name as pointer...");
  for(i = 0; i < SIZE; i++){
    printf("%d ", *(numbers + i));
  }
 
  puts("\n(G)Printing elements of array by subscripting nPtr...");
  for(i = 0; i < SIZE; i++){
    printf("%d ", nPtr[i]);
  }  

  puts("\n(H)Referring to 2nd element of array using array name for subscript and offset notations, followed by pointer subscript and offset notation...");
  printf("Using array name:\n\tsubscript notation: %d\n\toffset notation: %d\nUsing pointer:\n\tsubscript notation: %d\n\toffset notation: %d", numbers[1], *(numbers + 1), nPtr[1], *(nPtr+1));
  
  puts("\n(I)Address referenced by nPtr - 5 and value....");
  nPtr = &numbers[SIZE-1]; 
  //printf("Address: %p\n", &numbers[0]); for comparison
  printf("Address referenced by nPtr - 5: %p\n", (nPtr-5));
  printf("Address of first element in the array: %p\n", &numbers[0]);
  puts("The address being printed is 2 bytes before the first element in the array.");
  printf("Value at nPtr-5: %d", *(nPtr-5));

  puts("\n(J)Address referenced and value at nPtr-=2 when nPtr stores the address of numbers[5]...");
  nPtr = &numbers[5];
  nPtr -= 2;
  printf("Address referenced by nPtr -=2: %p\n", nPtr);
  puts("The address is 2 bytes more than the last element in the array");
  printf("Value at nPtr -=2: %d\n", *nPtr);

  puts("\nQuestion 4");
  puts("(A)Defining fPtr pointer variable...");
  float number1;
  float number2 = 5.3;
  float* fPtr;

  puts("(B)Defining fPtr2 pointer variable...");
  float* fPtr2;

  puts("(C)Assigning address of number2 to fPtr...");
  fPtr = &number2;

  puts("(D)Printing value of number 2 using pointer...");
  printf("%.2f\n", *fPtr);

  puts("(E)Assigning value of number2 to number1 using fPtr...");
  number1 = *fPtr;

  puts("(F)Assigning address of fPtr to fPtr2...");
  fPtr2 = &fPtr;

  puts("(G)Printing value of variable number1....");
  printf("%.2f\n", number1);

  puts("(H)Printing address of number2...");
  printf("%p\n", &number2);

  puts("(I)Printing address stored in fPtr...");
  printf("%p\n", fPtr);
  printf("The values of part I and H are the same\n");
  
  puts("(J)Printing address stored in fPtr2...");
  printf("%p\n", fPtr2);

  puts("\nQuestion5");
  puts("(A)Creating int variables to pass to function myswap");
  int x = 5;
  int y = 4;
  bool ans = myswap(&x, &y);
  printf("%d equal %d?: %d\n", x, y, ans);
  puts("(B)Created function prototype...");
  return 0;
}

bool myswap(int* xPtr, int* yPtr){
  if(*xPtr == *yPtr)
    return true;
  return false;
}

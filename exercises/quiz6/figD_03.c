// Fig. E.3: figE_03.c
// The merge sort algorithm using recursion.
// TODO: sortSubArray function uses recursion. Write a new function called sortSubArrayIter which doesn't use recursion
// To implement the new sort function without recursion, where the length of the array is an arbitrary number, 
// Keep merging adjacent regions whose size is a power of 2, and pay special attention to the last area whose size is less.
// Test to make sure that your results are correct.
 
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes 
void mergeSort(int array[], size_t length);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, size_t right);
void displayElements(int array[], size_t length);
void displaySubArray(int array[], size_t left, size_t right);
void sortSubArrayIter(int array[], int n, int start, int end);
int main(void)
{
   int array[SIZE]; // declare the array of ints to be sorted 
   size_t i;
   srand(time(NULL)); // seed the rand function 
    
   for (i = 0; i < SIZE; i++) {
      array[i] = rand() % 90 + 10; // give each element a value 
   }
        
   puts("Unsorted array:");
   displayElements(array, SIZE); // print the array 
   puts("\n");
   mergeSort(array, SIZE); // merge sort the array 
   puts("Sorted array:");
   displayElements(array, SIZE); // print the array 
} 

// function that merge sorts the array 
void mergeSort(int array[], size_t length)
{
   sortIterArray(array, length, 0, length - 1);
} 
/*
// function that sorts a piece of the array 
void sortSubArray(int array[], size_t low, size_t high)
{
   // test base case: size of array is 1 
   if ((high - low) >= 1) { // if not base case... 
      size_t middle1 = (low + high) / 2;
      size_t middle2 = middle1 + 1;
        
      // output split step 
      printf("%s", "split:   ");
      displaySubArray(array, low, high);
      printf("%s", "\n         ");
      displaySubArray(array, low, middle1);
      printf("%s", "\n         ");
      displaySubArray(array, middle2, high);
      puts("\n");
        
      // split array in half and sort each half recursively 
      sortSubArray(array, low, middle1); // first half 
      sortSubArray(array, middle2, high); // second half 
        
      // merge the two sorted arrays 
      merge(array, low, middle1, middle2, high);
   } 
}*/

void sortIterArray(int array[], int n, int start, int end){
  int i = 2; //groups in power of 2
  int j; //index within group

  while (i < n){
    j = 0; //reinitialize j so index matches up correctly
    while (j < n-1){
      int right = j + i - 1; //second num
      int left = j; //first num
      
      if (right > n){ //making sure right does not go past size of array
        right = n-1;
      }
      int middle = (left + right)/2;
      merge(array, left, middle, right); //correctly sort the nums in the group
      j++; 
    }
    i *= 2; //next group
    if (i >= n){ //check if all of the groups have been made and merge
      i/=2;
      merge(array, 0, n-1, i-1);
      i = n;
    }
  }
}
// merge two sorted subarrays into one sorted subarray 
void merge(int array[], size_t left, size_t middle1, size_t right){ //altered function to make it more understandable to myself
   size_t leftIndex = middle1 - left + 1; // index into left subarray 
   size_t rightIndex = middle1; // index into right subarray 
  // size_t combinedIndex = left; // index into temporary array 
  // int tempArray[SIZE]; // temporary array 
   int n1 = 0; //index of left array
   int n2 = 0; //inex of right array
   int n3 = left; //index of combined, sorted array
   int arr1[leftIndex]; //setting sizes based off of parameters
   int arr2[rightIndex];
   int i, j;

   //assigning values for both sub arrays
   for (i = 0; i < leftIndex; i++){
     arr1[i] = array[left + i];
   }   
   for (i = 0; i < rightIndex; i++){
     arr2[i] = array[middle1 + 1 + i];
   }
   //assign values from the arrays in the sorted array
   while (n1 < leftIndex && n2 < rightIndex){
     if (arr1[n1] < arr2[n2]){
       array[n3] = arr1[n1];
       n1++;
       n3++;
     }
     else{
       array[n3] = arr2[n2];
       n2++;
       n3++;
     }
    //if there is anything left over in the left array, then store into the sorted array
    while (n1 < leftIndex){
      array[n3] = arr1[n1];
      n1++;
      n3++;
    }
    //if there's anything left over in the right array, store it into the sorted array
    while (n2 < rightIndex){
      array[n3] = arr2[n2];
      n2++;
      n3++;
    }
   }
/*
   // output two subarrays before merging 
   printf("%s", "merge:   ");
   displaySubArray(array, left, middle1);
   printf("%s", "\n         ");
   displaySubArray(array, middle2, right);
   puts("");
    
   // merge the subarrays until the end of one is reached 
   while (leftIndex <= middle1 && rightIndex <= right) {
      // place the smaller of the two current elements in result 
      // and move to the next space in the subarray 
      if (array[leftIndex] <= array[rightIndex]) {
         tempArray[combinedIndex++] = array[leftIndex++];
      } 
      else {
         tempArray[combinedIndex++] = array[rightIndex++];
      } 
   }
    
   if (leftIndex == middle2) { // if at end of left subarray ... 
      while (rightIndex <= right) { // copy the right subarray 
         tempArray[combinedIndex++] = array[rightIndex++];
      } 
   } 
   else { // if at end of right subarray... 
      while (leftIndex <= middle1) { // copy the left subarray 
         tempArray[combinedIndex++] = array[leftIndex++];
      } 
   } 
    
   // copy values back into original array 
   size_t i;
   for (i = left; i <= right; i++) {
      array[i] = tempArray[i];
   } 
   
   // output merged subarray 
   printf("%s", "         ");
   displaySubArray(array, left, right);
   puts("\n");*/
} 

// display elements in array 
void displayElements(int array[], size_t length)
{
   displaySubArray(array, 0, length - 1);
} 

// display certain elements in array 
void displaySubArray(int array[], size_t left, size_t right)
{
  size_t i;
  /* // output spaces for alignment 
   for (i = 0; i < left; i++) {
      printf("%s", "   ");
   } */ 
    
   // output elements left in array 
   for (i = left; i <= right; i++) {
      printf(" %d", array[i]);
   }
   puts("\n"); 
} 


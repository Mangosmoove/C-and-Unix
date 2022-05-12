/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/1/2021
 */

// Quiz6.c 
// median of a sequence
/*
TODO:
The median m of a sequence of n elements is the element that would fall in the middle if the sequence was sorted. 
That is, e <= m for half the elements, and m <= e for the others. Clearly, one can obtain the median by sorting 
the sequence, but one can do quite a bit better with the following algorithm that finds the kth element of a
sequence between a (inclusive) and b (exclusive). (For the median, use k = n / 2, a = 0, and b = n.)
	select(k, a, b):
	Pick a pivot p in the subsequence between a and b.
	Partition the subsequence elements into three subsequences: the elements <p, =p, >p
	Let n1, n2, n3 be the sizes of each of these subsequences.
	if k < n1
		return select(k, 0, n1).
	else if (k > n1 + n2)
		return select(k, n1 + n2, n).
	else
		return p.

Implement this algorithm and measure how much faster it is for computing the median of a random large sequence, 
when compared to sorting the sequence and taking the middle element. Present your observations.

One way to "measure" the time or compare the performance would be to use any of the techniques mentione at 
https://fresh2refresh.com/c-programming/c-time-related-functions/
You may use any approach that you are comfortable with.

*/
 
#include <stdio.h>
#include <stdlib.h> //for rand
#include <time.h> //for seeding

int quickSort(int[], int, int, int); //function prototype
void swap(int[], int, int);
void sort(int[], int); //function prototype
int main(void){
  int n = 10;
  int arr[n];
  int arr2[n];
  time_t t;
  
  int i;
  srand((unsigned)time(&t));

  for (i = 0; i < n; i++){ //generate numbers from 0-100
    arr[i] = rand() % 101;
    printf("%d\n", arr[i]);
  }
  
  for (i = 0; i < n; i++){
    arr2[i] = arr[i];
  } 
  time_t start;
  time_t end;
  int k = n/2;
  //start timer
  start = time(NULL);
  int median = quickSort(arr, k, 0, n);
  end = time(NULL);
  time_t diff = difftime(end, start);
  printf("Quicksort took: %f seconds\n", diff);
  printf("Median: %d\n", median); 
  //start timer
  start = time(NULL);
  sort(arr2, n);
  end = time(NULL);
  diff = difftime(end, start);
  //end timer
  printf("Basic sort took: %f seconds\n", diff);
  printf("Median: %d\n", arr2[k]);
	
  return 0;
}

int quickSort(int arr[], int k, int a, int b){
/*
 * Pick a pivot p in the subsequence between a and b.
 * Partition the subsequence elements into three subsequences: the elements <p, =p, >p
 * Let n1, n2, n3 be the sizes of each of these subsequences.
 * if k < n1
 *  return select(k, 0, n1).
 * else if (k > n1 + n2)
 *  return select(k, n1 + n2, n).
 * else
 *  return p.
 */
  if (a >= b){
    return;
  } 
  //else{
    int pivot = arr[k];
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int i = a-1;
    int j = b-1;

    while (i < j){
      n1++;
      i++;
      while(arr[i] < pivot){
        n1++;
        i++;
      }
      while(arr[i] == pivot || arr[j] == pivot){
        n2++;
        i++;
        j--;
      }
      while(arr[j] > pivot){
        n3++;
        j--;
      }
    } 
   // printf("there\n");
    if(k < n1){
      return quickSort(arr, k, 0, n1);
    }
    else if (k > n1 + n2){
      return quickSort(arr, k, n1+n2, b);
    }
    else{
      return pivot;
    }
 // }
}
//using selection sort as the basic sort to be compared to
void sort(int arr[], int n){
  int min, i, j; //indices

  for (i = 0; i < n-1; i++){
    int min = i; //min index is assigned to i

    for (j = i+1; j < n; j++){ //run ahead of position i and find potential m
      if (arr[j] < arr[min]){
        min = j;
      }
    }
    swap(arr, i, min); //swap
  } 
}

//helper function for sorts
void swap(int arr[], int swapInd, int swapInd2){
  int temp; //temporary placeholder
  temp = arr[swapInd];
  arr[swapInd] = arr[swapInd2];
  arr[swapInd2] = temp;
}

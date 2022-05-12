/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/18/2021
 */

// >=2 people have same birthday
// array of size n (number of people) filled with nums 1 - 365 (using rand num generator)
// do this t amount of times where t is the number of trials
// need some count variable to keep track of true trial
// probably need to use a sorting algorithm to make things easier
// need another function for seeing if there is a num that occurs >=2x, can return true or false maybe or 0 or 1
// when n = 93, yields break even point from 93 on
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
bool two_time(int[], int); //function prototype

int main(){
  int countTrue = 0; //counts how many "true trials" there are
  int n = 93; //size of the array, i.e. the amount of people
  int trial = 100000; //number of trials wanted to be conducted
  int i, j, k, m; //for for loop
  int arr[n]; //array for storing the days people were born
  bool result; //store the return value of the function
  time_t t;  

  srand((unsigned)time(&t));

  //now run trials:
  for(i = 0; i < trial; i++){
    //for generating random numbers:
    //to give a random value btwn 1 - 365 for day born
    for(j = 0; j < n; j++){
      arr[j] = rand() % 365 + 1;
    }
    //sort the array using my favorite sorting algorithm: bubblesort
    for(k = 0; k < n; k++){
      for(m = 0; m < n - k - 1; m++){
        if(arr[m] > arr[m+1]){
          int swap = arr[m];
          arr[m] = arr[m+1];
          arr[m+1] = swap;
        }
      }
    }
    result = two_time(arr, n); //pass to function to determine if there is a streak
    if(result){ //if there is an occurence >= 2x then increment true trial count
      countTrue = countTrue + 1; 
    }
  }
  
  //**need to come back and account for variable type
  float simProb = countTrue/trial; //for print statement
  if(simProb > 0.5){ 
    printf("Simulated probability of n = %d yields the break-even point\n", n);
  }
  else{
    printf("Simulated probability of n = %d does not yield the break-even point\n", n);
  }
}

bool two_time(int arr[], int n){
  int streak = 1; //to see if a number occurs >= 2x
  int i; //for for loop
  
  for(i = 0; i < n; i++){
    if (i+1 != n){
      if(arr[i] == arr[i+1]){
        return true;
      }
    }
  }
  
  return false;
}

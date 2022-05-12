/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/8/2021
 */


/*
 *first thoughts on approach
 *main
 *  create a char 1d array [7] with different causes
 *  make a 2d int array "responses" that can update values of count per category and rating
 *  prompt user to rate each issue (Q to quit)
 *  display:
 *    7x10 grid w/ average ratings in rightmost column --> function prints
 *    issue and point total for highest and lowest point totals
 *    ranking of issues from highest to lowest --> need a variable to hold ratings for each row
 *    number of people who responded using entries from table
 */

#include<stdio.h>
const int row = 7; //row
const int col = 10; //column
//function prototypes
void update(int responses[][10], int rate, int question); //updating array
void displayTab(int responses[][10]); //displaying
char deterCat(int rowInd); //helper function for determining character to display
int minRate(int sumPerRow[]); //helper function to determine smallest sum rate for category
int maxRate(int sumPerRow[]); //helper function to determine highest sum rate for category
void displayByRate(int sumPerRow[]); //helper function to display contents by highest to lowest
void bubbleSort(int sumPerRow[], int sortingOrder[]); //helper function to displayByRate
const char* causes(char c); //returns back full name of cause

void main(void){
  int responses[7][10] = {0};//create a 2d array to store the responses
  char next; //to determine if another response is to be entered
  int rating; //individual rating given to a category
 
  printf("Would you like to take the survey(y/n): "); //prompt user to respond to survey
  scanf(" %c", &next); //scan in input
  while(next != 'n'){ //while the user does not decline to take the survey
    if (next != 'y'){ //to check whether they entered an incorrect character
      printf("Please indicate interest with y for yes or n for no: ");
      scanf(" %c", &next);
    }
    else{ //start the questionnaire
      puts("\nFor each of the following issues, rate on a scale of 1-10 where 1 is least important and 10 is most important to you.\n");
      //QUESTION 1
      printf("Climate change: ");
      scanf("%d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 0); //update value in 2d array by passing pointer and rating for column index and question number for the row index                           //QUESTION 2
      printf("\nHealth care: ");
      scanf("%d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 1); //update value in 2d array by passing pointer and rating for column index question number for row index
      //QUESTION 3
      printf("\nEducation for all: ");                                                                                                                                        scanf("%d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 2);
      //QUESTION 4
      printf("\nCreating economic opportunities: ");
      scanf(" %d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 3);
      //QUESTION 5
      printf("\nProviding housing for homeless: ");
      scanf(" %d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 4);
      //QUESTION 6
      printf("\nRace and ethnic inequality: ");
      scanf(" %d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 5);
                                                                                                                                                                              //QUESTION 7
      printf("\nGun policy: ");
      scanf(" %d", &rating);
      while (rating < 1 || rating >10){ //in case the user puts in invalid number
        printf("Invalid rating number. Please enter a rating from 1-10: ");
        scanf(" %d", &rating);
      }
      update(responses, rating, 6);
      printf("Thank you for your input!\nStart a new response?(y/n): ");
      scanf(" %c", &next);
    }
  }
  printf("\n");
  displayTab(responses);
}

//updates contents of 2d array
void update(int responses[][10], int rate, int question){
  int colInd = rate - 1; //subtracting 1 for column index
  int rowInd = question; //row index
  *(*(responses+rowInd)+colInd) = *(*(responses+rowInd)+colInd) + 1; //update at correct position by one
}

//for displaying
void displayTab(int responses[][10]){
  int i, j; //for row and column indices
  int sumPerRow[7] = {0}; //keeping track of sums of rating per category
  int totalCount = 0; //keeping track of the number of people who
  int average = 0; //for printing out averages per category
  puts("   1  2  3  4  5  6  7  8  9  10"); //printing out ratings followed by newline
  for(i = 0; i < row; i++){
    totalCount = 0;
    char category = deterCat(i); //for determining what character to display
    printf(" %c ", category);
    for(j = 0; j < col; j++){
      totalCount += *(*(responses+i)+j); //cumulative sum of the number of votes per rating to get total number of votes
      sumPerRow[i] += (*(*(responses+i)+j))*(j+1);
      printf("%d  ", (*(*(responses+i)+j))); //prints count per rating
    }
    average = (*(sumPerRow+i))/totalCount; //get the average rate per category
    printf("%d\n", average); //print average per category
  }
  int minInd = minRate(sumPerRow); //find lowest rate
  char minCause = deterCat(minInd); //find corresponding cause based on index of lowest rating
  
  int maxInd = maxRate(sumPerRow); //find highest rate
  char maxCause = deterCat(maxInd); //find corresponding cause based on index of highest rating
  
  printf("\nIssue with highest point total: %s %d\n", causes(maxCause), *(sumPerRow+maxInd)); //printing highest rating
  printf("Issue with lowest point total: %s %d\n", causes(minCause), *(sumPerRow+minInd)); //printing lowest rating

  displayByRate(sumPerRow);
  printf("\nTotal responses: %d\n", totalCount);
}

//helper function
char deterCat(int rowInd){
  if(rowInd == 0)
    return 'C';
  else if (rowInd == 1)
    return 'H';
  else if (rowInd == 2)
    return 'E';
  else if (rowInd == 3)
    return 'N';
  else if (rowInd == 4)
    return 'P';
  else if (rowInd == 5)
    return 'R';
  else
    return 'G';
}

//returns index of min rating
int minRate(int sumPerRow[]){
  int i;
  int min = *sumPerRow;
  int index = 0;
  for (i = 1; i < row; i++){
    if (min > *(sumPerRow+i)){
      min = *(sumPerRow+i);
      index = i;
    }
  }
  return index;
}

//returns index of max rating
int maxRate(int sumPerRow[]){
  int i;
  int max = *sumPerRow;
  int index = 0;
  for (i = 1; i < row; i++){
    if (max < *(sumPerRow+i)){
      max = *(sumPerRow+i);
      index = i;
    }
  }
  return index;
}

//ordering the causes on highest to lowest rates
void displayByRate(int sumPerRow[]){
  int sortingOrder[7] = {0, 1, 2, 3, 4, 5, 6};
  bubbleSort(sumPerRow, sortingOrder); //sorting array using bubbleSort
  int i;
  char c;

  for (i = 0; i < row; i++){
    c = deterCat(*(sortingOrder+i));
    printf("%d) %s  %d\n", i+1, causes(c), *(sumPerRow+i));
  }
}

//helper function to sort rate sums of all categories in descending order
void bubbleSort(int sumPerRow[], int sortingOrder[]){
  int i, j;
  for (i = 0; i < row-1; i++){
    for(j = 0; j < row-i-1; j++){
      if (*(sumPerRow+j) < *(sumPerRow+j+1)){
        int temp = *(sumPerRow+j);
        *(sumPerRow+j) = *(sumPerRow+j+1);
        *(sumPerRow+j+1) = temp;
        
        int temp2 = *(sortingOrder+j+1);
        *(sortingOrder+j+1) = *(sortingOrder+j);
        *(sortingOrder+j) = temp2;
      }
    }
  }
}

const char* causes(char c){
  if(c == 'C')
    return "Climate Change";
  else if (c == 'H')
    return "Health Care";
  else if (c == 'E')
    return "Education for All";
  else if (c == 'N')
    return "Creating economic opportunities";
  else if (c == 'P')
    return "Providing housing for homeless";
  else if (c == 'R')
    return "Race and ethnic inequality";
  else
    return "Gun policy";
}



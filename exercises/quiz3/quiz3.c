/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/6/2021
 *
 * 
 * Instructions:
 *
 *
 1. Write a program to assign a grade to Student. 
	Get the number of assignmnets from user.
  Get the students score out of how many points for each assignmnet.
	Calculate percentage and return the grade associated with a range of marks.
 2. The overall score range and the associated grades are as follows:
     a. [97-100] = A+
     b. [90-97] = A
     c. [80-90] = B
     d. [70-80] = C
     e. less than 70 is a failing grade and should be given an F
     e. greater than 100 or less than 0 is invalid and your code should print "Invalid"
 3. Use the skeleton code provided below to create a new function "printGrade" to assign a grade based on the score ranges.
 4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read:
        "Your grade is : C"
 5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.
 *
 *
 * */
void printGrade(float score)
{
  //print the students grade based on their score in the class
  if (score >= 97){
    printf("Your grade for the assignment is: A+\n");
  }
  else if (score >= 90){
    printf("Your grade for the assignment is: A\n");
  }
  else if (score >= 80){
    printf("Your grade for the assignment is: B\n");
  }
  else if (score >= 70){
    printf("Your grade for the assignment is: C\n");
  }
  else{
    printf("Your grade for the assignment is: F\n");
  }
}
int main(void){
  char ch;
  float score;
  int total;
  int assignments;
  int i;
  do {
    printf("How many assignments did you have? "); //get the number of assignmnets from the student
    scanf(" %d", &assignments);
    for(i = 1; i <= assignments; i++) {
      printf("Enter your score for assignment %d followed by the max score: ", i); //get the student's score and the max score for each assignment 
      scanf(" %f %d", &score, &total);
      //calculate the student's percentage in the class using the information you've gathered.
      float percent = (score / total) * 100;
      printGrade(percent);
    }
    printf(" \n Do you want to continue? (Y/N) ");
    scanf(" %c",&ch);
  } while(ch == 'y'|| ch == 'Y');
}

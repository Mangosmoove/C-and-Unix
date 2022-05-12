/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/16/2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//question 2 prototype:
char* reverseString(char* str);
//question 3 prototype:
char* countIntDoubles(char* str);

void main(void){
  //QUESTION 1
  puts("1a.Use an appropriate pointer to dynamically allocate memory for one integer value...");
  int num = 10;
  int* iPtr;
  iPtr = (int*)malloc(sizeof(int));
  puts("\tallocated memory for int variable");
  puts("\tfreeing pointer...");
  free(iPtr);

  puts("1b.Use an appropriate pointer to dynamically allocate memory for two double values...");
  double num1 = 2.4;
  double num2 = 15.7;
  double* dPtr;
  dPtr = (double*)malloc(sizeof(double));
  dPtr = (double*)malloc(sizeof(double));
  puts("\tallocated memory for two double variables");
  puts("\tfreeing pointer...");
  free(dPtr);

  puts("1c.Use an appropriate pointer to dynamically allocate memory for 5 integers, initialize them to some values and print them...");
  int nums[5] = {1, 2, 3, 4, 5};
  int* iPtr2;
  iPtr2 = (int*)malloc(sizeof(int)*5);
  int i;
  for(i = 0; i < 5; i++){
    printf("\tValue of num: %d\n", *(nums+i));
  }
  puts("\tfreeing pointer...");
  free(iPtr2); 
  
  puts("1d.Use an appropriate pointer to dynamically allocate memory for 20 characters, initialize them to something and print them...");
  char* cPtr;
  cPtr = (char*)malloc(20*sizeof(char));
  strcpy(cPtr, "Good evening world!");
  printf("\t%s\n", cPtr); 
  free(cPtr);
  
  puts("1e.Use an appropriate (double) pointer to dynamically allocate memory for 25 characters for 2D array...");
  char** cPtr2 = (char**)malloc(5*sizeof(char*));
  for(i = 0; i < 5; i++){
   *(cPtr2+i) = (char*)malloc(5*sizeof(char));
  }
  puts("Initializing values....");
  int j;
  int start = 65;
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
      *(*(cPtr2+i)+j) = (char)start;
      start++;
    }
  }
  printf("Values in array: \n\t");
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
      printf("%c ", *(*(cPtr2+i)+j));
    }
    printf("\n\t");
  }
  puts("Freeing pointer...");
  for(i = 0; i < 5; i++)
    free(*(cPtr2+i));
  free(cPtr2);

  puts("1f. 1e, but with one pointer..");
  char* cPtr3 = (char*)malloc(5*5*sizeof(char));
  start = 65;
  puts("Intiailizing values....");
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
      *(cPtr3+i*5+j) = (char)start;
      start++;
    }
  }
  printf("Values in array: \n\t");
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
      printf("%c ", *(cPtr3+i*5+j));
    }
    printf("\n\t");
  }
  puts("Freeing pointer...");
  free(cPtr3);

  //QUESTION 2
  puts("\nCreating function that converts upper case characters to lowercase and vice versa...");
  char* str;
  str = (char*)malloc(sizeof(char*)*2000);
  str = strcpy(str, "According to all known laws of aviation, there is no way a bee should be able to fly.Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Coming! Hang on a second. Hello? Barry? Adam? Oan you believe this is happening. I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. You got lint on your fuzz. Ow! That's me! Wave to us! We'll be in row 118,000. Bye! Barry, I told you, stop flying in the house! Hey, Adam. Hey, Barry. Is that fuzz gel? A little. Special day, graduation. Never thought I'd make it. Three days grade school, three days high school. Those were a");
  str = strcpy(str,reverseString(str));
  printf("Converted sentence: \n%s", str);
  puts("\nFreeing pointer...");
  free(str);

  //QUESTION 3
  puts("Counting all integers and doubles in a string...");
  char *countStr;
  countStr = (char*)malloc(sizeof(char*)*1000);
  countStr = strcpy(countStr, "I am 19 with a 19.8 at the end. 4 is the best number, but 5.0 is also cool."); 
  printf("\tThe sum of all integers: %d\n\tThe sum of all doubles: %d\n", *(countStr+0), *(countStr+1)); 
  puts("Freeing pointer...\n");
  free(countStr);
}

char *reverseString(char* str){
  int i;
  char* cPtr = (char*)malloc(sizeof(char)*(strlen(str)+1));
  for(i = 0; *(str+i)!= '\0'; i++){
    if(*(str+i)>='A' && *(str+i)<='Z'){ //capital letter found
      *(cPtr+i) = tolower(*(str+i)); 
    }
    else if(*(str+i) >= 'a' && *(str+i) <= 'z'){ //lower case letter found
      *(cPtr+i) = toupper(*(str+i));
    }
    else{ //something that isn't a letter
      *(cPtr+i) = *(str+i);
    }
  } 
  return cPtr;
}

char* countIntDoubles(char* str){
  char* result;
  result = (char*)malloc(sizeof(char*)*3);
  int start = 0; //for substring
  int to; //for substring
  int i, j;
  int iCount = 0; //sum for ints
  int dCount = 0; //sum for doubles
  for (i = 0; *(str+i)!='\0', start < strlen(str); i++){
    if(*(str+i) == ' '){
      to = i; //ending index of substring
      char *subStr = (char*)malloc(sizeof(char*)*100);
      subStr = strncpy(subStr, str+start, to); //https://stackoverflow.com/questions/6679204/how-to-get-substring-in-c/6679254
      for(j = 0; j < strlen(subStr)+1; j++){
        if(isdigit(*(subStr+j))){ //check if string contains integers
          if(strchr(*(subStr+j), '.') != NULL){ //checking for . in a number
            dCount += *(subStr+j);
          }
          else{
            iCount += *(subStr+j);
          }
        }
       }
      start = to +1; //start index shifts to 
      }
    }
  *(result+0) = iCount;
  *(result+1) = dCount;
  return result;
}

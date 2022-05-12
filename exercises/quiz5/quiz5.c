/*
TODO:
Write a Program that does the following: Spam Checker
Research online some of the most common spam e-mail messages and words, and check your own
junk e-mail folder. Create a list of 30 words and phrases commonly found in spam messages. Write
a program in which the user enters an e-mail message. Read the message into a large character array
and ensure that the program does not attempt to insert characters past the end of the array. Then
scan the message for each of the 30 keywords or phrases. For each occurrence of one of these within
the message, add a point to the message’s “spam score.” Next, rate the likelihood that the message
is spam, based on the number of points it received. Print your results in a tabulator format showing 
the words (highest likelihood first)
*/

#include <stdio.h>
#include <string.h>

int main(void) {
  char spamWords[30][5000] = {"as seen on", "order", "status", "buy", "earn", "free", "best price", "one hundred percent free", "money", "no cost", "save money", "serious cash", "no hidden costs", "full refund", "avoid bankruptcy", "get out of debt", "chance", "miracle", "satisfaction", "passwords", "click here", "increase your sales", "direct email", "month trial offer", "subscribe", "unsubscribe", "lose weight", "remove wrinkles", "giving away", "guarantee"}; 
  char userInput[5000];
 
  printf("Enter your email message:\n");
  fgets(userInput, 4999, stdin);
  
  int i, j;
  int count = 0;
  int numOccur[30] = {};
  for(i = 0; i < 30; i++){
    while (j < 5000){
      if(strstr(userInput, spamWords[i])!= NULL){
        count++;
        numOccur[i] += 1;
      }
      j++;
    }
  }
  
  printf("\ncount: %d\n", count);
  return 0;
}

/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/15/2021
 */

//This program should read a string from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

#include <stdio.h>
#include <string.h>

void main(void){
  char s[20];
  char *cPtr;
  //scanf("%[19]s", s); wasn't working for some reason
  fgets(s, 19, stdin);
  cPtr = s;
   
  while(*cPtr != '\0'){
      printf("%c", *(cPtr++));
  }
  printf("\n");
}

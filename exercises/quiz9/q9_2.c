/* Arinah Karim
 * CSCI-C 291/Spring 2021 
 * 3/15/2021
 */


//This program uses a function called CharacterScan to read a char from the user
//The function must take an int pointer as a parameter
//The program should print the char and ascii code for each character the user enters
//The program should only exit whe nthe user enters escape

#include <stdio.h>
#include <stdlib.h>
char CharacterScan(int*);
int main(void){
  //char exit;
  int aCode = 0;
  int* iPtr = &aCode;
  while(1){
    char c = CharacterScan(iPtr);
    aCode = *iPtr;
    if(aCode == 27){
      printf("Exiting the code!\n");
      break;
    }
    else{
      printf("%c is ASCII code %d.\n", c, aCode);
    }
  }
}

char CharacterScan(int *iPtr){
  char c;
  printf("Enter a character: ");
  scanf(" %c", &c);
  int a = (int)c;
  *iPtr = a;
  return c;
}

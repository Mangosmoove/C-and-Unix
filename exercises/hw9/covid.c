/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 4/9/2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct patient {
  char lastName[ 15 ];
  char firstName[ 15 ];
  char gender;
  struct covidData *covidInfo;
};

struct covidData{
  int isCovidPositive;
  char date[12];
};

void main(void){
  FILE *fPtr, *tempPtr;
  fPtr = fopen("nameage.dat", "r");
  tempPtr = fopen("temp.txt", "w");
  struct patient p;
  int i, lines = 30;
  
  
  for (i = 0; i < lines; i++){
    if (i % 2 == 0){
      printf("Enter a last name, first name, gender, positive for covid (0/1), and date (month-date-year): ");
      scanf("%s %s %c %s", p.lastName, p.firstName, p.gender, p.covidInfo->isCovidPositive, p.covidInfo->date);
      fwrite (&p, sizeof(struct patient), 1, tempPtr+i);
    }
    else{
      char *line;
      fscanf(fPtr+i, "%[^\n]", line);
      fwrite(&line, sizeof(line), 1, tempPtr+i);
    }
  }
  fclose(fPtr);
  fclose(tempPtr);
}


/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/9/2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); //shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]); //dealing doesn't modify the arrays
//int highCard(char* f[], char* s[]);
int pairs(char* f[]);
int threeOfKind(char* f[]);
/*int straight(char* f[], char* s[]);
int fullHouse(char* f[]);
*/
int fourOfKind(char* f[]);
//int royalFlush(char* f[], char* s[]);

int main(void){
  //initialize deck array
  unsigned int deck[SUITS][FACES] = { 0 };
  
  srand(time(NULL)); //seed random-number generator

  shuffle(deck); //shuffle the deck

  //initialize suit array
  const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

  //initialize face array
  const char *face[FACES] = {"Ace", "Decuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

  deal(deck, face, suit); //deal the deck
}

//shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES]){
  //for each of the cards, choose slot of deck randomly
  size_t card;
  for(card = 1; card <= CARDS; ++card){
    size_t row; //row number
    size_t column; //column number

    //choose new random location until unoccupied slot found
    do{
      row = rand() % SUITS;
      column = rand() % FACES;
    }while(wDeck[row][column] != 0); //end do...while

    //place card number in chosen slot of deck
    wDeck[row][column] = card;
  }
}

//deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]){
  //deal each of the cards
  size_t card;
  char *face[6];
  char *suit[6];

  for (card = 1; card <= 5; ++card){ //modified to print out 5 cards only
    //loop through rows of wDeck
    size_t row;
    for (row = 0; row < SUITS; ++row){
      //loop thorugh columns of wDeck for current row
      size_t column;
      for (column = 0; column < FACES; ++column){
        //if slot contains current card, display card
        if (wDeck[row][column] == card){
          face[card] = wFace[column];
          suit[card] = wSuit[row];
          printf("%5s of %-8s%c", wFace[column], wSuit[row], card%2 == 0? '\n' : '\t'); //2-column format
        }
      }
    }
  }
  printf("\n");

// testing
/*  int i;
  for (i = 1; i < 6; i++){
    printf("%5s\n", face[i]);
  }

  for (i = 1; i < 6; i++){
    printf("%8s\n", suit[i]);
  }*/
 // printf("Is high card: %d\n", highCard(face, suit));
  printf("Is pairs: %d\n", pairs(face));
  printf("Is three of a kind: %d\n", threeOfKind(face));
 // printf("Is straight: %d\n", straight(face, suit, wFace));
 // printf("Is full house: %d\n", fullHouse(face, suit));
  printf("Is four of a kind: %d\n", fourOfKind(face));
 // printf("Is royal flush: %d\n", royalFlush(face, suit));  
}
/* would work if other functions were implemented 
int highCard(char* f[], char* s[]){
  if (pairs(f) || threeOfKind(f) || straight(f, s) || fullHouse(f, s) || fourofKind(f) || royalFlush(f, s))
    return 0;
  return 1;
}*/
int pairs(char* f[]){
  int i, j;
  for(i = 1; i < 5; i++){
    printf("%8s\n", f[i]);
    for (j = i+1; j < 6; j++){
      if (f[i] == f[j]){
        return 1;
      }
    }  
  }
  return 0;
}
int threeOfKind(char* f[]){
  int i, j;
  int count = 0;
  for(i = 1; i < 5; i++){
    printf("%8s\n", f[i]);
    for (j = i+1; j < 6; j++){
      if (f[i] == f[j]){
        count += 1;
        if (count >= 3){
          return 1;
        }
      }
    }
  }
  return 0; 
}

/*
int straight(char* f[], char* s[], const char* wFace){
  int streak = 0;
  
}*/
/* 
int fullHouse(char* f[]){
  int i, j;
  int streak;

  for(i = 1; i < 5; i++){
    printf("%8s\n", f[i]);
    for (j = i+1; j < 6; j++){
      if (f[i] == f[j]){
        streak++;  
      }
      
    }
  }
  return 0;  
}*/

int fourOfKind(char* f[]){
  int i, j;
  int count = 0;
  for(i = 1; i < 5; i++){
    printf("%8s\n", f[i]);
    for (j = i+1; j < 6; j++){
      if (f[i] == f[j]){
        count += 1;
        if (count >= 4){
          return 1;
        }
      }
    }
  }
  return 0;
}
/*
int royalFlush(char* f[], char* s[]){
  
}*/

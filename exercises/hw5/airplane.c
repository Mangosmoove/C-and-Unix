/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/23/2021
 */

#include<stdio.h>
#include<stdlib.h>
int main(void){
  //make an array of 20 rows, filled with 3 charaters per string
  char seating[20][4] = {"A1", "B1", "x", "D1", "E1", "F1", "x", "H1", "I1",
                         "A2", "B2", "x", "D2", "E2", "F2", "x", "H2", "I2",
                         "A3", "B3", "x", "D3", "E3", "F3", "x", "H3", "I3",
                         "A4", "B4", "x", "D4", "E4", "F4", "x", "H4", "I4",
                         "A5", "B5", "x", "D5", "E5", "F5", "x", "H5", "I5",
                         "A6", "B6", "x", "D6", "E6", "F6", "x", "H6", "I6",
                         "A7", "B7", "x", "D7", "E7", "F7", "x", "H7", "I7",
                         "A8", "B8", "x", "D8", "E8", "F8", "x", "H8", "I8",
                         "A9", "B9", "x", "D9", "E9", "F9", "x", "H9", "I9",
                         "A10", "B10", "x", "D10", "E10", "F10", "x", "H10", "I10",
                         "A11", "B11", "x", "D11", "E11", "F11", "x", "H11", "I11",
                         "A12", "B12", "x", "D12", "E12", "F12", "x", "H12", "I12",
                         "A13", "B13", "x", "D13", "E13", "F13", "x", "H13", "I13",
                         "A14", "B14", "x", "D14", "E14", "F14", "x", "H14", "I14",
                         "A15", "B15", "x", "D15", "E15", "F15", "x", "H15", "I15",
                         "A16", "B16", "x", "D16", "E16", "F16", "x", "H16", "I16",
                         "A17", "B17", "x", "D17", "E17", "F17", "x", "H17", "I17",
                         "A18", "B18", "x", "D18", "E18", "F18", "x", "H18", "I18",
                         "A19", "B19", "x", "D19", "E19", "F19", "x", "H19", "I19",
                         "A20", "B20", "x", "D20", "E20", "F20", "x", "H20", "I20",

  
  //char name[]; //array for names
  char name[140][50]; //for lining up name with which seat they have
  char levelForName[140]; //getting letter representing level at certain index
  char level; //for the 3 different levels
  char display[140] = {' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' ',
                       ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' ', ' '};

  char option; //1-4 & quit
  char response;
  int found;
  
  printf("Menu\n");
  printf("\t1.Choose Seat\n\t2.Print Boarding Pass\n\t3.Display Seating Map\n\t4.Print Manifest\n\tQuit\n");
  printf("Enter a number or Q to quit: ");
  scanf(" %c", &option);

  while (option != 'Q'){
    switch(option){
       case '1':
          printf("\nPlease type 'F' for \"first class\"");
          printf("\nPlease type 'B' for \"business class\"");
          printf("\nOthers will be \"economy class\"");
          printf("Enter your option here: ");
          char level;
          int count = 0;
          scanf(" %c", &level);
            switch(level){
               //seats 0-26
               case 'F':
                 found = rand()%27; //0-26
                 while (display[found] == 'x' || display[found] == 'c' || display[found] == '1' || display[found-1] == 'c' || display[found+1] == 'c' && found != 0){
                   found = rand()%27;
                 }
                 printf("\nWould you like seat %s?(y/n) ", seating[found]);
                 scanf(" %c", &response);
                 if(response == 'n'){
                   printf("\nWould you like a window seat?  (y/n): ");
                   scanf(" %c", &response);
                   if (response == 'y'){
                     int i;
                     found = -1;
                     for (i = 0; i < 20, found == -1; i+=9){
                       if(display[i] != 'x' && display[i] != 'c' && display[i] != '1' && display[i+1] != 'c'){
                         if(i == 0 || display[i-1] != 'c'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                         }
                         if (response == 'y'){
                           found = i;
                         }
                       }
                     }
                     if (found == -1){
                       for (i = 8; i < 20, found == -1; i+=9){
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                           if (response == 'y'){
                             found = i;
                           }
                         }
                       }
                     }
                   } 
                   else if (response == 'n'){
                     printf("\nWould you like an aisle seat?(y/n) ");
                     scanf(" %c", &response);
                     if (response == 'y'){
                       for(i = 1; i < 19, found == -1; i+=9){
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                           if (response == 'y'){
                             found = i;
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 3; i < 22, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 5; i < 23, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       } //
                       if (found == -1){
                         for(i = 7; i < 25, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                     }
                     if (response == 'n'){
                       count = 0;
                       while (count < 3 && found == -1){
                         index = rand()%27;
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1' && display[i+1] != 'c'){
                           if(i == 0 || display[i-1] != 'c'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                           }
                           if (response == 'n'){
                             oount++;
                           }
                           else{
                             found = i;
                           }
                         }
                       } 
                       if (count == 2){
                         printf("\nPlese hop on our next flight.Thanks!");
                       }
                       else{
                         levelForName[found] = 'F';
                      }
                     }
                   }
                 }
                   
                 break;
               case 'B':
                 found = rand()%(62-27+1) + 27; //0-26
                 while (display[found] == 'x' || display[found] == 'c' || display[found] == '1' || display[found-1] == 'c' || display[found+1] == 'c' && found != 0){
                   found = rand()%(62-27+1) + 27;
                 }
                 printf("\nWould you like seat %s?(y/n) ", seating[found]);
                 scanf(" %c", &response);
                 if(response == 'n'){
                   printf("\nWould you like a window seat?  (y/n): ");
                   scanf(" %c", &response);
                   if (response == 'y'){
                     int i;
                     found = -1;
                     for (i = 27; i < 55, found == -1; i+=9){
                       if(display[i] != 'x' && display[i] != 'c' && display[i] != '1' && display[i+1] != 'c'){
                         if(i == 0 || display[i-1] != 'c'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                         }
                         if (response == 'y'){
                           found = i;
                         }
                       }
                     }
                     if (found == -1){
                       for (i = 35; i < 63, found == -1; i+=9){
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                           if (response == 'y'){
                             found = i;
                           }
                         }
                       }
                     }
                   }
                   else if (response == 'n'){
                     found = -1;
                     printf("\nWould you like an aisle seat?(y/n) ");
                     scanf(" %c", &response);
                     if (response == 'y'){
                       for(i = 28; i < 56, found == -1; i+=9){
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                           if (response == 'y'){
                             found = i;
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 30; i < 58, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 32; i < 60, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       } 
                       if (found == -1){
                         for(i = 34; i < 62, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                     }
                     if (response == 'n'){
                       count = 0;
                       while (count < 3 && found == -1){
                         index = rand()%(62-27+1) + 27;
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1' && display[i+1] != 'c'){
                           if(i == 0 || display[i-1] != 'c'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                           }
                           if (response == 'n'){
                             oount++;
                           }
                           else{
                             found = i;
                           }
                         }
                       }
                       if (count == 2){
                         printf("\nPlese hop on our next flight.Thanks!");
                       }
                       else{
                         levelForName[found] = 'B';
                       }
                     }
                   }
                 }

		  break;
               default: //TO BE IMPLEMENTED
                 found = rand()%(148-63+1) + 63; 
                 while (display[found] == 'x' || display[found] == 'c' || display[found] == '1' || display[found-1] == 'c' || display[found+1] == 'c' && found != 0){
                   found = rand()%(148-63+1) + 63;
                 }
                 printf("\nWould you like seat %s?(y/n) ", seating[found]);
                 scanf(" %c", &response);
                 if(response == 'n'){
                   printf("\nWould you like a window seat?  (y/n): ");
                   scanf(" %c", &response);
                   if (response == 'y'){
                     int i;
                     found = -1;
                     for (i = 27; i < 55, found == -1; i+=9){
                       if(display[i] != 'x' && display[i] != 'c' && display[i] != '1' && display[i+1] != 'c'){
                         if(i == 0 || display[i-1] != 'c'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                         }
                         if (response == 'y'){
                           found = i;
                         }
                       }
                     }
                     if (found == -1){
                       for (i = 35; i < 63, found == -1; i+=9){
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                           if (response == 'y'){
                             found = i;
                           }
                         }
                       }
                     }
                   }
                   else if (response == 'n'){
                     found = -1;
                     printf("\nWould you like an aisle seat?(y/n) ");
                     scanf(" %c", &response);
                     if (response == 'y'){
                       for(i = 28; i < 56, found == -1; i+=9){
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                           printf("\nIs seat %s acceptable?(y/n) ");
                           scanf(" %c", &response);
                           if (response == 'y'){
                             found = i;
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 30; i < 58, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 32; i < 60, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                       if (found == -1){
                         for(i = 34; i < 62, found == -1; i+=9){
                           if(display[i] != 'x' && display[i] != 'c' && display[i] != '1'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                             if (response == 'y'){
                               found = i;
                             }
                           }
                         }
                       }
                     }
                     if (response == 'n'){
                       count = 0;
                       while (count < 3 && found == -1){
                         index = rand()%(62-27+1) + 27;
                         if(display[i] != 'x' && display[i] != 'c' && display[i] != '1' && display[i+1] != 'c'){
                           if(i == 0 || display[i-1] != 'c'){
                             printf("\nIs seat %s acceptable?(y/n) ");
                             scanf(" %c", &response);
                           }
                           if (response == 'n'){
                             oount++;
                           }
                           else{
                             found = i;
                           }
                         }
                       }
                       if (count == 2){
                         printf("\nPlese hop on our next flight.Thanks!");
                       }
                       else{
                         levelForName[found] = 'E';
                       }
                     }
                   }
                 }
                 break;
               if (count < 2){
                 display[found] = '1';
                 display[found-1] = 'c';
                 display[found+1] = 'c';

                 printf("\nPlease enter your name: ");
                 scanf( "%s", &name[found]);
               }
          break;
       case '2':
          char seatNum[3];
          printf("Provide the seat assignment: ");
          scanf(" %s", seatNum);
          //loop through array to find index of occurence
          //use that index to find whether seat is taken on display map
          int i;
          int indexOfOccur = -1;
          for (i = 0; i < 140; i++){
            if (seating[i] == seatNum){
              indexOfOccur = i;
              break;
            }
          }
          if (indexOfOccur == -1){
           printf("\nInvalid seat.\n"); 
          }
          else{
            if(display[indexOfOccur] == '0'){
              printf("\nSeat Unassigned - No boarding pass available. Try again!\n");
            }
            else if (display[indexOfOccur] == '1'){
              printf("\nName: %s, Seat: %s, Level: ", name[indexOfOccur], seatNum);
              if (levelForName[indexOfOccur] == 'F'){
                printf("First class\n");    
              }
              else if (levelForName[indexOfOccur] == 'B'){
                printf("Business\n");
              }
              else{
                printf("Economy\n");
              }
            }
            else if (display[indexOfOccur] == 'c'){
              printf("Due to covid, this seat is not available.\n");
            }
          }
          break;
       case '3':
          printf("\n");
          int i;
          for (i = 0; i < 140; i++){
            printf("%c ", display[i]);
            if ((i+1)%9 == 0){
              printf("\n");
            }
          }
          break;
       case '4':
          printf("\nWould you like to view (d)efault or (a)lphabetized manifest? ");
          char response;
          scanf(" %c", &response);
          if (response == 'd'){
            int i;
            printf("Seating:\t\t\tName:\n");
            for(i = 0; i < 140; i++){
              printf("%s\t\t\t%s\n", seating[i], name[i]);
            }
          }
         /* else if (response == 'a'){
          //TODO

          }*/
          else{
            printf("\nInvalid character entered.\n");
          }
          break;
       default:
          printf("Invalid menu option.\n");
          break;

     printf("Menu\n");
     printf("\t1.Choose Seat\n\t2.Print Boarding Pass\n\t3.Display Seating Map\n\t4.Print Manifest\n\tQuit\n");
     printf("Enter a number or Q to quit: ");
     scanf(" %c", &option);
    }
  }
  printf("\nThank you for your time. We hope you enjoy your flight!\n");
  return 0;
}

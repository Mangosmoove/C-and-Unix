/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/1/2021
 */
// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 812, exchange = 424
Output : 
812-424-0001
812-424-0002
812-424-0003
.
.
812-424-9998
812-424-9999
 */

#include<stdio.h>
  
int main(){
   int digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   printf( "Hello, I am a telemarketing calling making program.\n");
   printf(" Enter a three-digit area code ");
   scanf("%d", &areaCode); //changed variable to areaCode 
   printf( "Enter a three-digit exchange to call ");
   scanf("%d", &exchange); //changed variable to exchange
   for(digit1 = 0; digit1 < 10; ++digit1){
        for(digit2 = 0; digit2 < 10; digit2++){
            for(digit3 = 0; digit3 < 10; digit3++){ //got rid of while loop format
                for (digit4 = 0; digit4 < 10; digit4++){ //added another loop for fourth digit
                  printf( "Dialing (%d)-%d-", areaCode , exchange);
                  printf( "%d%d%d%d\n", digit1,digit2,digit3,digit4); //print decimal values
                  printf( "I am calling to tell you to buy a subscription to Dogs Monthly!\n");
                }
            }
        }       
    } 
    printf("\nCalls completed\n");
    return;
  }

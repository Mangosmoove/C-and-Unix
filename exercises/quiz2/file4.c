/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/1/2021
 */

/* Months 4, 6, 9 and 11 have 30 days, Months 1, 3, 5, 7, 8, 10 and 12 have 31 days*/
/* Month 2 usually has 28 days except when it is leap year*/
/* Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100 */
/* But these centurial years are leap years if they are exactly divisible by 400 */
/* For example, the years 1700, 1800, and 1900 were not leap years, but the years 1600 and 2000 were*/
/* Based on these facts, evaluate the eneterd day,month,year is valid or invalid year/month/day 
Total no. of bugs: 20
*/

#include<stdio.h>
int main()
{
   int birthMo;
   int birthDay;
   int birthYr;
   const int HIGHMO = 12;
   const int HIDAY1 = 31;
   const int HIDAY2 = 30;
   const int HIDAY3 = 29;
   const int HIDAY4 = 28;
   const int LOYEAR = 1885;
   const int HIYEAR = 2019;
   printf( "Enter your birth month ");
   scanf(" %d", &birthMo); //2 fix
   printf( "Enter your birth day ");
   scanf(" %d", &birthDay); //3 fix
   printf( "Enter your birth year ");
   scanf(" %d", &birthYr); //4 fix

   if(birthYr < LOYEAR){
      printf("No one is that old\n");
   }else if(birthYr > HIYEAR && birthYr <= 2021){ //1 fix
      printf( "You are too little to be using a computer\n");
   }else{
     printf( "Valid year\n");
   }
   
   if(birthMo > HIGHMO){ //1 fix
      printf( "Invalid month\n");
   }else if(birthMo == 2 && (birthYr%4  == 0 && birthYr%10 != 0 || birthYr%400 == 0)){
         if(birthDay <= HIDAY3 && birthDay > 0){ //1 fix
           printf( "Valid day\n"); //1 fix
         }else{
           printf( "Invalid day for month in %d\n", birthYr ); //3 fix
        }
    }else if(birthMo == 2){
        if(birthDay <= HIDAY4 && birthDay > 0){ //1 fix
           printf( "Valid day\n"); //1 fix
         }else{
           printf( "Invalid day for month in %d\n", birthYr); //3 fix
        }
            //Jan Mar May Jul                   Aug, Oct, Dec
    }else if (birthMo <= 7 && birthMo%2 != 0 || birthMo > 7 && birthMo%2 == 0){//1 fix
         if(birthDay <= HIDAY1 && birthDay > 0){ //1 fix
            printf("Valid day");
        }else{
            printf( "Invalid day for month %d\n", birthMo); //1 fix
        }
    }else{ //1 fix
        if(birthDay <= HIDAY2 && birthDay > 0){ //1 fix
            printf( "Valid day\n"); //1 fix
        }else{
            printf( "Invalid day for month %d\n" , birthMo ); //2 fix
        }
   }
   return 0;//1 fix
}

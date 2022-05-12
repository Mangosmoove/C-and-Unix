/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/12/2021
 */

#include<stdio.h>
#include "const.h" //for getting the constants
#include<stdlib.h> //for rand()

extern const double FW;
extern const double SW;
extern const double RC;
extern const double COMM;
extern const double MINBONUS;
extern const double ADDEDBONUS;
extern const double PROFIT;

double print_statement(int); //function prototype

int main(void){
  // printf("%.2f\n", FW); testing to make sure access to header file works
  int i;
  int n = 5; //num of employees
  double empSold[n]; //goods sold per employee
  int numYear[n]; //years worked per employee
  double commission[n]; //commission per employee
  double bonus[n]; //bonus per employee
  double fedW[n]; //fw. per employee
  double stW[n]; //sw. per employee
  double rt[n]; //rt. per employee
  double netpay[n]; //net pay per employee
  double totSales, totProfit, totComm, totBonus, totFed, totSt, totRT, totNP; //totals for each category

  for (i = 0; i < n; i++){
    empSold[i] = print_statement(1);    
    totSales += empSold[i]; //calculate total sales
   
    //assigning number of years an employee worked at company
    numYear[i] = rand() % (30 + 1 - 1) + 1;
  }
 
  //monthly profit is 45% of monthly sales
  totProfit = totSales * PROFIT;

  //sum of commissions is monthly sales * 12.5%
  totComm = totSales * COMM; 

  //determining commission per each person based on how much they sold * 12.5%
  for(i = 0; i < n; i++){
    commission[i] = empSold[i] * COMM;
  } 

  //determining bonus per person based on profit and how many decades they worked at the company
  for (i = 0; i < n; i++){
    if (numYear[i] < 10){ //for someone who worked less than a decade --> 10% bonus
      bonus[i] = totProfit * MINBONUS;
    }
    else { //worked over a decade --> %10 + %5 for each decade
      int temp = numYear[i] / 10; //determine the number of decades they've been working 
      bonus[i] = totProfit * MINBONUS + (temp * ADDEDBONUS) * totProfit;
    }
    totBonus += bonus[i]; //calculate total bonus
  }

  //calculating federal withholding rate, state witholding rate, retirement contribution, and net pay
  for (i = 0; i < n; i++){
    double sum = commission[i] + bonus[i]; 
    fedW[i] = sum * FW;
    stW[i] = sum * SW;
    rt[i] = sum * RC; 
    netpay[i] = sum - fedW[i] - stW[i] - rt[i];
 
    //calculating totals...
    totFed += fedW[i];
    totSt += stW[i];
    totRT += rt[i];
    totNP += netpay[i]; 
  }
  
  //time to print oh no
  char name; //to keep up with naming employer
  printf("%s\t(%s)\n", "MONTHLY STATEMENT", "JANUARY 2021");
  printf("%*s\n%*s\n%*s\n", 100, "Bloomington Skating Company", 100, "Bloomington, IN", 100, "Phone: (812)-855-0000");
  printf("MONTHLY SALES: %.2f\nMONTHLY PROFIT: %.2f\n", totSales, totProfit);
  printf("====================================================================================================\n");
  printf("Name\tCommission\tBonus\t\tFed W.\t\tST W.\t\tRT\t\t      NetPay\n");
  printf("----------------------------------------------------------------------------------------------------\n");
  for (i = 0, name = 'A'; i < n; i++, ++name){
    printf("Mr. %c\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t     %.2f\n", name, commission[i], bonus[i], fedW[i], stW[i], rt[i], netpay[i]);  
  }
  printf("----------------------------------------------------------------------------------------------------\n");
  printf("Total\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t     %.2f\n", totComm, totBonus, totFed, totSt, totRT, totNP);
  printf("----------------------------------------------------------------------------------------------------\n");
  printf("Net Profit (Profit - Bonus): %.2f\n", (totProfit - totBonus)); 
  printf("John Doe, Branch Manager\n");
  return 0;
}

double print_statement(int num_of_employees){
  int i;
  int n = num_of_employees;

  for (i = 0; i < n; i++){ 
    //designating how much each employee sold from 1k - 10k
    return rand() % (10000 + 1 - 1000) + 1000; //rand % (max + 1 - min) + min
  }
  return 0;
}

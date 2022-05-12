/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 4/9/2021
 */
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int rem(int a, int b);
int power(int a, int b);

int(*operations[])(int, int) = {add, subtract, multiply, divide, rem, power};

void main(void){
  int num1, num2;
  char op;
  int index = 0;
  printf("Enter num1 followed by operation followed by num2: ");
  scanf(" %d %c %d", &num1, &op, &num2);
  //printf("%c\n %d\n", op, op);
  /*while(op != '+' || op != '-' || op != '*' || op != '/' || op != '%' || op != '^'){
      printf("\nIncorrect operation. Please use: +, -, *, or /");
      printf("Enter correct operation: ");
      scanf(" %c", &op);
  } */

  if (op == '+'){
    index = 0;
  }
  else if (op == '-'){
    index = 1;
  }
  else if (op == '*'){
    index = 2;
  }
  else if (op == '/'){
    index = 3;
  }
  else if (op == '%'){
    index = 4;
  }
  else {
    index = 5;
  }
  //printf("%d\n", index);
                                                                                
  int ans = (*operations[index])(num1, num2);
  printf("%d%c%d=%d\n", num1, op, num2, ans); 
}

int add(int a, int b){
  return a+b;
}

int subtract(int a, int b){
  return a-b;
}

int multiply(int a, int b){
  return a*b;
}

int divide(int a, int b){
  return a/b;
}

int rem(int a, int b){
  return a%b;
}

int power(int a, int b){
  return pow(a, b);
}

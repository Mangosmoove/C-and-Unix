// Program to calculate the power of given equation - > x^n
// example - 2^10 -> 1024
// Number of errors/bugs = 13

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>

double my_power(int x, int n); //changed return type from void to double, matched parameter types with 

void main(){
  int x = 2;
  int n = 3; //changed variable type from char to int
  double return_value_function = my_power(x, n); //gave type to variable
  printf("The power value of %d ^ %d is :: %.2f\n", x,n,return_value_function);//changed %s to %f
  return;//got rid of 0
}

//the return value of your func should be x^n result
double my_power(int x, int n) { //changed parameter type to match arguments
    if(n == 0) //changed != to ==
        return 1.0;
    if(n == 1)
        return x; //changed n to x

    int m = n<0 ? -n : n;//fixed ternary expression by swapping ? w/ : and : w/ ?, put -n w/ right if
    double cur = 1.0;//changed type to double
    double ans = x; //created ans variable and assigned it to base value (x)
    while(cur*2 < m) { 
        cur *= 2;
        ans *= ans;//changed to *= instead of /=
    }
   // printf("%d\n", ans);
    ans *= my_power(x, (m-cur)); //got rid of char type cast, made it *= instead of +=
   // printf("%d\n", ans);
    return n<0 ? (1.0/ans) : ans; //fixed ternary expression by swapping ? w/ : and : w/ ?, swapped the results to match conditional
}


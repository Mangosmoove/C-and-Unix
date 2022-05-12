/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/22/2021
 */
// Fig. 5.16: fig05_16.c
// Scoping.

//Todo: Modify the code to print memory addresses of all variables/array elements and
//explain the impact of "static" keyword. Also use an extern variable and discuss how
//it impacts the memory address. Why?

//ANSWERS TO ABOVE
// key word static: the value of the variable with static keyword keeps the value even after function runs completely. The value of the variable keeps incrementing by
// one until the the program is finished running. 
// after some searching on the internet, I learned that global variables stay in the heap while local variables are stored in a stack.

#include <stdio.h>

void useLocal(void); // function prototype
void useStaticLocal(void); // function prototype
void useGlobal(void); // function prototype

int x = 1; // global variable

int main(void){
  int x = 5; // local variable to main
  printf("local variable in main value: %d\n", x);
  printf("local variable in main in memory address: %p\n", &x);
  {
    extern int x;
    printf("local x in outer scope of main is %d\n", x);
    printf("local x in outer scope of main in memory address: %p\n", &x);
  }
  { // start new scope                                     
    int x = 7; // local variable to new scope               
                                                                 
    printf("local x in inner scope of main is %d\n", x);     
    printf("local x in inner scope of main in memory address: %p\n", &x);
  } // end new scope                                          
  {
    extern int x;
    printf("local x in outer scope of main is %d\n", x);
    printf("local x in outer scope of main in memory address: %p\n", &x);
  }
  useLocal(); // useLocal has automatic local x
  useStaticLocal(); // useStaticLocal has static local x
  useGlobal(); // useGlobal uses global x
  useLocal(); // useLocal reinitializes automatic local x
  useStaticLocal(); // static local x retains its prior value
  useGlobal(); // global x also retains its value

   printf("\nlocal x in main is %d\n", x);
   printf("local variable in main in memory address: %p\n", &x);

} 


// useLocal reinitializes local variable x during each call
void useLocal(void){
  int x = 25; // initialized each time useLocal is called

  printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
  printf("local x in useLocal memory address: %p\n", &x);
  ++x;
  printf("local x in useLocal is %d before exiting useLocal\n", x);
  printf("local x in useLocal memory address: %p\n", &x);
} 

// useStaticLocal initializes static local variable x only the first time 
// the function is called; value of x is saved between calls to this
// function
void useStaticLocal(void){
  // initialized once 
  static int x = 50;                        

  printf("\nlocal static x is %d on entering useStaticLocal\n", x);
  printf("local static x in memory address: %p\n", &x);
  ++x;
  printf("local static x is %d on exiting useStaticLocal\n", x);
  printf("local static x in memory address: %p\n", &x);
}

// function useGlobal modifies global variable x during each call
void useGlobal(void){
  printf("\nglobal x is %d on entering useGlobal\n", x);
  printf("global x in memory address: %p\n", &x);
  x *= 10;
  printf("global x is %d on exiting useGlobal\n", x);
  printf("global x in memory address: %p\n", &x);
}

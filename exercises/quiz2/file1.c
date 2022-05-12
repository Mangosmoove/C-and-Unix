/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/1/2021

* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

#include <stdio.h>

int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum, i; //changed limit to 10 since we are only going up to 10
    char c;
    printf("The value of limit is %d\n", limit);
    for(i = 1; i <= limit; i++){ //started i at 1 otherwise the products would have been 0
       if(i%2 == 0){
           even_product *= i; //correctly stored the product of even numbers from 1 -10
       }   
       else if(i%2 != 0){
           odd_product *= i; //correctly stored the product of odd numbers from 1 - 10
       }
    }
    sum = even_product + odd_product;
    printf("The Sum = %d\n", sum);
    for(c = 'Z'; c >= 'A'; c-=2){ //changd to -=2 to decrement properly
      printf("%c ", c);
    }
    return 0;
}

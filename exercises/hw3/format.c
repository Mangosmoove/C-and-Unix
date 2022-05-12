/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/12/2021
 */

#include<stdio.h>
void main(){
  //Part 1
  //a) Print unsigned integer 1001 left justified in a 12-digit field with 6 digits
  printf("%-12.6u\n", 1001);

  //b) Print 7.350 in a 8-digit field with preceding zeros.
  printf("%08.3f\n", 7.350);
   
  //c) Print 300 with a sign
  printf("%+d\n", 300);
 
  //d) Print 300 without a sign
  printf("%d\n", 300); 

  //e) Read a hexadecimal value into variable hex.
  unsigned int hex;
  printf("Enter a hexadecimal value: ");
  scanf(" %x", &hex);
  //printf("hex: 0x%x\n", hex); 
 
  //f) Read an octal value into variable octal.
  unsigned int octal;
  printf("Enter an octal value: ");
  scanf(" %o", &octal);
  printf("Octal value: %o\n", octal);

  //g) Print 100 in hexadecimal form preceded by 0x.
  printf("0x%x\n", 100);  
  //h) Print 100 in octal form preceded by 0. 
  printf("0%o\n", 100); 
  
  //i) Read characters into array m until the letter z is encountered.
  char m[9];
  printf("%s: ", "Enter a string");
  scanf(" %8[^z]", m);
  printf("The string was: %s\n", m);

  //j) Read a time of the form hh-mm-ss, storing the parts of the time in the integer variables hour,
  //minute and second. Skip the dash (-) in the input stream. Use the assignment suppression
  //character.
  int hour, minute, second;
  printf("Enter a time in format of: hh-mm-ss: ");
  scanf(" %d%*c%d%*c%d", &hour, &minute, &second);
  printf("\nHour: %d, Minute: %d, Second: %d\n", hour, minute, second); 
  
  //k) Read a time of the form hh:mm:ss, storing the parts of the time in the integer variables hour,
  //minute and second. Skip the colons (:) in the input stream. Do not use the assignment
  //suppression character.
  printf("Enter a time in format of: hh:mm:ss: ");
  scanf(" %d%*c%d%*c%d", &hour, &minute, &second);
  printf("\nHour: %d, Minute: %d, Second: %d\n", hour, minute, second); 
  //l) Read a string of the form "characters" from the standard input. Store the string in character
  //array s. Eliminate the quotation marks from the input stream. 
  int size = 10;
  char s[size];
  printf("Enter a string in the form of \"string\": ");
  scanf(" %9s", s);
  int i;
  size -= 2;
  char str[size];
  for (i = 1; i < size; i++){
    str[i-1] = s[i];
  }
  str[size-1] = '\0';
  printf("String: %s\n", str);

  //Part 2
  //a) printf( "%-10d\n", 32100 ); my answer: It should run fine. 32100 will be left-aligned and the print expects a minimum of 10 characters to be printed
  printf( "%-6d\n", 32100 ); //my answer was correct 
 
  //b) printf( "%c\n", "This is a string" ); my answer: It will not run correctly because it should use %s instaed of %c
  //printf( "%c\n", "This is a string" ); it printed out some weird three bar thing 
  //corrected version:
   printf("%s\n", "This is a string");
 
  //c) printf( "%*.*lf\n", 8, 3, 7124.921654 ); my answer: it won't print out 8 and 3 but it will print out the last number 
  printf( "%*.*lf\n", 8, 3, 7124.921654 ); //it printed out the floating number but only to two decimal points because the usual precision for a float is 6 digits
 
  //d) printf( "%#o\n%#X\n%#e\n", 17, 17, 1008.83619 ); my answer: it will print 0 with the octal value for 17, then newline and 0xhex for 17, and the scientific notation for the last number
  printf( "%#o\n%#X\n%#e\n", 17, 17, 1008.83619 ); //the last number cut off the 1 and 9 at the end of the base number 

  //e) printf( "% ld\n%+ld\n", 1000000, 8000000 ); my answer: it will print out 100000 as a long int followed by a newline, and then +800000 followed by another newline
  printf( "% ld\n%+ld\n", 1000000, 8000000 ); //my answer was right
 
  //f) printf( "%10.3E\n", 854.93738 ); my answer: it will print out 8.549E3 because the 3 after the . will truncate the numbers after the decimal
  printf( "%10.3E\n", 854.93738 ); //my answer was correct

  //g) printf( "%10.3g\n", 264.93738 ); my answer: it will print 6 spaces in front of 2.649E2 
  printf( "%10.3g\n", 264.93738 ); //it printed out 265 with 7 spaces in front of it because it printed out the shortest representation between %e and %f 
 
   //h) printf( "%d\n", 10.937 ); my answer: it will throw an error
  // printf( "%d\n", 10.937 ); //a random number is printed. I am guessing this is because there is separate memory allocated for the decimal number and the int it is trying to print?
   //coorect implementation:
   printf("%d\n", 10); //will print 10 
}

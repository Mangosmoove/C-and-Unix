/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 2/15/2021
 */

#include<stdio.h>
int main(){
  // 1a
  // unsigned: 2^n-bit - 1
  // signed: -2^(n-bit-1) to 2^(n-bit-1) - 1
  printf("Unsigned range of 16-bit binary number: 0 to 65535\n");
  printf("Signed range of a 16-bit binary number: -32768 to 32767\n");
  // 1b
  printf("Unsigned range of 8-bit binary number: 0 to 255\n");
  printf("Signed range of 8-bit binary number: -128 to 127\n");
 
  // 2a
  // writing -18 as +18 in 8-bit binary:
  // 00010010
  // taking not
  // 11101101
  // adding 1                  0+0 = 0    
  // 11101101                  0+1 = 1
  // +      1                  1+1 = 10 
  // ---------                 1+1+1 = 11
  // 11101110
  printf("2's compliment of -18: 11101110\n");

  // 2b
  // writing -50 as +50 in 8-bit binary
  // 00110010
  // taking not
  // 11001101
  // adding 1
  // 11001101
  // +      1
  // --------
  // 11001110
  printf("2's compliment of -50: 11001110\n");

  // 3a
  // 100_10 --> binary:
  // 64 32 16 8 4 2 1
  // 1  1  0  0 1 0 0
  printf("100 base 10 in binary: 1100100\n");
  
  //1100100_2 to hex
  //grouping in 4:
  //0110 = 6    0100 = 4
  printf("100 base 10 in hexadecimal: 0x64\n");

  //1100100_2 to octal
  //grouping in 3:
  //001 = 1  100 = 4 100 = 4
  printf("100 base 10 in octal: 144\n");

  // 3b
  // 12A hex to binary
  // 1 = 0001
  // 2 = 0010
  // A = 1010
  printf("12A to binary: 000100101010\n");
  
  // 12A hex to decimal:
  // 1 = 1
  // 2 = 2
  // A = 10
  // (1*16^2) + (2*16^1) + (10*16^0)
  printf("12A to decimal: 298\n");

  // 12A hex to octal
  // 000100101010 in 3:
  // 000 = 0 100 = 4  101 = 5 010 = 2
  printf("12A to octal: 452\n");
 
  // 3c
  // 701 in octal to binary:
  // 7 = 111
  // 0 = 000
  // 1 = 001
  printf("701 in octal to binary: 111000001\n");

  // 701 in octal to decimal:
  // 7 * 8^2 + 0 * 8^1 + 1 * 8^0
  // = 448 + 0 + 1
  printf("701 in octal to decimal: 449\n");

  // 701 in octal to hex
  // binary: 111000001
  // group in 4:
  // 0001 = 1  1100 = C   0001 = 1
  printf("701 in octal to hex: 0x1C1\n");

  // 4a
  //  0+0 = 0    
  //  0+1 = 1
  //  1+1 = 10 
  //  1+1+1 = 11
  //
  // A = 00011100
  // B = 01111111
  //    +---------
  //     10011011
  printf("A + B = 10011011\n");
   
  // 1-1 = 0
  // 0-0 = 0
  // 1-0 = 1
  //
  // 01111111
  //-00011100
  //----------
  // 01100011
  printf("B - A = 1100011\n");

  // 0*0 = 0
  // 1*0 = 0
  // 1*1 = 1
  //
  // 1+1+1+1 = 111                       
  //                            
  // A: 00011100 --> 28
  // B: 01111111 --> 127
  // A*B = 28 * 127 = 155
  // binary: 128 64 32 16 8 4 2 1
  //         1   0  0  1  1 0 1 1
  printf("A * B = 10011011\n");                        
                            
  // 4b
  // A = 1754 = 8^3 + 7*8^2 +5*8 + 4 = 1004 
  // B = 10001 = 8^4 + 0 + 0 + 0 + 1 = 4097
  // A + B = 5101
  // 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
  // 1    0    0    1   1   1   1  1  0  1 1 0 1
  //
  // binary: 001 001 111 101 101
  // binary to octal grouping in 3:
  // 001 = 1
  // 001 = 1 
  // 111 = 7
  // 101 = 5
  // 101 = 5
  printf("A + B = 11755\n");
  
  // B-A
  // 4097 - 1004 = 3093
  // 2048 1024 512 256 128 64 32 16 8 4 2 1
  // 1    1    0   0   0   0  0  1  0 1 0 1
  // binary: 110 000 010 101
  // binary to octal grouping in 3:
  // 110 = 6
  // 000 = 0
  // 010 = 2
  // 101 = 5
  printf("B - A = 6025\n");

  // A*B
  // 4097 * 1004 = 4113388
  // 2097152 1048576 524288 262144 131072 65536 32768 16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
  // 1       1       1      1      1      0     1     1     0    0    0    0    1   1   1   1  1  0  1 1 0 0
  // binary: 1 111 101 100 001 111 101 100
  // binary to octal grouping in 3: 
  // 001 = 1 
  // 111 = 7
  // 101 = 5
  // 100 = 4
  // 001 = 1
  // 111 = 7
  // 101 = 5
  // 100 =4
  printf("A * B = 17541754\n");
  
  // 4c
  // A = 100A1 = 16^4 + 0 + 0 + 10 *16 + 1 = 65697
  // B = B1100 = 11* 16^4 + 16^3 + 16^2 + 0 + 0 = 725248
  // A+B = 790945
  // 524288 262144 131072 65536 32768 16384 8192 4096 2048 1026 512 256 128 64 32 16 8 4 2 1
  // 1      1      0      0     0     0     0    1    0    0    0   1   1   0  1  0  0 0 0 1
  // binary: 11000001000110100001
  //
  //
  // binary to hex grouping in 4:
  // 1100 = C
  // 0001 = 1
  // 0001 = 1
  // 1010 = A
  // 0001 = 1
  printf("A + B = C11A1\n");

  // B-A
  // = 659551
  // 524288 262144 131072 65536 32768 16384 8192 4096 2048 1026 512 256 128 64 32 16 8 4 2 1
  // 1      0      1      0     0     0     0    1    0    0    0   0   0   1  0  1  1 1 1 1 
  // binary: 1010 0001 0000 0101 1111
  // binary to hex grouping in 4:
  // 1010 = A
  // 0001 = 1
  // 0000 = 0
  // 0101 = 5
  // 1111 = F
  printf("B - A = A105F\n");

  // A*B 
  // =47646617856
  // 34359738368 17179869184 8589934592 4294967296 2147483648 1073741824 536870912 268435456 134217728 67108864 33554432 16777216 8388608 4194304 2097152 1048576 524288  // 1           0           1          1          0          0          0         1         0         1        1        1        1       1       1       1       1
  // 262144 131072 65536 32768 16384 8192 4096 2048 1026 512 256 128 64 32 16 8 4 2 1
  // 0      1      0     1     0     1    0    0    0    0   1   0   0  0  0  0 0 0 0
  //  1011 = B
  //  0001 = 1
  //  0111 = 7
  //  1111 = F
  //  0101 = 5
  //  1011 = B
  //  0001 = 1
  //  0000 = 0
  //  0000 = 0
  printf("A * B = B17F5B100\n");

  //5
  // 3a: convert 100 to binary, hex, and octal
  printf("Convering 100 in decimal to binary, hex, octal...\n");
  int num = 100;
  int binary[7]; //2^6 = 128, +1 for null character
  int i = 0; //keep track of indices
  while (num != 0){ //keep doing until num cannot be /2
    binary[i]= num % 2; //stores either 1 or 0
    num /= 2; //divide the current num by 2
    i++; //keep track of placement into array
  }
  int j; //to make it more clear and understandable
  printf("Binary: ");
  for (j = i-1; j >= 0; j--){
    printf("%d", binary[j]); //have to print reversed otherwise the formatting will be wrong
  }
  //decimal to hex
  printf("\n%#2X", 100);
 
  //decimal to octal
  printf("\n%#3o", 100);


  printf("\nConverting 12A in hex to binary, decimal, and octal...\n");
  int hex = 0x12A;
  printf("\nDecimal: %d", hex);
  printf("\nOctal: %o", hex);
  printf("\nBinary...\n");

  printf("Converting 701 in octal to binary, decimal, and hex...\n");
  int oct = 0701;
  printf("\nDecimal: %d", oct);
  printf("\nHexadecimal: %x", oct);
  printf("\nBinary: ..\n");

  printf("Working on computations...\n");
  printf("Binary...\n");
  

  int num1 = 01754;
  int num2 = 010001;
  int sum = num1 + num2;
  int difference = num2 - num1;
  int product = num1 * num2;
  printf("Octal sum: %o\n", sum);
  printf("Octal difference: %o\n", difference);
  printf("Octal product: %o\n", product);
 
  int hex1 = 0x100A1;
  int hex2 = 0xB1100;
  int hexSum = hex1 + hex2;
  int hexDiff = hex2 - hex1;
  int hexProd = hex1 * hex2;
  printf("Hex sum: %x\n", hexSum);
  printf("Hex difference: %x\n", hexDiff);
  printf("Hex product: %x\n", hexProd); //my answer was off by a the first letter so I probably converted wrong...
}  

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {

/* Declare variables */
   int i,inum,tmp,numdigits;
   float fnum;
   char binnum[60];


/* Intialise 4-byte integer */
   inum = 6;//33554431;
/* Convert to 4-byte float */
   fnum = (float) inum;


/* Convert to binary number (string)*/
   i = 0; tmp = inum;
   while (tmp > 0) {
     sprintf(&binnum[i],"%1d",tmp%2);
     tmp = tmp/2;
     i++;
   }

/* Terminate the string */
   binnum[i] = '\0';

/* Reverse the String binnum*/
   int length, mid, j;
   char aux;
   length = strlen(binnum);
   mid = length/2;
   for(i = 0; i < mid; i++) {
       j = length-i-1;
       aux = binnum[i];
       binnum[i] = binnum[j];
       binnum[j] = aux;
    }

/* TODO: Complete the expression */
/*   numdigits = ceil(...);
   printf("The number of digits is %d\n",numdigits);
*/
   numdigits = ceil(log2f(inum + 1)); // Using log2f to calculate the number of digits
   printf("The number of binary digits is %d\n", numdigits);
   printf("inum=%d,  fnum=%f, inum in binary=%s\n",inum,fnum,binnum);

   return 0;
}

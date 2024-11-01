
#include <stdio.h>

int main(void) {
   int num_1, num_2, error;

   printf("Please input two positive integers\n");
   error = scanf("%d %d",&num_1,&num_2);
   if (error != 2) {
     printf("Please try again\n");
     return 1;
   }

   if (num_1<=0 || num_2<=0) {
     printf("These numbers are not positive!\n");
     return 1;
   }

   printf(" You entered %d and %d\n",num_1,num_2);
   if (num_1%2 == 0) {
      printf(" num_1 is even and");
   } else {
      printf(" num_1 is odd and");
   }

   if (num_2%2 == 0) {
      printf(" num_2 is even\n");
   } else {
      printf(" num_2 is odd\n");
   }
   printf("\n");


  return 0;
}




#include <stdio.h>

void fibonacci(int *fn1, int *fn2) {
    int temp = *fn1 + *fn2;
    *fn2 = *fn1; 
    *fn1 = temp;
}

int main(void) {
    int n;
    
    //input
    printf("Enter the value of n (no: of terms in Fibonacci series): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer\n");
        return 1;
    }

    // print the series
    printf("Fibonacci Series up to %d terms:\n", n);

    int fn1 = 1, fn2 = 0; // Initial values
    printf("%d ", fn2);   
    if (n > 1) {
        printf("%d ", fn1);   
    }

    for (int i = 2; i < n; i++) {
        fibonacci(&fn1, &fn2); // Calculate the next number in the series
        printf("%d ", fn1); 
    }
    printf("\n");

    return 0;
}

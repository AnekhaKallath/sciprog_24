#include <stdio.h>

/* Function to compute next Fibonacci number */
void fibonacci(int *fn1, int *fn2) {
    int temp = *fn1 + *fn2;
    *fn2 = *fn1;  // Update Fn-2 to the previous Fn-1
    *fn1 = temp;  // Update Fn-1 to Fn
}

int main(void) {
    int n;
    
    /* Get input */
    printf("Enter the value of n (no: of terms in Fibonacci series): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer\n");
        return 1;
    }

    /* Print Fibonacci series */
    printf("Fibonacci Series up to %d terms:\n", n);

    int fn1 = 1, fn2 = 0; // Initial values: F0 = 0, F1 = 1
    printf("%d ", fn2);   // Print F0
    if (n > 1) {
        printf("%d ", fn1);   // Print F1
    }

    for (int i = 2; i < n; i++) {
        fibonacci(&fn1, &fn2); // Calculate the next number in the series
        printf("%d ", fn1);         // Print it
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Allocate memory for array
double* allocateArray(int size) {
    return (double*)malloc(size * sizeof(double));
}

// Fill array with ones
void fillWithOnes(double* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1.0;
    }
}

// Print array
void printArray(double* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", array[i]);
    }
    printf("\n");
}

// Free memory
void freeArray(double* array) {
    free(array);
}

// Calculate factorial
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Calculate Taylor series
double calExponential(int order) {
    double estimate = 0.0;
    for (int i = 0; i <= order; i++) {
        estimate += 1.0 / factorial(i); 
    }
    return estimate;
}

int main() {
    const double trueValue = exp(1);
    int order;

    printf("Enter the order of the polynomial: ");
    scanf("%d", &order);

    double* estimates = allocateArray(order + 1);

    for (int i = 0; i <= order; i++) {
        estimates[i] = calExponential(i);
    }

    printf("\nOrder\tEstimate\tDifference\n");
    for (int i = 0; i <= order; i++) {
        printf("%d\t%lf\t%lf\n", i, estimates[i], fabs(trueValue - estimates[i]));
    }

    printf("Actual value of e = 2.7182818284\n");

    freeArray(estimates);

    int size;
    printf("\nEnter the size of array for pointer operations: ");
    scanf("%d", &size);

    double* intArray = allocateArray(size);
    fillWithOnes(intArray, size);

    printf("\nArray filled with ones: ");
    printArray(intArray, size);

    freeArray(intArray);

    return 0;
}

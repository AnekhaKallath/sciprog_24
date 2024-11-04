#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate aarray
double* allocate_array(int order) {
    return (double*)malloc(order * sizeof(double));
}

// Function to calculate the factorial
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate approximation for e
double e_approximation(double* terms, int order) {
    double sum = 0.0;
    for (int i = 0; i < order; i++) {
        terms[i] = 1.0 / factorial(i);
        sum += terms[i];
    }
    return sum;
}

// Function to free the allocated memory for the array
void free_array(double* array) {
    free(array);
}

// Functions for integer array operations
int* allocate_integer_array(int size) {
    return (int*)malloc(size * sizeof(int));
}

//function to fill every cell of the array with one
void fill_with_ones(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

//function to print the array elements
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void free_integer_array(int* array) {
    free(array);
}

int main() {
    const double actual_value = 2.71828;  // Approximate true value of e

    // Loop through orders from 1 to 15 for the polynomial approximation
    for (int order = 1; order <= 15; order++) {
        double* terms = allocate_array(order);
        double approximation = e_approximation(terms, order);
        printf("Order %d: Approximation = %.5f, Error = %.5f\n", order, approximation, actual_value - approximation);
        free_array(terms);
    }

    // Demonstrating integer array operations
    int size = 10;
    int* int_array = allocate_integer_array(size);
    fill_with_ones(int_array, size);
    printf("Integer array filled with ones: ");
    print_array(int_array, size);
    free_integer_array(int_array);

    return 0;
}

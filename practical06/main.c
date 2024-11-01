#include <stdio.h>

void matmult(double A[5][3], double B[3][4], double C[5][4]);

int main() {
    int n = 5, p = 3, q = 4;
    double A[5][3], B[3][4], C[5][4] = {0};

    // Initialize matrices A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            A[i][j] = i + j;
        }
    }
    
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            B[i][j] = i - j;
        }
    }

    // Call the matrix multiplication function
    matmult(A, B, C);

    // Print matrix A
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }

    // Print matrix B
    printf("\nMatrix B:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%.2f ", B[i][j]);
        }
        printf("\n");
    }

    // Print matrix C
    printf("\nMatrix C (Result of A * B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

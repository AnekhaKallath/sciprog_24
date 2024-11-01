#include <stdio.h>
#include <math.h>

/* Maclaurin series approximation */
double artanh_mclaurin(double x, double delta) {
    double sum = 0.0;
    double term = x;  // since first term is x^1 / 1
    int n = 0;

    while (fabs(term) > delta) {
        sum += term;
        n++;
        term = pow(x, 2*n + 1) / (2*n + 1);  // Next term: x^(2n+1) / (2n+1)
    }

    return sum;
}

/* Logarithmic formula for arctanh(x) */
double artanh_log(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

int main(void) {
    double x, delta;
    
    /* Get user input */
    printf("Enter a value for x (|x| < 1): ");
    scanf("%lf", &x);
    if (fabs(x) >= 1) {
        printf("Invalid input. |x| must be less than 1.\n");
        return 1;
    }

    printf("Enter a small positive number for delta (precision): ");
    scanf("%lf", &delta);
    if (delta <= 0) {
        printf("Invalid input, delta must be a positive number.\n");
        return 1;
    }

    /* Compute arctanh using both methods */
    double result_mclaurin = artanh_mclaurin(x, delta);
    double result_log = artanh_log(x);

    /* Output the results */
    printf("Maclaurin series approximation of arctanh(%lf): %lf\n", x, result_mclaurin);
    printf("Logarithmic formula result of arctanh(%lf): %lf\n", x, result_log);

    return 0;
}

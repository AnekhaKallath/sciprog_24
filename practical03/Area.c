#include <stdio.h>
#include <math.h>

int main(void) {
    
    int i;
    double a, b, h, sum, result, exact_result, difference;
    int N = 12;  // Number of points

    a = 0.0;
    b = M_PI / 3.0;

    // Step size
    h = (b - a) / (N - 1);

    // first and last points
    sum = tan(a) + tan(b);

    // Intermediate points
    for (i = 1; i < N - 1; i++) {
        double xi = a + i * h; 
        sum += 2 * tan(xi); 
    }

    result = (b - a) * sum / (2 * (N - 1));

    // log2 results
    exact_result = log(2.0);

    difference = result - exact_result;

    printf("Approximate integral using Trapezoidal Rule: %f\n", result);
    printf("Exact integral (log(2)): %f\n", exact_result);
    printf("Difference: %f\n", fabs(difference));

    return 0;
}

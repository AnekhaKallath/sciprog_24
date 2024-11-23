#include <stdio.h>
#include <math.h>

// arctanh using Maclaurin series
double artanh1(double x, double delta) {
    double term = x;
    double result = 0.0;
    int n = 1;

    while (fabs(term) >= delta) {
        result += term;
        n += 2;
        term = pow(x, n) / n;
    }
    return result;
}

// arctanh using log
double artanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

int main() {
    double delta, x;
    double maclaurin[181];
    double log_result[181];
    int index = 0;

    printf("Enter a positive precision value (delta): ");
    scanf("%lf", &delta);

    if (delta <= 0) {
        printf("Delta must be a positive value.\n");
        return 1;
    }

    for (x = -0.9; x <= 0.9; x += 0.01) {
        maclaurin[index] = artanh1(x, delta);
        log_result[index] = artanh2(x);
        index++;
    }

    // Compare results to 10 significant figures
    printf("\nx\tartanh1\t\tartanh2\t\tDifference\n");
    for (int i = 0; i < 181; i++) {
        double difference = fabs(maclaurin[i] - log_result[i]);
        printf("%.2f\t%.10f\t%.10f\t%.10e\n", 
               -0.9 + i * 0.01, 
               maclaurin[i], 
               log_result[i], 
               difference);
    }

    return 0;
}

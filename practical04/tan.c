#include <stdio.h>
#include <math.h>

float tan_values[13];  
float pi;

// function from week 4 lecture
float degtorad(float arg) {
    return ((pi * arg) / 180.0);
}

// Trapezoidal rule
float trapezoidal_rule(float values[], int n, float a, float b) {
    float sum = 0.0;
    float h = (b - a) / (n - 1); 
    int i;

    sum = values[0] + values[n - 1]; 

    for (i = 1; i < n - 1; i++) {
        sum += 2.0 * values[i];
    }

    return (h / 2.0) * sum;
}

int main(void) {
    
    float degang, radang;
    int i;

    // initialize pi
    pi = atanf(1.0) * 4.0;

    // degrees from 0-60
    for (i = 0; i <= 12; i++) {
        degang = i * 5;  
        radang = degtorad(degang);  // Convert to radians
        tan_values[i] = tanf(radang);  // Compute tan(x)
        printf("Degree: %f, Radian: %f, tan(x): %f\n", degang, radang, tan_values[i]);
    }

    // area under tanx
    float area = trapezoidal_rule(tan_values, 13, 0.0, degtorad(60.0));
    printf("Area under the curve of tan(x) from 0 to 60 degrees: %f\n", area);

    return 0;
}

#include <stdio.h>

int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("GCD (Iterative) of %d and %d is: %d\n", a, b, gcd_iterative(a, b));
    return 0;
}

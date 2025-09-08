#include <stdio.h>
int main() {
    float a, b;
    printf("Enter first number: ");
    scanf("%f", &a);
    printf("Enter second number: ");
    scanf("%f", &b);
    printf("Addition       : %.2f\n", a + b);
    printf("Subtraction    : %.2f\n", a - b);
    printf("Multiplication : %.2f\n", a * b);
    printf("Division       : %.2f\n", a / b);
    return 0;
}

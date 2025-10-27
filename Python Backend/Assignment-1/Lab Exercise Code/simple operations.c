#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("\nArithmetic Operations:\n");
    printf("Sum = %d\n", a + b);
    printf("Difference = %d\n", a - b);
    printf("Product = %d\n", a * b);
    printf("Quotient = %d\n", a / b);

    printf("\nRelational Operations:\n");
    printf("a == b : %d\n", a == b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);

    printf("\nLogical Operations:\n");
    printf("a && b : %d\n", a && b);
    printf("a || b : %d\n", a || b);
    printf("!a : %d\n", !a);

    return 0;
}

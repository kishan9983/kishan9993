#include <stdio.h>

int factorial_recursive(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial (Recursive): %d\n", factorial_recursive(num));
    printf("Factorial (Iterative): %d\n", factorial_iterative(num));

    return 0;
}

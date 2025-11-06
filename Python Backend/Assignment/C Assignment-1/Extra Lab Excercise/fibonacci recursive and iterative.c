#include <stdio.h>

// Recursive function for Fibonacci
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function for Fibonacci
int fibonacci_iterative(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0)
        return 0;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci Sequence (Recursive):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }

    printf("\n\nNth Fibonacci Number (Recursive) = %d\n", fibonacci_recursive(n - 1));
    printf("Nth Fibonacci Number (Iterative) = %d\n", fibonacci_iterative(n - 1));

    printf("\nNote: Recursive method is slower for large N due to repeated calculations.\n");

    return 0;
}

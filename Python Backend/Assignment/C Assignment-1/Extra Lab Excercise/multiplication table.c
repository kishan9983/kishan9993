#include <stdio.h>

int main() {
    int num, range, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter range (e.g., print table up to): ");
    scanf("%d", &range);

    printf("Multiplication table of %d up to %d:\n", num, range);
    for (i = 1; i <= range; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}

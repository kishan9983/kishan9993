#include <stdio.h>

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("%d is Even\n", num);
    else
        printf("%d is Odd\n", num);

    if (num > 0)
        printf("%d is Positive\n", num);
    else if (num < 0)
        printf("%d is Negative\n", num);
    else
        printf("The number is Zero\n");

    if (num % 3 == 0 && num % 5 == 0)
        printf("%d is a multiple of both 3 and 5\n", num);
    else
        printf("%d is not a multiple of both 3 and 5\n", num);

    return 0;
}

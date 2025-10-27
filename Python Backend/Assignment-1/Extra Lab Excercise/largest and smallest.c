Using if-else:


#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("Largest number: %d\n", a);
    else if (b >= a && b >= c)
        printf("Largest number: %d\n", b);
    else
        printf("Largest number: %d\n", c);

    if (a <= b && a <= c)
        printf("Smallest number: %d\n", a);
    else if (b <= a && b <= c)
        printf("Smallest number: %d\n", b);
    else
        printf("Smallest number: %d\n", c);

    return 0;
}







Using switch-case:


#include <stdio.h>

int main() {
    int a, b, c, largest, smallest;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    smallest = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

    switch (1) {
        case 1:
            printf("Largest number: %d\n", largest);
            printf("Smallest number: %d\n", smallest);
            break;
    }

    return 0;
}





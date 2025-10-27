#include <stdio.h>

int main() {
    int i;

    printf("Using while loop:\n");
    i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }

    printf("\n\nUsing for loop:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }

    printf("\n\nUsing do-while loop:\n");
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);

    return 0;
}

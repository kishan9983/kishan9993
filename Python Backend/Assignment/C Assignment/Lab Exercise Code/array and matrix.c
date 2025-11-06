#include <stdio.h>

int main() {
    int i, j;

    int arr[5];
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("1D Array Elements:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    int matrix[3][3], sum = 0;
    printf("\n\nEnter 3x3 matrix elements:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
        }
    }

    printf("\n3x3 Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of all elements = %d\n", sum);

    return 0;
}

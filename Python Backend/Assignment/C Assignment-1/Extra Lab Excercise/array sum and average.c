#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = sum / n;

    printf("\nSum of all elements = %.2f\n", sum);
    printf("Average of elements = %.2f\n", avg);

    return 0;
}

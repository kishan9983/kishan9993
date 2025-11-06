#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, digit, sum = 0, n = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    temp = num;
    while (temp != 0) {
        digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }

    if (sum == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    printf("\nArmstrong numbers between 1 and 1000:\n");
    for (int i = 1; i <= 1000; i++) {
        int t = i, s = 0, d, c = 0;

        int temp2 = t;
        while (temp2 != 0) {
            temp2 /= 10;
            c++;
        }

        temp2 = t;
        while (temp2 != 0) {
            d = temp2 % 10;
            s += pow(d, c);
            temp2 /= 10;
        }

        if (s == i)
            printf("%d ", i);
    }

    return 0;
}

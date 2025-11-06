#include <stdio.h>

void reverseString(char str[]) {
    int i = 0, j = 0;
    char temp;

    // Find string length manually
    while (str[j] != '\0') {
        j++;
    }
    j--; // Move to last character index

    // Swap characters from both ends
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

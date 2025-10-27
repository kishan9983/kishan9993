#include <stdio.h>
#include <string.h>

int main() {
    char str[200], longest[50], word[50];
    int i = 0, j = 0, maxLen = 0, wordCount = 0;

    printf("Enter a sentence: ");
    gets(str);

    while (1) {
        if (str[i] == ' ' || str[i] == '\0') {
            word[j] = '\0';
            if (j > 0) {
                wordCount++;
                if (j > maxLen) {
                    maxLen = j;
                    strcpy(longest, word);
                }
                j = 0;
            }
            if (str[i] == '\0')
                break;
        } else {
            word[j] = str[i];
            j++;
        }
        i++;
    }

    printf("\nTotal words: %d\n", wordCount);
    printf("Longest word: %s\n", longest);
    printf("Length of longest word: %d\n", maxLen);

    return 0;
}

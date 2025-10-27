#include <stdio.h>

int main() {
    FILE *fp;
    char text[100], ch;

    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter a string to write into the file: ");
    gets(text);

    fputs(text, fp);
    fclose(fp);

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nFile contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    return 0;
}

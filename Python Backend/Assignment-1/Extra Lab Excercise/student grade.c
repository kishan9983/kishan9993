#include <stdio.h>

int main() {
    int marks;

    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks > 90)
        printf("Grade: A\n");
    else if (marks > 75 && marks <= 90)
        printf("Grade: B\n");
    else if (marks > 50 && marks <= 75)
        printf("Grade: C\n");
    else
        printf("Grade: D\n");

    return 0;
}

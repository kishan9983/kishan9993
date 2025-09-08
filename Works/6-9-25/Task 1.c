#include <stdio.h>
int main() {
    char name[50], birthdate[20], address[50];
    int age;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your birthdate: ");
    scanf("%s", birthdate);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your address: ");
    scanf("%s", address);
    printf("\n--- Your Details ---\n");
    printf("Name      : %s\n", name);
    printf("Birthdate : %s\n", birthdate);
    printf("Age       : %d\n", age);
    printf("Address   : %s\n", address);
    return 0;
}

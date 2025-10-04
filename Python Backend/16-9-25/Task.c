#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int choice, quantity;
    int totalAmount = 0;
    char moreOrders = 'y';

    while (moreOrders == 'y' || moreOrders == 'Y') {
        printf("\n1. Pizza    price = 180rs/pcs");
        printf("\n2. Burger   price = 100rs/pcs");
        printf("\n3. Dosa     price = 120rs/pcs");
        printf("\n4. Idli     price = 50rs/pcs");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You have selected Pizza.\n");
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                totalAmount += quantity * 180;
                printf("Current Total Amount: %d\n", totalAmount);
                break;

            case 2:
                printf("You have selected Burger.\n");
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                totalAmount += quantity * 100;
                printf("Current Total Amount: %d\n", totalAmount);
                break;

            case 3:
                printf("You have selected Dosa.\n");
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                totalAmount += quantity * 120;
                printf("Current Total Amount: %d\n", totalAmount);
                break;

            case 4:
                printf("You have selected Idli.\n");
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                totalAmount += quantity * 50;
                printf("Current Total Amount: %d\n", totalAmount);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("Do you want to place more orders? (y/n): ");
        scanf(" %c", &moreOrders);
    }

    printf("\nFinal Total Amount to Pay = %d\n", totalAmount);
    printf("Thank you for your order!\n");

    return 0;
}
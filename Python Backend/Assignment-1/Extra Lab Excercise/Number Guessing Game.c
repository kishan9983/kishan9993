#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, guess, attempts = 0;
    number = rand() % 100 + 1;  // Generates random number between 1 and 100

    printf("Guess the number between 1 and 100!\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            printf("Correct! You guessed the number in %d attempts.\n", attempts);
            break;
        } 
        else if (guess > number) {
            printf("Too high! Try again.\n");
        } 
        else {
            printf("Too low! Try again.\n");
        }

        if (attempts == 7) {
            printf("You've used all 7 attempts. The number was %d.\n", number);
            break;
        }
    }

    return 0;
}

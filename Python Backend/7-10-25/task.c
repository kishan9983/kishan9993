#include <stdio.h>
#include <stdlib.h>

int main() {
    int lucky, guess, tries = 0, maxTries = 5;
    srand(1);
    lucky = (rand() % 10) + 1;

    printf("Guess the Lucky Number between 1 to 10\n");

    while (tries < maxTries) {
        scanf("%d", &guess);
        tries++;

        if (guess == lucky) {
            printf("Congratulations! You guessed the number\n");
            return 0;
        } else if (guess < lucky) {
            printf("Try with higher number\n");
        } else {
            printf("Try with lower number\n");
        }
    }

    printf("Maximum tries available (%d) -> Game Over\n", maxTries);
    printf("The Lucky Number was: %d\n", lucky);

    return 0;
}

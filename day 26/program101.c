#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess;
    int attempts = 0;

    
    srand(time(NULL));

    
    secret_number = (rand() % 100) + 1;

    printf("=========================================\n");
    printf("   Welcome to the Number Guessing Game!  \n");
    printf("=========================================\n");
    printf("I have chosen a secret number between 1 and 100.\n\n");

    
    do {
        printf("Enter your guess: ");
        
        
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n\n");
            while (getchar() != '\n'); 
            continue;
        }

        attempts++;

        
        if (guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } 
        else if (guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } 
        else {
            printf("\n🎉 CONGRATULATIONS! You found the hidden number!\n");
            printf("It took you exactly %d attempts.\n", attempts);
        }

    } while (guess != secret_number);

    return 0;
}

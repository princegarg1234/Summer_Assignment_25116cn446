#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    char text[256];
    char options[4][64];
    char correct_option; 
} Question;

void display_welcome_message();
void play_quiz(Question quiz[], int total_questions);

int main() {
    
    Question quiz[] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. C", "C. Java", "D. Assembly"},
            'B'
        },
        {
            "What is the correct format specifier for a double variable in printf()?",
            {"A. %d", "B. %c", "C. %f", "D. %lf"},
            'D'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. volatile", "C. const", "D. immutable"},
            'C'
        },
        {
            "What does the malloc() function return if allocation fails?",
            {"A. 0", "B. NULL", "C. Void pointer", "D. Garbage value"},
            'B'
        }
    };

    
    int total_questions = sizeof(quiz) / sizeof(quiz[0]);
    char choice;

    do {
        display_welcome_message();
        printf("Enter 'S' to Start the quiz or 'Q' to Quit: ");
        
        
        if (scanf(" %c", &choice) != 1) {
            choice = 'Q';
        }
        choice = toupper(choice);

        if (choice == 'S') {
            play_quiz(quiz, total_questions);
        } else if (choice != 'Q') {
            printf("\n[!] Invalid input. Please select 'S' or 'Q'.\n\n");
        }

    } while (choice != 'Q');

    printf("\nThank you for using the Quiz Application! Goodbye.\n");
    return 0;
}


void display_welcome_message() {
    printf("==========================================\n");
    printf("        WELCOME TO THE COMPUTER QUIZ      \n");
    printf("==========================================\n");
}

void play_quiz(Question quiz[], int total_questions) {
    int score = 0;
    char user_answer;

    printf("\n--- The Quiz Has Started! Good Luck! ---\n\n");

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].text);
        
    
        for (int j = 0; j < 4; j++) {
            printf("  %s\n", quiz[i].options[j]);
        }

        
        while (1) {
            printf("Your Answer (A/B/C/D): ");
            scanf(" %c", &user_answer);
            user_answer = toupper(user_answer);

            if (user_answer >= 'A' && user_answer <= 'D') {
                break;
            }
            printf("[!] Invalid choice. Enter a character between A and D.\n");
        }

    
        if (user_answer == quiz[i].correct_option) {
            printf(">> Correct!\n\n");
            score++;
        } else {
            printf(">> Wrong answer! The correct option was %c.\n\n", quiz[i].correct_option);
        }
    }

    
    printf("==========================================\n");
    printf("               QUIZ OVER                  \n");
    printf("==========================================\n");
    printf("Your final score is: %d out of %d\n", score, total_questions);
    
    float percentage = ((float)score / total_questions) * 100;
    printf("Passing Grade Score: %.2f%%\n", percentage);
    
    if (percentage >= 70.0) {
        printf("Status: PASSED! Excellent job!\n");
    } else {
        printf("Status: FAILED. Better luck next time!\n");
    }
    printf("==========================================\n\n");
}

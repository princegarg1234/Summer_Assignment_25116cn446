#include <stdio.h>
#include <stdbool.h>


float balance = 5000.00; 
int default_pin = 1234;  


void check_balance();
void deposit_money();
void withdraw_money();
bool authenticate_user();

int main() {
    int choice;
    printf("=========================================\n");
    printf("      WELCOME TO THE ATM SIMULATION      \n");
    printf("=========================================\n");

    
    if (!authenticate_user()) {
        printf("\nToo many incorrect attempts. Card locked!\n");
        return 0;
    }

    
    while (true) {
        printf("\n---------- MAIN MENU ----------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_balance();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid option! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}


bool authenticate_user() {
    int entered_pin;
    int attempts = 0;
    const int max_attempts = 3;

    while (attempts < max_attempts) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == default_pin) {
            return true; 
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", max_attempts - attempts);
        }
    }
    return false;
}


void check_balance() {
    printf("\n>>> Your current balance is: $%.2f <<<\n", balance);
}

void deposit_money() {
    float amount;
    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Deposit must be greater than zero.\n");
    } else {
        balance += amount;
        printf("Successfully deposited $%.2f\n", amount);
        printf("Updated balance: $%.2f\n", balance);
    }
}


void withdraw_money() {
    float amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Withdrawal must be greater than zero.\n");
    } else if (amount > balance) {
        printf("Transaction Denied: Insufficient balance!\n");
    } else {
        balance -= amount;
        printf("Successfully withdrew $%.2f\n", amount);
        printf("Remaining balance: $%.2f\n", balance);
    }
}

#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} BankAccount;

BankAccount bank[MAX_ACCOUNTS];
int totalAccounts = 0;


void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
int findAccount(int accNo);

int main() {
    int choice;
    do {
        printf("\n1. Create Account | 2. Deposit | 3. Withdraw | 4. Balance | 5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
        }
    } while (choice != 5);
    return 0;
}


void createAccount() { /* ... */ }
void depositMoney() { /* ... */ }
void withdrawMoney() { /* ... */ }
void checkBalance() { /* ... */ }
int findAccount(int accNo) { /* ... */ }

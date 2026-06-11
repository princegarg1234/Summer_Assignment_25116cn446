#include <stdio.h>

unsigned long long findFactorial(int n);

int main() {
    int number;
    unsigned long long factorial;

    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else if (number > 20) {
        printf("Error: This program only supports up to 20 due to integer limits.\n");
    } else {
        
        factorial = findFactorial(number);
        printf("Factorial of %d = %llu\n", number, factorial);
    }

    return 0;
}


unsigned long long findFactorial(int n) {
    unsigned long long result = 1;
    
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

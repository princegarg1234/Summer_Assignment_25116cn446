#include <stdio.h>

int sumOfDigits(int num);

int main() {
    int number, result;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < 0) {
        number = -number;
    }

    result = sumOfDigits(number);

    printf("Sum of digits: %d\n", result);

    return 0;
}

int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    
    return (num % 10) + sumOfDigits(num / 10);
}

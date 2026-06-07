#include <stdio.h>


int reverse_recursive(int num, int reversed_accumulator) {
    
    if (num == 0) {
        return reversed_accumulator;
    }
    
    int last_digit = num % 10;
    int updated_accumulator = (reversed_accumulator * 10) + last_digit;
    
    return reverse_recursive(num / 10, updated_accumulator);
}

int main() {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int result = reverse_recursive(number, 0);

    
    printf("Reversed number: %d\n", result);

    return 0;
}

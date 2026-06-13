#include <stdio.h>

int isPalindrome(int num);

int main() {
    int number;

    
    printf("Enter an integer: ");
    scanf("%d", &number);

    
    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}


int isPalindrome(int num) {
    
    if (num < 0) {
        return 0; 
    }

    int original = num;
    int reversed = 0;
    int remainder;

    
    while (num != 0) {
        remainder = num % 10;
        reversed = (reversed * 10) + remainder;
        num /= 10;
    }

    
    return (original == reversed);
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    
    if (str[end] == '\n') {
        str[end] = '\0';
        end--;
    }


    while (start < end) {
        if (str[start] != str[end]) {
            return false; 
        }
        start++;
        end--;
    }
    return true; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is NOT a palindrome.\n");
    }

    return 0;
}

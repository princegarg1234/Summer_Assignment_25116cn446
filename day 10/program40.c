#include <stdio.h>

int main() {
    int rows = 5; 

    for (int i = 1; i <= rows; i++) {
        
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        
        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            printf("%c", ch++);
        }

        
        ch -= 2; 
        for (int j = 1; j < i; j++) {
            printf("%c", ch--);
        }

        
        printf("\n");
    }

    return 0;
}
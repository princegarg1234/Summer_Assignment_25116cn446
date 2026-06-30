#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

int main() {
    char str[100];
    int freq[ASCII_SIZE] = {0}; 
    int max_count = 0;
    char max_char = ' ';

    printf("Enter any string: ");
    
    if (fgets(str, sizeof(str), stdin) != NULL) {
        
        str[strcspn(str, "\n")] = '\0';
    }


    for (int i = 0; str[i] != '\0'; i++) {
        
        unsigned char index = (unsigned char)str[i];
        freq[index]++;
    }

    
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_char = (char)i;
        }
    }

    
    if (max_count > 0) {
        printf("Maximum occurring character is '%c', appearing %d times.\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}

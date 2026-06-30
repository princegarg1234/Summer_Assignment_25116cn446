#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char text[500];
    
    
    char current_word[100];
    char longest_word[100] = "";
    
    int i = 0, j = 0;
    int max_length = 0;

    printf("Enter a sentence: ");
    
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    
    while (text[i] != '\0') {
       
        if (isalnum((unsigned char)text[i])) {
            current_word[j++] = text[i];
        } 
        
        else if (j > 0) {
            current_word[j] = '\0'; 
            
            
            if (j > max_length) {
                max_length = j;
                strcpy(longest_word, current_word);
            }
            j = 0; 
        }
        i++;
    }

    
    if (j > max_length) {
        current_word[j] = '\0';
        max_length = j;
        strcpy(longest_word, current_word);
    }

    
    if (max_length > 0) {
        printf("\nThe longest word is: \"%s\"\n", longest_word);
        printf("Length of the longest word: %d characters\n", max_length);
    } else {
        printf("\nNo words were found in the input.\n");
    }

    return 0;
}

#include <stdio.h>
#include <ctype.h> 

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; 

    while (*str) {
        
        if (isspace((unsigned char)*str)) {
            in_word = 0; 
        } 
        
        else if (!in_word) {
            in_word = 1;
            count++;   
        }
        str++; 
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int total_words = count_words(sentence);
        printf("Total number of words: %d\n", total_words);
    }

    return 0;
}

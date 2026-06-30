#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50


int compare_word_lengths(const void *a, const void *b) {

    const char *word_a = (const char *)a;
    const char *word_b = (const char *)b;
    
    
    size_t len_a = strlen(word_a);
    size_t len_b = strlen(word_b);
    

    if (len_a < len_b) return -1;
    if (len_a > len_b) return 1;
    
    
    return strcmp(word_a, word_b);
}

int main() {
    int n;
    char words[MAX_WORDS][MAX_LENGTH];

    
    printf("Enter the number of words: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    
    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    
    qsort(words, n, MAX_LENGTH * sizeof(char), compare_word_lengths);

    
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Length: %zu)\n", words[i], strlen(words[i]));
    }

    return 0;
}

#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0}; 
    int i;

    printf("Enter a string: ");
    
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    
    for (i = 0; str[i] != '\0'; i++) {
        
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;
        }
    }


    printf("\nCharacter Frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}

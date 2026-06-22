#include <stdio.h>


void removeSpaces(char *str) {
    int readIdx = 0;
    int writeIdx = 0;

    
    while (str[readIdx] != '\0') {
        
        if (str[readIdx] != ' ') {
            str[writeIdx] = str[readIdx];
            writeIdx++;
        }
        readIdx++;
    }
    
    
    str[writeIdx] = '\0';
}

int main() {
    
    char message[200];

    printf("Enter a string with spaces: ");
    
    
    if (fgets(message, sizeof(message), stdin) != NULL) {
        
    
        removeSpaces(message);
        
        
        printf("Resulting string: %s", message);
    }

    return 0;
}

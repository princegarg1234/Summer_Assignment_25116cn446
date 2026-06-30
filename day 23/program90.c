#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256  


char findFirstRepeating(char *str) {
    int count[MAX_CHAR] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        
        unsigned char ch = str[i];

        
        if (count[ch] == 1) {
            return str[i];
        }
        
        
        count[ch]++;
    }

    
    return '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    
    scanf("%[^\n]s", str); 

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}

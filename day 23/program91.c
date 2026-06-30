#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define CHARSET_SIZE 256
bool check_anagram(const char *str1, const char *str2) {
    
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    int count[CHARSET_SIZE] = {0};

    
    for (int i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    for (int i = 0; i < CHARSET_SIZE; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter the first string: ");
    
    fgets(str1, sizeof(str1), stdin);
    
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (check_anagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }

    return 0;
}

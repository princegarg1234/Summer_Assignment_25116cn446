#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void helper_remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char str1[200], str2[100], temp[200];
    int choice;
    int result;

    do {
        
        printf("\n=================================");
        printf("\n   STRING OPERATIONS SYSTEM");
        printf("\n=================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                helper_remove_newline(str1);
                
                printf("Length of the string is: %zu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                fgets(str1, sizeof(str1), stdin);
                helper_remove_newline(str1);
                
            
                strcpy(str2, str1);
                printf("String copied successfully!\n");
                printf("Original String: %s\n", str1);
                printf("Copied String:   %s\n", str2);
                break;

            case 3:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                helper_remove_newline(str1);

                printf("Enter the second string to append: ");
                fgets(str2, sizeof(str2), stdin);
                helper_remove_newline(str2);

                
                if (strlen(str1) + strlen(str2) >= sizeof(str1)) {
                    printf("Error: Combined string size exceeds buffer limit.\n");
                } else {
                    strcat(str1, str2);
                    printf("Concatenated string: %s\n", str1);
                }
                break;

            case 4:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                helper_remove_newline(str1);

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                helper_remove_newline(str2);

                result = strcmp(str1, str2);
                if (result == 0) {
                    printf("Both strings are perfectly equal.\n");
                } else if (result > 0) {
                    printf("The first string is lexicographically greater than the second.\n");
                } else {
                    printf("The second string is lexicographically greater than the first.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                helper_remove_newline(str1);

                
                int len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char t = str1[i];
                    str1[i] = str1[len - 1 - i];
                    str1[len - 1 - i] = t;
                }
                printf("Reversed string: %s\n", str1);
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid selection! Please enter a choice between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

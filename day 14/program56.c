#include <stdio.h>

void findDuplicates(int arr[], int size) {
    int i, j, isDuplicate;
    int alreadyPrinted;

    printf("Duplicate elements in the array: ");
    

    for (i = 0; i < size; i++) {
        isDuplicate = 0;
        alreadyPrinted = 0;

        
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                alreadyPrinted = 1;
                break;
            }
        }

        
        if (alreadyPrinted) {
            continue;
        }

        
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        
        if (isDuplicate) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    
    int arr[] = {4, 2, 7, 2, 8, 3, 7, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    findDuplicates(arr, size);

    return 0;
}

#include <stdio.h>

void findPairBruteForce(int arr[], int size, int targetSum) {
    int found = 0;

    
    for (int i = 0; i < size - 1; i++) {
    
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pair found with the given sum.\n");
    }
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\nTarget Sum: %d\n\n", targetSum);

    findPairBruteForce(arr, size, targetSum);

    return 0;
}

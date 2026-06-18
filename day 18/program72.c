#include <stdio.h>

int main() {
    int arr[100];
    int size, i, j, temp;

    
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            
            if (arr[i] < arr[j]) { 
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    
    printf("\nArray sorted in descending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

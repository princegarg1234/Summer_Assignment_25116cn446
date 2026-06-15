#include <stdio.h>


void moveZeroesToEnd(int arr[], int size) {
    int nonZeroCount = 0;

    
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[nonZeroCount] = arr[i];
            nonZeroCount++;
        }
    }

    
    while (nonZeroCount < size) {
        arr[nonZeroCount] = 0;
        nonZeroCount++;
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {1, 0, 2, 0, 4, 3, 0, 5};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, size);

    moveZeroesToEnd(data, size);

    printf("Modified array: ");
    printArray(data, size);

    return 0;
}

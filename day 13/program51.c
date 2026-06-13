#include <stdio.h>

int main() {
    int arr[100];
    int size, i;
    int largest, smallest;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    
    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    largest = arr[0];
    smallest = arr[0];

    
    for (i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    
    printf("\nLargest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}

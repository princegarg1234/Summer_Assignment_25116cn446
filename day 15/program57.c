#include <stdio.h>


void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        
        start++;
        end--;
    }
}

int main() {
    int n;

    
    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];


    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    reverseArray(arr, n);

    
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

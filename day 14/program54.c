#include <stdio.h>

int main() {
    int size, target, count = 0;

    
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter the element to find its frequency: ");
    scanf("%d", &target);

    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    
    printf("Frequency of %d = %d\n", target, count);

    return 0;
}

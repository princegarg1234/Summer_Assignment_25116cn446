#include <stdio.h>


int linearSearch(int arr[], int size, int target) {
    
    for (int i = 0; i < size; i++) {
        
        if (arr[i] == target) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {12, 45, 67, 89, 23, 90, 34};
    int target = 23;
    
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    
    int result = linearSearch(arr, size, target);
    
    
    if (result != -1) {
        printf("Element %d found at index: %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}

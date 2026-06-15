#include <stdio.h>
#include <limits.h> 

void findSecondLargest(int arr[], int size) {
    
    if (size < 2) {
        printf("Invalid Input! Array must contain at least 2 elements.\n");
        return;
    }

    
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < size; i++) {
        
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
    
        else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    
    if (second_largest == INT_MIN) {
        printf("There is no second largest unique element.\n");
    } else {
        printf("The largest element is: %d\n", largest);
        printf("The second largest element is: %d\n", second_largest);
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    findSecondLargest(arr, size);

    return 0;
}




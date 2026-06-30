#include <stdio.h>


void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; 
    int j = 0; 
    int k = 0; 


    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }


    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    
    int mergedSize = n1 + n2;
    int merged[mergedSize];

    
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    
    printf("Merged Sorted Array: \n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

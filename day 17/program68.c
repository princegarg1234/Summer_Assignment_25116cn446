#include <stdio.h>

int main() {
    
    int arr1[] = {1, 2, 4, 5, 6, 2, 8};
    int arr2[] = {4, 2, 9, 2, 5, 10};
    
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    
    int common[100];
    int k = 0; 

    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            
            if (arr1[i] == arr2[j]) {
                int isDuplicate = 0;
                
                
                for (int x = 0; x < k; x++) {
                    if (arr1[i] == common[x]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                
                
                if (!isDuplicate) {
                    common[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }

    
    printf("\n\nCommon elements are: ");
    if (k == 0) {
        printf("None");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%d ", common[i]);
        }
    }
    printf("\n");

    return 0;
}

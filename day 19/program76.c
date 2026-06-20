#include <stdio.h>

int main() {
    int size;
    int principal_sum = 0;
    int secondary_sum = 0;

    
    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &size);

    int matrix[size][size];

    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (int i = 0; i < size; i++) {
        principal_sum += matrix[i][i];              
        secondary_sum += matrix[i][size - i - 1];  
    }

    
    printf("\n--- Results ---\n");
    printf("Sum of Principal Diagonal elements: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal elements: %d\n", secondary_sum);

    return 0;
}

#include <stdio.h>

int main() {
    int rows, cols;

    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    printf("\nRow-wise sums:\n");
    for (int i = 0; i < rows; i++) {
        int rowSum = 0; 
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; 
        }
        printf("Sum of Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}

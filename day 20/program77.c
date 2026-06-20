#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;

    
    printf("Enter rows and columns for the first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2) return 1;

    
    printf("Enter rows and columns for the second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2) return 1;

    
    if (c1 != r2) {
        printf("\nError: Multiplication is impossible!\n");
        printf("Columns of the 1st matrix must match rows of the 2nd matrix.\n");
        return 1;
    }

    
    int mat1[r1][c1];
    int mat2[r2][c2];
    int result[r1][c2];

    
    printf("\nEnter elements of the first matrix (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (scanf("%d", &mat1[i][j]) != 1) return 1;
        }
    }

    
    printf("\nEnter elements of the second matrix (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (scanf("%d", &mat2[i][j]) != 1) return 1;
        }
    }

    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    
    printf("\nResultant Matrix (%dx%d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

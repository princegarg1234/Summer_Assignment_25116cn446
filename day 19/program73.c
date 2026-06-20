#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int m1[r][c], m2[r][c], sum[r][c];

    
    for(i=0; i<r; i++)
        for(j=0; j<c; j++) {
            printf("Enter elements for A[%d][%d] and B[%d][%d]: ", i, j, i, j);
            scanf("%d %d", &m1[i][j], &m2[i][j]);
        }

    
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            sum[i][j] = m1[i][j] + m2[i][j];

    
    printf("\nSum Matrix:\n");
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) printf("%d ", sum[i][j]);
        printf("\n");
    }
    return 0;
}

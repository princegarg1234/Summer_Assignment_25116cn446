#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int m1[r][c], m2[r][c], res[r][c];

    
    printf("Enter matrix 1:\n");
    for(i=0; i<r; i++) for(j=0; j<c; j++) scanf("%d", &m1[i][j]);
    printf("Enter matrix 2:\n");
    for(i=0; i<r; i++) for(j=0; j<c; j++) scanf("%d", &m2[i][j]);


    printf("Result:\n");
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            res[i][j] = m1[i][j] - m2[i][j];
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>


void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int terms;

    
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        
        printFibonacci(terms);
    }

    return 0;
}

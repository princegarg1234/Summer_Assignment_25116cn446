#include <stdio.h>


int addNumbers(int a, int b);

int main() {
    int num1, num2, sum;

    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    
    sum = addNumbers(num1, num2);

    
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}

int addNumbers(int a, int b) {
    return a + b;
}

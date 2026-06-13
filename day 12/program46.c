#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}
bool isArmstrong(int num) {
    int originalNum = num;
    int digits = countDigits(num);
    int sum = 0;

    while (num != 0) {
        int remainder = num % 10;
        
        sum += round(pow(remainder, digits)); 
        
        num /= 10;
    }

    
    return (sum == originalNum);
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

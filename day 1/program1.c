#include<stdio.h>
int main(){
    int a,sum=0;
    printf("enter number upto which sum is to be calculated ");
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        sum+=i;

    }
    printf("the sum of first %d natural number is %d ",a,sum);
    return 0;
}
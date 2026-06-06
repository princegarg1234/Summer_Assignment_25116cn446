#include<stdio.h>
int main(){
    int a,fact=1;
    printf("enter number whose factorial is to b e calculated");
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        fact*=i;
    }
printf("the factorial of number %d is %d",a,fact);
return 0;
}
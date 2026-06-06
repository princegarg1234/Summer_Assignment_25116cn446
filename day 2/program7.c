#include<stdio.h>
int main(){
    int a,b,product=1;
    printf("enter the number");
    scanf("%d",&a);
    int c=a;
    while(a!=0){
        b=a%10;
        product*=b;
        a=a/10;
    }
printf("the product of digit of number %d is %d",c,product);
return 0;
}
#include<stdio.h>
int main(){
    int a,b,c,gcd;
    printf("enter first number");
    scanf("%d",&a);
    printf("enter second number");
    scanf("%d",&b);
    if(a>b){
        c=b;
    }
    else{
        c=a;
    }
    for(int i=2;i<=c;i++){
        if(a%i==0 && b%i==0){
            gcd=i;}}
printf("%d is gcd of %d and %d",gcd,a,b);
return 0;}
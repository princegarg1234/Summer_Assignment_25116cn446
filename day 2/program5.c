#include<stdio.h>
int main(){
    int a,c, sum=0;
    printf("enter the number");
    scanf("%d",&a);
    int b=a;
    while(a!=0){
        c=a%10;
        sum+=c;
        a=a/10;
    }
printf("the sum  of digit of number %d is %d",b,sum);
return 0;
}
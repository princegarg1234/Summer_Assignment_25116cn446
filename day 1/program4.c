#include<stdio.h>
int main(){
    int a,count=0;
    printf("enter the number whose digit is to be calculated");
    scanf("%d",&a);
    int b=a;
    while(a!=0){
        a=a/10;
        count++;}
printf("the number of digit in number %d is %d",b,count);
return 0;
}
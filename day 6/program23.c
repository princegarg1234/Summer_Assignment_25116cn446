#include<stdio.h>
int main(){
    int a;
    printf("enter the decimal number  ");
    scanf("%d",&a);
    int count=0;
    int d=a;
    while(a!=0){
        if(a%2==1){
            count++;
        }
        a=a/2;
    }
printf("the count of set bits in number %d is %d ",d,count);
return 0;

}
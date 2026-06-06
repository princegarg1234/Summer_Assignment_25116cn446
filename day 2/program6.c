#include<stdio.h>
int main(){
    int  a,c,rev=0;
    printf("Enter the number");
    scanf("%d",&a);
    while(a!=0){
     
        c=a%10;
        rev=rev*10+c;
        a=a/10;
    }
printf("%d",rev);
return 0;
}
#include<stdio.h>
int main(){
    int a;
    printf("enter the number");
    scanf("%d",&a);
    if(a==0||a==1){
        printf("%d is not a prime number",a);
    }
    for(int i=2;i<a;i++){
        if(a%i==0){
            printf("%d is not a prime number",a);
            break;
        }
        else{
            printf("%d is a prime number",a);
            break;

        }
    }
return 0;
    }
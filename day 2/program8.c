#include<stdio.h>
int main(){
    int a,b,rev=0;
    printf("enter the number");
    scanf("%d",&a);
    int c=a;
    while(a!=0){
        b=a%10;
        rev=rev*10+b;
        a=a/10;
    }
if(c==rev){
    printf("the entered number %d is palindrone",c);}
else{printf("the entered number %d is not palindrone",c);
}
return 0;
}
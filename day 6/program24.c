#include<stdio.h>
#include<math.h>
int main(){
    int a,n;
    printf("enter the number");
    scanf("%d",&a);
    printf("enter its power");
    scanf("%d",&n);
    int c=pow(a,n);
    printf("the value of %d**%d is %d",a,n,c);
    return 0;
    
}
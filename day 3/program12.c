#include<stdio.h>
int main(){
    int a,b,c,lcm;
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
            lcm=i;
            break;
            
        }
        else{
            lcm=1;
        }

    }
printf("%d is lcm of %d and %d",lcm,a,b);
return 0;


}
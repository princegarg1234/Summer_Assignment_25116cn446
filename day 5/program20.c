#include<stdio.h>
int main(){
    int a,larprime=0,j,prime;
    printf("enter the number");
    scanf("%d",&a);
    for(int i=2;i<a;i++){
        if(a%i==0){
            prime =1;
            for(j=2;j<i;j++){
                if(i%j==0){
                    prime=0;
                    
                }
            }
        if(prime==1){
            larprime=i;
        }
        }

    }
   


    
printf("the largest prime factor of number %d is %d",a,larprime);
return 0;}
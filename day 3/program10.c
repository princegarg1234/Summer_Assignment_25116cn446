#include<stdio.h>
int main(){
    int a,b,j;
    printf("enter the starting ");
    scanf("%d",&a);
    printf("enter ending ");
    scanf("%d",&b);
    for(int i=a;i<=b;i++){
       

    
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }

        }
    if(i==j){printf("%d",i);

    }
    
    }
return 0;






}
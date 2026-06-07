#include<stdio.h>
int main(){
    int first,second,next,a;
    first=1;
    second=1;
    printf("enter to print number of fibonacci term");
    scanf("%d",&a);
    if(a>=1){
        printf("%d ",first);
    
    }
       
    if(a>=2){
        printf("%d ",second);
    }
   
    for(int i=3;i<=a;i++){
        next=first+second;
        printf("%d ",next);
        first=second;
        second=next;
        
    }
return 0;

}
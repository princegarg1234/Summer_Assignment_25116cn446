#include<stdio.h>
int main(){
    int first,second,next;
    first=1;
    second=1;
    printf("%d,%d,",first,second);
    for(int i=3;i<=5;i++){
        next=first+second;
        printf("%d,",next);
        first=second;
        second=next;
        
    }
return 0;

}
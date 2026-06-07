#include<stdio.h>
int main(){
    int start,end,a,rev;
    printf("enter starting ");
    scanf("%d",&start);
    printf("enter ending value");
    scanf("%d",&end);

    for(int i=start;i<=end;i++){

        a=i;
        int d=a;
        rev=0;
        while(a!=0){
            int c=a%10;
            rev+=c*c*c;
            a=a/10;

        }
    if(d==rev){
        printf("%d ",rev);
    }
    }
return 0;

}
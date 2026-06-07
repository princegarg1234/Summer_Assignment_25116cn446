#include<stdio.h>
#include<math.h>
int main(){
    int a,count=0,ans=0;
    printf("enter the binary number");
    scanf("%d",&a);
    int d=a;

    while(a!=0){
        int c=a%10;
        count++;
        a=a/10;

    }
    
    for(int i=0;i<count;i++){
        int e=d%10;
        ans+=e*pow(2,i);
        d=d/10;

        }
    
printf(" NUMER TO DECIMAL IS %d",ans);
return 0;

}
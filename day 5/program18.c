#include<stdio.h>
int fact(int a){
    int fact=1;
    for(int i=1;i<=a;i++){
        fact*=i;

    }
return fact;
}
int main(){
    int a,ans=0;
    printf("enter the digit");
    scanf("%d",&a);
    int s=a;
    while(a!=0){
        int c=a%10;
        ans+=fact(c);
        a=a/10;
    }
if(s==ans){
    printf("%d is a strong number",s);
}
else{
    printf("%d is not a strong number",s);

}
return 0;



}
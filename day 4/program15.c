#include<stdio.h>
int main(){
    int a,rev=0;
    printf("enter the number to be checked");
    scanf("%d",&a);
    int b=a;
    while(a!=0){
        int c=a%10;
        rev+=c*c*c;
        a=a/10;
    }
if(b==rev){
    printf("%d is an armstrong number",b);
}
else{
    printf("%d is not an armstrong number",b);
}
return 0;

}
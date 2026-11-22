#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long fact(int n){
    if(n<=1) return 1;
    else return n*fact(n-1);
}
long long fib(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fib(n-1)+fib(n-2);
}
int gcd (int a,int b){
    if(b==0) return a;
    return gcd(b,a%b); // works because the common divisor of a and b also divides remainder of a/b (a%b)
}
void towerofhanoi(int n,char source,char des,char aux){
    if(n==1){
     printf("move 1 disc from %c to %c\n",source,des);
    return;}
    towerofhanoi(n-1,source,aux,des);
    printf("move %d disc from %c to %c\n",n,source ,des);
    towerofhanoi(n-1,aux,des,source);
}
void revstr(char string[],int left ,int right){
    if(left>=right) return ;
    char temp = string[right];
    string[right]=string[left];
    string[left]=temp;
    revstr(string,left+1,right-1);
}
long long ackerman(int m, int n){
    if(m==0) return n+1;
    else if( n==0) return ackerman(m-1,1);
    else return ackerman(m-1,ackerman(m,n-1));
}
int main(){
    printf("%d ",fact(5));
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",fib(i));
    }
    char string[5]="DAIM";
    revstr(string,0,3);
    printf("%s",string);
    printf(" gcd=%d\n",gcd(26,250));
    printf("ackerman(10,2) :%lld\n",ackerman(3,4));
    towerofhanoi(3,'a','c','b');

    return 0;

}
#include<stdio.h>
void search(int arr[],int n,int key){
    int left=0;
    int right=n-1;
    int middle=0;
    int flag=0;
    while(left<=right && middle<= n-1){
    middle =(left+right)/2;
    if(key==arr[middle]) {flag=1;printf("found at index %d",middle);break;}
    else if(key>arr[middle]) left=middle+1;
    else if(key<arr[middle]) right=middle-1;
    }
    if (flag==0){
        printf("not found");
    }
}
int main(){
    int arr[20]={0,1,3,4,5,6,7,8,9,10,11,12,16,44,45,78,90,101,105,108};
    search(arr,20,108);
    return 0;
}
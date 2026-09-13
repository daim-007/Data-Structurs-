#include <stdio.h>
void trav();
void search();
void insert();
void delete();
   
int main(){
    int arr[100],n,key,num,pos,del;
    printf("Enter size of array\n");
    scanf ("%d",&n);
     printf("Enter Elements of array\n");
     for (int i=0;i<n;i++){
        scanf ("%d",&arr[i]);
     }
     trav (arr, n);
     printf ("\nenter number to be found:");
     scanf ("%d",&key); 
     search(arr,n,key);
     printf("enter number you want to insert and position to be inserted into \n");
     scanf ("%d %d",&num,&pos);
     insert ( &arr[0], &n,num,pos);
     trav(arr,n);
     printf("\n");
     printf ("Enter number you want to delete\n");
     scanf ("%d",&del);
     delete(&arr[0],&n,del);
     trav(arr,n);
     return 0;
}
void trav(int arr[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void search(int arr[],int n, int key){
    int flag =0;
    int j;
    for (j=0;j<n;j++){
        if (key== arr[j]){
            printf ("Element found at %d\n",j);
            flag=1;
        }
    }
    if (flag==0){
        printf ("Element not found\n");
    }
}
void insert(int *p,int *q,int num,int pos){
    for(int i=*q;i>=pos;i--){
        p[i+1]=p[i];
    }
    *q=*q+1;
    p[pos]=num;
    }
    void delete(int *p,int *q,int del){
        int i,pos=-1;
        for (i=0;i<*q;i++){
            if(p[i]==del){
                pos= i;
                   (*q)--;
                   i--;
                 for(int j=pos;j<*q;j++){
            p[j]=p[j+1];
                 }
        }
        }
        if(pos==-1)
            printf ("Element not found\n");
        }
   

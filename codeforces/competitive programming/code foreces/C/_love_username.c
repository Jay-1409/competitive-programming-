#include<stdio.h>
#include<string.h>
int main(){
    int x;
    scanf("%d",&x);
    int arr[x];
    for(int i=0;i<x;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    int answer=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=i;j++){
            if(arr[i]>arr[j]){
                count=count+1;
            } 
            if(count=i){
                answer=answer+1;
            }               
        }
    }
    // for(int i=1;i<=x;i++){
    //     for(int j=1;j<=i;j++){
    //         if(arr[i]<arr[j]){
    //             count=count+1;
    //         }                 
    //     }
    // }
    printf("%d",answer);
}
    // printf("%d",arr[2]);
    // int n=arr[0];
    // for(int i=0;i<x;i++){
    //     if(arr[i]>n){
    //         n=arr[i];
    //     }
      
    // }
    // int m=arr[0];
    // for(int j=0;j<=x;j++){
    //     if(arr[j]<m){
    //         m=arr[j];
    //     }
    // }
    // // printf("%d \n",n);
    // // printf("%d",m);
    // int count=0;
    // for(int i=0;i<=x;i++){
    //     if(arr[i+1]>arr[i+2]){
    //         count=count+1;
    //     }
    // }
    // for(int i=0;i<=x;i++){
    //     if(arr[i+1]<arr[i+2]){
    //         count=count+1;
    //     }
    // }
    // printf("%d",count);


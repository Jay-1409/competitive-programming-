#include<stdio.h>
int main(){
    int n,count=0;
    int arr[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        if(arr[0]==-1){
            count++;
        }
        if(arr[i]==-1){
            // if(arr[i-1]>0){
            //     continue;
            // }
            if(arr[i-1]<0){
                count=count+1;
            }
        }
    }
    printf("%d",count);
}
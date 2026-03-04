#include<stdio.h>
int main(){
    int n,k;
    int count=0;
    scanf("%d %d",&n,&k);char arr[n];
    for(int i=0;i<=n-1;i++){
        int a;scanf("%d",&a);arr[i]=a;
    }
    int x=arr[k-1];
    int flag=0;
    for(int k=0;k<=n-1;k++){
        arr[k];
        if(arr[k]==0){
            flag=flag+1;
        }
    }
    for(int j=0;j<=n-1;j++){
        int y=arr[j];
        if(y>=x){
            if(arr[j]>0){
            count=count+1;
            }
        }
    }
    if(flag==n){
    printf("0");
}
    else{
    printf("%d",count);
    }
}
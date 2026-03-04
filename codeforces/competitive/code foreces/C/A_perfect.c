#include<stdio.h>
int main(){
    char arr[100];
    int x=1;
    for(int k=0;k<=100;k++){
        arr[k]=x;
        x=x+1;
    }
    // printf("%d",arr[99]);
    int n;
    scanf("%d",&n);
//     int i;//i<=n
//     for(i=0;i<=n;i=i+2){
        // int a=0;
        // a=arr[i+1];
        // arr[i+1]=arr[i];
//         arr[i]=a;
//     }
//     printf("%d",arr[2]);
// 
    if(n%2!=0){
        printf("-1");
    }
    else{
    for(int i=0;i<=n;i=i+2){
        int a=0;
        a=arr[i+1];
        // printf("%d \n",a);
        arr[i+1]=arr[i];
        arr[i]=a;
        }
    for(int j=0;j<=n-1;j++){
        printf("%d ",arr[j]);
    }
    }
}

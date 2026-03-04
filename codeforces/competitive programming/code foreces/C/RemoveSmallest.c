#include<stdio.h>
#include<string.h>
int main(){
    int t,n;
    scanf("%d \n %d",&t,&n);
    char arr[n];
    // printf("lenth o: %d",strlen(arr));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // printf("%d",arr[2]);
    // int count=0;
    for(int i=1;i<=n;i++){
        int x=n-i;
        for(int j=1;j<=n-i;j++){
        if(arr[i]-arr[i+j]<=1){
            // count=count+1;
            for(int k=i;k<n-1;k++){
            arr[k]=arr[k+1];
            }
            n--;
            // if(arr[i]<arr[i+j]){
            //     for(int k=0;k<n;k++){
            //         arr[i]=arr[i+1];
            //         n--;
            //     }
            // }
            // else if(arr[i]>arr[i+j]){
            //     for(int l=0;l<n;l++){
            //         arr[i+j]=arr[i+j+1];
            //         n--;
            //     }
            // }
            // else if(arr[i]==arr[i+j]){
            //     for(int l=0;l<n;l++){
            //         arr[l+j]=arr[l+j+1];
            //         n--;
            //     }
            // }
        }
    }
}
// int x=strlen(arr);
printf("lenth n: %d",n);
if(n<=1){
    printf("YES");
}
else{printf("NO");}
}


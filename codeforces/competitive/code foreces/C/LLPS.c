#include<stdio.h>
#include<string.h>
int main(){
    char arr[1000];
    fgets(arr,1000,stdin);
    int n=strlen(arr)-1;int count=0;
int max=0;
    for(int i=0;i<=n;i++){
        if(max>arr[i]){
            count=i-1;
        }
        else{
        max=arr[i];
        }
    }
    char x=max;
// printf("%c",x);
    int flag=0;
    for(int j=0;j<=n;j++){
        if(arr[j]==max){
            flag++;
        }
    }
    // printf("%d",flag);
    for(int k=1;k<=flag;k++){
        printf("%c",x);
    }   
}
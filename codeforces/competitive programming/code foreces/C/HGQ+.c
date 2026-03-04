#include<stdio.h>
int main(){
    char arr[100];
    int count=0;
    fgets(arr,100,stdin);
    for(int i=0;i<=99;i++){
        if(arr[i]=='H'){
            count=count+1;
        }
        else if(arr[i]=='Q'){
            count=count+1;
        }
        else if(arr[i]=='9'){
            count=count+1;
        }
        else if(arr[i]=='+'){
            count=count;
        }
}
    if(count>0){
        printf("YES");
    }
    else{
        printf("NO");
    }
}
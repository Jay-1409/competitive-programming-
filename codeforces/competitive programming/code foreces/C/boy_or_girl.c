#include<stdio.h>
#include<string.h>
int main(){
    char arr[100];
    fgets(arr,100,stdin);
    int x=strlen(arr);
    // for(int l=0;arr[l]!="\n";l++){
    //     char n;
    //     scanf("%c",n);
    //     arr[l]=n;
    // }
    int count_a=0;
    int count_b=0;
    int count_c=0;

    for(int i=0;i<=x-3;i++){
        if(arr[i]==arr[x-1]){
        count_a=count_a+1;
        }
        x=x-1;
    }
    for(int j=0;j<=x-2;j++){
        if(arr[j]==arr[j+1]){
            count_b=count_b+1;
        }
    }
    for(int m=0;m<=100-x;m++){
    for(int k=0;k<=x-(3+m);k++){
        
        if(arr[k]==arr[k+m]){
            count_c=count_c+1;
            }
        }
    }
    printf("a %d \n",count_a);
    printf("b %d \n",count_b);
    printf("c %d \n",count_c);
    int count_total=count_a+count_b+count_c;
    printf("%d",count_total);

}
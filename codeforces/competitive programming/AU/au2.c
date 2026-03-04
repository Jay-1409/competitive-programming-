#include<stdio.h>
int main(){
    int n;
    printf("input a number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        // to display all the factors of that numbers
        if(n%i==0){
            printf("%d \n",i);
        }
    }
}
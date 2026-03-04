#include<stdio.h>
int main(){
    int m;
    int n;
    int count=0;
    scanf("%d %d",&m,&n);
    // int b=0;
    for(int i=0;i<=961;i++){
        int a=i;
        // b=b+1;
        int x,y;
        for(int j=0;j<=961;j++){
            int b=j;
        x=(a*a)+b;
        y=(b*b)+a;
            if(x==n&&y==m){
            count=count+1;
        }
        }
    }
    printf("%d",count);
}
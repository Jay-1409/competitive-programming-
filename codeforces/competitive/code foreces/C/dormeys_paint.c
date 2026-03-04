#include<stdio.h>
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int count=0;
    scanf("%d",&n);
    char a[n];
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
            if(n==2){
            printf("YES\n");
        }
        if(n==3){
            printf("YES\n");
        }
        if(n<1){printf("YES\n");}
    for(int i=0;i<n-3;i++){
        if(n>3){
        if(a[i]+a[i+1]!=a[i+2]+a[i+3]){
            count++;
        }
        }
    }
    if(n!=2){
            if(count>0){
            printf("NO\n");
        }
    if(n!=3){
            if(count>0){
            printf("NO\n");
        }
        if(count==0){printf("YES\n");}
    }
    }
    }
}
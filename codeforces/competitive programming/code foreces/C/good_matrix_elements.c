#include<stdio.h>
int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    int x=(n-1)/2;
    if(n%2!=0){
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&matrix[j][i]);
        }
    }
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            if(k==x){
                sum=sum+matrix[x][l];
            }
        }
    }
    for(int m=0;m<n;m++){
        for(int q=0;q<n;q++){
            if(q==x){
                sum=sum+matrix[m][x];
            }
        }
    }
    for(int r=0;r<n;r++){
        for(int s=0;s<n;s++){
            if(r==s){
                sum=sum+matrix[r][s];
            }
        }
    }
    for(int t=0;t<n;t++){
        for(int u=0;u<n;u++){
            if((t+u)==(n-1)){
                // printf("%d \n",matrix[t][u]);
                sum=sum+matrix[t][u];
            }
        }
    }
    int ans=sum;
    // printf("%d\n",ans);
    // printf("%d \n",matrix[x][x]);
    ans=ans-(matrix[x][x]+matrix[x][x]+matrix[x][x]);
    printf("%d",ans);
    }

}
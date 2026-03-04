#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char arr[n][m];
    // for(int i=0;i<=m;i++){
    //     for(int j=0;i<=n;j++){
    //         scanf("%d",arr[i][j]);
    //     }
    // }
    // printf("%d",arr[1][1]);
    for(int j=0;j<=n;j++){
    for(int i=0;i<=n;i++){
        scanf("%c",arr[i][j]);
    }
    }
    printf("%c",arr[1][1]);

}

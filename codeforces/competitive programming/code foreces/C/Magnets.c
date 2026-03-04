#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        }
    int grp=1;
    // printf("%c",arr[2]);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i+1])
        {
            continue;
        }
        else{grp++;}
    }
    printf("%d",grp);
}

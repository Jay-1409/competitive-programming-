#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    if (arr[0]==-1){
        count++;
        printf("test 1 \n");
        }
        printf("%d \n",count);
    for(int i=0;i<n;i++){
        if(arr[i]<0 && arr[i+1]>0){
            count++;
            printf("test 2 \n");
            printf("%d \n",count);

            if(arr[0]==-1){
                count--;
            printf("test 3 \n");
            printf("%d \n",count);
            }
            if(i==n){
                break;
            }
        }
    }
    printf("%d",count);
}
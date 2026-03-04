#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int index_max=0,index_min=0;
    // printf("%d %d \n",max,min);
    for(int i=0;i<n;i++){
        if(arr[i]==min){
            index_min=i;
            }
        }
    for(int i=n-1;i>=0;i--){
        if(arr[i]==max){
            index_max=i;
        }
    }
    printf("M%d m%d \n",index_max,index_min);
    int step_min,step_max;
    step_max=index_max;
    if(n%2==0){
        step_min=(n)-index_min;
        printf("testeven\n");
    }
    else if(n%2!=0){
        step_min=(n-2)-index_min;
        printf("testodd\n");
        }
    int ans=step_max+step_min;
    if(ans<0){
        ans=0;a
    }
    printf("M%d m%d \n",step_max,step_min);
    printf("%d",ans);


}
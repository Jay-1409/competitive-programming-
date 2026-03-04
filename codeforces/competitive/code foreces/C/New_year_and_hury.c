#include<stdio.h>
int main(){
    int n,k,time=0,range=240;
    int ans=0;
    scanf("%d %d",&n,&k);
    ans=n;
    for(int i=1;i<=n;i++){
        time=time+5*i;
    }
     int free=range-time;
    printf("%d\n",free);

    for(int i=0;i<n;i++){
    if(free<k){
        free=free+5*n;
        n--;
        printf("%d",n);
        }
    else{break;}
    }
    ans=

    printf("%d\n",ans);

}

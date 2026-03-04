#include<stdio.h>
int main(){
    int n;
    int attempts=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    int count=0;
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a==1&&b==1){
        count=count+1;
    }
    else if(b==1&&c==1){
        count=count+1;
    }
    else if(c==1&&a==1){
    count=count+1;
    }
    else if(a==1&&b==1&&c==1){
        count=count+1;
    }
    else if(a==0&&b==0&&c==0){
        count=count;
        }
    else{
        count=count;           
        }   
    if(count>0){
        attempts=attempts+1;
        }
     // printf("%d",count);
    }
    printf("%d",attempts);

}
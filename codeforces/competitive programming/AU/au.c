#include<stdio.h>
int main()
{
    int n;
    int count=0;
    printf("enter a number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x=n%i;
        if(x==0){
            count=count+1;
        }
    }
    if(count>=3){
        printf("this number is a composite number");
    }
    else{
        printf("this number is a prime number");
    }
}

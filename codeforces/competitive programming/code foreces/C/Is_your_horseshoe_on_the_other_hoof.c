#include<stdio.h>
int main(){
    int a,b,c,d;
    int n=4;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);

    char arr[4]={a,b,c,d};
    int count_a=0;
    int count_b=0;
    int count_c=0;

    for(int i=0;i<=1;i++){
        if(arr[i]==arr[n-1]){
        count_a=count_a+1;
        }
        n=n-1;
    }
    for(int j=0;j<=2;j++){
        if(arr[j]==arr[j+1]){
            count_b=count_b+1;
        }
    }
    for(int k=0;k<=1;k++){
        if(arr[k]==arr[k+2]){
            count_c=count_c+1;
        }
    }
    // printf("a %d \n",count_a);
    // printf("b %d \n",count_b);
    // printf("c %d \n",count_c);
    
    // if(count_a>count_b){printf("%d",count_a);}
    // else if(count_a<count_b){printf("%d",count_b);}
    // if(count_b>=count_c){printf("%d",count_b);}
    // else if(count_b<=count_c){printf("%d",count_c);}
    // if(count_c>=count_a){printf("%d",count_c);}
    // else if(count_c>=count_a){printf("%d",count_a);}
    // if(count_a==count_b==count_c){printf("%d",count_a);}
    int count_max;
    // if(count_a>count_b){
    //     count_max=count_a;
    // }
    // else if(count_a<count_b){
    //     count_max=count_b;
    // }
    // if(count_b>count_c){
    //     count_max=count_b;
    // }
    // else if(count_b<count_c){
    //     count_max=count_c;
    // }
    // if(count_c>count_a){
    //     count_max=count_c;
    // }
    // else if(count_c<count_a){
    //     count_max=count_a;
    // }
    // else if(count_a==count_b||count_b==count_c||count_c==count_a){
    //     count_max=count_a;
    // }
    // else if(count_b==count_c){
    //     count_max=count_b;       
    // }
    // else if(count_c==count_a){
    //     count_max=count_c;       
    // }
    // else{return 1;}
    if(count_a>count_b){
        if(count_a>count_c){
            count_max=count_a;
        }
    }
    else if(count_b>count_a){
        if(count_b>count_c){
            count_max=count_b;
        }
    }
    else if(count_b>count_c){
        if(count_b>count_a){
            count_max=count_b;
        }
    }
    else if(count_c>count_b){
        if(count_c>count_a){
            count_max=count_c;
        }
    }   
    else if(count_c>count_a){
        if(count_c>count_b){
            count_max=count_c;
        }
    }
    else if(count_a>count_c){
        if(count_a>count_b){
            count_max=count_a;
        }
    }
    else {count_max=0;}
    printf("%d",count_max);
}
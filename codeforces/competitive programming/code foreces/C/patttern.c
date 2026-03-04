#include<stdio.h>
int main(){
    for(int i=0;i<=4;i++){
        if(i==0){
            printf("%c",'*');
            printf("%c",'*');
            printf("%c\n",'*');
            }
        else if(i==1){
            printf("%c\n",'*     *');
            // printf("test");
        }
        else if(i>1&&i<4){
            printf("%c",'*');
            for(int j=0;j<=6;j++){
                printf("");
            }
        }
    }    
}
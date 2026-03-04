#include<stdio.h>
int main(){
    int age;
    printf("Input your age");
    scanf("%d",&age);
    char name[1000];
    printf("Input your name");
    scanf("%s",name);
    char gender;
    printf("Input your gender in M/F");
    scanf("%c",&gender);
    if(gender=='F'){
        if(age<12){
            printf("Baby %s",name);
        }
        else if(age>12){
            printf("Mrs %s",name);
        }
    }
    else if(gender=='M'){
        if(age<12){
            printf("Master %s",name);
        }
        if(age>12){
            printf("Mr %s",name);
        }

    }
}
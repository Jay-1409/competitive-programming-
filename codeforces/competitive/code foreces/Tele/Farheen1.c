#include<stdio.h>
char marksToGrade(int a){
    if(a>=80 && a<=100){
        return 'A';
    }
    else if(a<80 && a>=60){
        return 'B';
    }
    else if(a>=50&&a<60){
        return 'P';
    }
    else if(a>=0 && a<50){
        return 'F';
    }
}

void printGradeCount(char arr[], int n){
    int a=0,b=0,p=0,f=0;
    for(int i=0;i<n;i++){
        if(arr[i]=='A'){
            a++;
        }
        else if(arr[i]=='B'){
            b++;
        }
        else if(arr[i]=='P'){
            p++;
        }
        else if(arr[i]=='F'){
            f++;
        }
    }
    printf("%dA %dB %dP %dF \n",a,b,p,f);

}
int gradeCount(char arr[]){
    int n=sizeof(arr);
    int count=0;
    char x;
    printf("Enter A,B,C OR D: \n");
    scanf("%c",&arr[]);
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            count++;
        }
    }
    printf("%d \n",count);
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int M[n];
    char N[n];
    for(int i=0;i<n;i++){
        scanf("%d",&M[i]);
        N[i]=marksToGrade(M[i]);
    }

    printf(gradeCount(N));
    printGradeCount(N,n);
}
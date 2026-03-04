#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a;
    cin >>b;
    cin >>c;
//to return the max out of these;
int arr[3]={a,b,c};
int max=arr[0];
for(int i=0;i<3;i++){
    if(arr[i]>max){
        max=arr[i];
    }
}
printf("%d",max);
    return 0;
} 
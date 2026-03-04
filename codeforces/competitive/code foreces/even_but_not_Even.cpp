#include<iostream>
#include<cmath>
using namespace std;
int countLen(int n){
    int count=0;
    while (n!=0){
        n=n/10;
        count++;
    }   
    return count;
}
int main(){
    int a;
    cin >> a;
    int len=countLen(a);
    cout << len;
    int arr[len];
    for(int i=0;i<len;i++){
        arr[i]=a%10;
        a=floor(a/10);
    }
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }
    int sum=0;
    for(int i=0;i<len;i++){
        sum=sum+arr[i];
    }
    for(int i=0;i<;len;i++){
            
    }
}
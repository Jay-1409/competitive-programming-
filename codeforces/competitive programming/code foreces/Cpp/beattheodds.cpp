#include<iostream>
using namespace std;
int countOdd(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            count++;
        }
    }
    return count;
}
int countEven(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            count++;
        }
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int odd=countOdd(arr,n);
        int even=countEven(arr,n);
            // cout << even << endl;
            // cout << odd << endl;

        if(odd>even){
            cout << even << endl;
        }
        if(odd<even){
            cout << odd << endl;
        }
        if(odd==even){
            cout << odd << endl;
        }
    }
}
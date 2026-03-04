#include<iostream>
using namespace std;
int sum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
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
        if(sum(arr,n)<=n){
            cout << "YES" << endl;
        }else{cout << "NO" << endl;}
    }
}
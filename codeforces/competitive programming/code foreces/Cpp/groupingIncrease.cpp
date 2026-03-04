#include<iostream>
using namespace std;
int left(int arr[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]<=arr[i+1]){
            count++;
        }
    }
    return count;
}
int right(int arr[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
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
            cin >>  arr[i];
        }
        int a=left(arr,n);
        int b=right(arr,n);
        cout << a << endl;
        cout << b << endl;
        // if(a>=b){
        //     cout << b << endl;
        // }
        // if(a<b){
        //     cout << a << endl;
        // }
    }
}
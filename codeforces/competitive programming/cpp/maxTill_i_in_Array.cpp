#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int j=0;j<n;j++){
    cin >> arr[j];
    }
    int i;
    cin >> i;
    int max=arr[0];
    for(int j=0;j<=i;j++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout << max;
}
#include<iostream>
using namespace std;
void arrSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    arrSort(arr,n);

    cout << arr[n-1]-arr[0] << endl;
}
int main(){
    int t;
    cin >>t;
    for(int i=0;i<t;i++){
        solve();
    }
}
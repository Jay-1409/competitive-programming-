#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n,k; cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    for(int i=n-k-1;i>=0;i--){
        cout << arr[i] << " ";
    }
    for(int i=n-k;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int t;cin >> t;
    for(int i=0;i<t;i++){
    solve();
    }
}
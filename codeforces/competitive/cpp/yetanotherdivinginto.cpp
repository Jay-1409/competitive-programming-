#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n; cin>>n;
    int arr[n]; int ans=1;
    for(int i=0;i<n;i   ++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]==1){
            ans=2;
        }
    }
    cout<< ans << endl;
}
int main(){
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        solve();
    }
}
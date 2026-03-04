#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;cin>>n;
    int arr[n];
    int ans=0;int cnt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
            // cout<<arr[i]<<endl;
            if(arr[i]==0){
                cnt++;                
            ans=max(cnt,ans);
            }else{
                ans=max(cnt,ans);
                cnt=0;
            }
        
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
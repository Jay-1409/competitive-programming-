#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ref=(int)'A';
    int arr[26]={0};
    for(int i=0;i<n;i++){
        int temp=(int)s[i]-ref;
        // cout<<temp<<endl;
        arr[temp]++;
    }
    // cout<<arr[0]<<endl;
    int ans=0;
    for(int i=0;i<26;i++){
        if(arr[i]/(i+1)>=1){
    ans++;
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
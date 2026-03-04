#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

void solve() {
    int n,k; cin>>n>>k;
    int res=((n)*(n-1))/2;
    // cout<<res-k;
    // cout<<res<<endl;
    if(k>=n-1){
        cout<<1<<endl;return;
    }
    if(k==0){
        cout<<n<<endl;return;
    }
    int ans=min(res,n);
    cout<<max(1,ans)<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
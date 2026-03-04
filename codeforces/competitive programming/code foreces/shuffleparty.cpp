#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin>>n;
    int ans=1;
    for(int i=0;n/2>0;i++){
        ans*=2;
        n/=2;
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
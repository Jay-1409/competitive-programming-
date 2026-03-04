#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x=0;
        cin>>x;
        x=abs(x);
        sum+=x;
    }
    cout<<sum<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
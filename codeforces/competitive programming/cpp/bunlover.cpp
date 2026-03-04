#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long int n; cin>>n;
    long long int a=1;
    a+=((n)*(n+1))/2;
    a+=((n+1)*(n+2))/2;
    cout<<a<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
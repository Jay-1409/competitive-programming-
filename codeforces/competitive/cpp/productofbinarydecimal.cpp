#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int arr[26];
    int ref=97;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        arr[(int)s[i]-ref]++;
        cout<<arr[(int)s[i]-ref];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
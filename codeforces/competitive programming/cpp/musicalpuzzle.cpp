#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
    int n;cin>>n;
    string s;cin>>s;
    set<string> st;
    for(int i=0;i<n-1;i++){
        st.insert(s.substr(i,2));
        // cout<<s.substr(i,2)<<endl;
    }
    cout<<st.size()<<endl;    
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
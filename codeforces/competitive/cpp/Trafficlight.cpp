#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve() {
    int n;
    cin>>n;
    char c;
    cin>>c;
    string s;
    cin>>s;
    s=s+s;
    int lstg=0;
    int maxd=0;
    for(int i=2*n-1;i>=0;i--){
        if(s[i]=='g'){
            lstg=i;
        }
        else if(s[i]==c){
            maxd=max(maxd,lstg-i);
        }
    }
    cout<<maxd<<endl;

}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s; cin>>s;
    int flg=0;
    for(int i=0;i<s.size()/2-1;i++){
        if(s[i]==s[i+1])flg=flg; else {flg=1;break;}
    }
    if(flg==1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
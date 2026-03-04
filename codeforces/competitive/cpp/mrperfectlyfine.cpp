#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

void solve() {
    int n; cin>>n; 
    int m;string s;
    int a=1e9,b=1e9,c=1e9;
    for(int i=0;i<n;i++){
        cin>>m;cin>>s;
        if(s=="11"){
            a=min(a,m);
        }
        if(s=="10"){
            b=min(b,m);
        }
        if(s=="01"){
            c=min(c,m);
        }
    }
    if((a!=1e9)||(b!=1e9&&c!=1e9)){
        cout<<min(a,b+c)<<endl;
    }else{
        cout<<-1<<endl;
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
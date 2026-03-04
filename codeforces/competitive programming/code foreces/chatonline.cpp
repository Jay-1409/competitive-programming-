#include<bits/stdc++.h>
using namespace std;
void solve(){
    int p,q,r,l;
    cin >> p >> q >> r >> l;
    vector<pair<int,int>> x;
    vector<pair<int,int>> y;
    while(p--){
        int a,b;
        cin >> a >> b;
        x.push_back({a,b});
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        y.push_back({a,b});
    }
    
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
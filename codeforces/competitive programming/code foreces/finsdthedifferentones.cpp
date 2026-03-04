#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i = 0 ;i < n;i++){
        cin >> v[i];
    }
    vector<int> pfx(n);
    int q;
    cin >> q;
    pfx[n - 1] = n;
    for(int i = n - 2; i >= 0; i--){
        if(v[i] == v[i+1]){
            pfx[i] = pfx[i+1];
        }else{
            pfx[i] = i + 1;
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        x--;
        if(pfx[x] < y){
            cout << x + 1 << " " << pfx[x] + 1 << endl;
        }else{
            cout << -1 << " " << -1 << endl;
        }
    }
    cout << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
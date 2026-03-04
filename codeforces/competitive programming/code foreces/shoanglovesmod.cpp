#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    map<int,bool> mp;
    // for(auto &i : v)cout<< i << " " ;
    mp[v[0] % 1] = true;
    for(int i = 1; i < n; i++){
        v[i] = v[i - 1] + 1;
        while(mp[v[i] % (i + 1)]){
            v[i]++;
        }
        mp[v[i] % (i + 1)] = true;
    }  

    for(auto &i : v)cout<< i << " " ;
    cout << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
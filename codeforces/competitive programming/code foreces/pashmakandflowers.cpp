#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }
    bool eq = true;
    long long ele = v.front();
    for(auto i : v){
        if(i != ele){
            eq = false;
            break;
        }
    }
    map<long long,long long> mp;
    for(auto i : v) mp[i] ++;
    sort(v.begin(),v.end());
    cout << v.back() - v.front() << " ";
    if(eq){
        cout << (n * (n - 1)) / 2;
    }else cout << mp[v.back()] * mp[v.front()];
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
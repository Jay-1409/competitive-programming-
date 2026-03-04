#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<pair<long long ,char>> p;
    map<char,long long>mp;
    for(auto i : s){
        mp[i]++;
    }
    for(auto i : mp){
        p.push_back({i.second,i.first});
    }
    sort(p.begin(),p.end());
    long long id = p.size() - 1;  
    unsigned long long ans = 0; 
    while(k>0 && id>=0){
        if(k >= p[id].first){
            ans += p[id].first*(p[id].first);
            k-=p[id].first;
            id--;
        }else{
            ans += (k)*(k);
            k = 0;
        }
    }
    cout << ans << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
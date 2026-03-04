#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<string,int> mp;
    for(int i = 0 ; i < n - 1; i ++){
        string x ="";
        x+=s[i];
        x+=s[i+1];
        mp[x]++;
    }
    int mxno = 0;
    string ans;
    for(auto i : mp){
        if(i.second > mxno){
            mxno = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
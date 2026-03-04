#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<char,bool> mp;
    vector<char> tk;
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size(); i++){
        if(!mp[s[i]]){
            tk.push_back(s[i]);
            mp[s[i]] =true;
        }
    }
    if(tk.size() >1){
        string ans;
        for(int i = 0 ; i < 4;i++){
            ans.push_back(tk[i]);
        }        
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
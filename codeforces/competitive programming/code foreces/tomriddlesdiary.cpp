#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<string,bool> mp;
    int n;
    cin >> n;
    while(n--){
        string s; cin >> s;
        if(mp[s] == true){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
            mp[s] = true;
        }
    }
}
int main(){
int t = 1;

while(t--)solve();
return 0;
}
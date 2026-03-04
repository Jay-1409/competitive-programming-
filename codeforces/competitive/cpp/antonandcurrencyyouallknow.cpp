#include<bits/stdc++.h>
using namespace std;
void solve(){
    //SOLVED
    string s; cin >> s;
    bool ok = false;
    int cnt = 0;
    vector<int> v;
    int prev = 0;
    int ev = 0;
    for(auto i :s){
        if((i - '0') % 2 == 0){
            ev++;
        }
    }
    for(auto i:s){
        // cout << i - '0' << endl;
        if((i - '0') % 2 == 0){
            ev--;
            ok = true;
            if(s[cnt] > s[s.length()-1] && ev > 0){
                cnt ++;
                continue;
            }else
            {swap(s[cnt],s[s.length() - 1]); break;}
        }
        cnt ++;
    }
    if(ok){
        cout << s << endl;
    }else cout << -1 << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
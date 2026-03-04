#include<bits/stdc++.h>
using namespace std;
//unsolved
void solve(){
    int n; cin >> n;
    vector<string> s(2);
    for(int i = 0 ; i < 2;i++){
        cin >> s[i];
    }
    int cnt=0;
    for(int i = 0 ; i < n - 1 ; i ++){
        if(s[0][i] == '0' && s[0][i+1] == '0'){
            if(s[1][i] == '0' && s[1][i+1] == '0'){
                cnt++;
            }   
        } else if(s[0][i] == '1' && s[0][i+1] == '1'){
            if(s[1][i] == '1' && s[1][i+1] == '1'){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
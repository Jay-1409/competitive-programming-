#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    string ref = "aeiou";
    int m = ref.size();
    string ans="";
    string ans2 = "";
    int i = 0;
    bool flg = true;
    bool od = false;
    
    while(n--){
        if(flg){
            flg = false;
            ans2 += ref[i];
        }else{
            ans += ref[i];
            flg = true;
        }
        i++;
        if(i >= m){
            i = 0;
        }
    }
    string fans = ans+ans2;
    sort(fans.begin(),fans.end());
    cout << fans << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
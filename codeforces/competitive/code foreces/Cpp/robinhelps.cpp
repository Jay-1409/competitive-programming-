#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    int x;
    int coin = 0;
    while(n--){
        cin >> x;
        if(x >= k){
            coin+=x;
        }else if(x == 0 && coin > 0){
            coin--;
            cnt++;
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
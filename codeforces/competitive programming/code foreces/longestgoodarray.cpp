#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long l,r;
    cin >> l >> r;
    int k  = 1;
    int cnt = 0;
    for(int i = 0 ; i < (r - l ) ; i += k ){
        k++;
        cnt++;
    }
    cout << cnt + 1 << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    if(n < m){
        cout << "NO" << endl;
    }else{
        if(n - m & 1){
            cout <<"NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
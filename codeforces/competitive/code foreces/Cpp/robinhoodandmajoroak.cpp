#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin >> n >> k;
    if(false){
        cout << "NO" << endl;
    }else{
        if(k%2 == 0 && n % 2 == 0){
            cout << "YES" << endl;
        }else{
            if(n % 2 == 0 && k == 1){
                cout << "YES" << endl;
            }else
            cout << "NO" << endl;
        }
    }
}
#undef int
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
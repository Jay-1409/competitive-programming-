#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    if(n & 1){
        cout << n + (n+1)/2 << endl;
    }else{
        if(n <= 4)
        cout << n + (n / 2) << endl;
        else cout << n + (n / 2) - 1 << endl;
    }
}
#undef int
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
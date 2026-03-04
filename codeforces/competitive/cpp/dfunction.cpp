
#include <bits/stdc++.h>
using namespace std;
long long int mod=1e9+7;
long long int modf(long long int a, long long int b) {
    long long int cyr = 1;
    while (b > 0) {
        if (b % 2 == 1)
            cyr = (cyr * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return cyr;
}
void solve(){
        long long int l, r, k; 
        cin >> l >> r >> k; 
        long long int fhans = 10 / k; 
        if(k>=10){ 
            cout << 0 << endl; 
        }
        else{
        if(10 % k)
            fhans++; 
        int lefte = modf(fhans, l); 
        int rightw = modf(fhans, r);
        int ans = (rightw - lefte + mod) % mod; 
        cout << ans << endl;
        }
}
int32_t main() {
    long long int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
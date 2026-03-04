#include<bits/stdc++.h>
using namespace std;
const long long mod = (1e9 + 7);
void solve(){
    //fi = fi-1 + fi+1
    // fi+1 = fi - fi-1
    // fi  = fi-1 - fi - 2
    long long x,y;
    cin >> x >> y;
    long long n;
    cin >> n;
    // vector<long long> v(n+1);
    // v[0] = x;
    // v[1] = y;
    int a = x;
    int b = y;
    int c = y - x;
    if( n == 1){
        cout << (a % mod + mod)% mod << endl;
    }else if(n == 2){
        cout << (b % mod + mod)% mod << endl;
    }else{
        for(int i = 3 ; i < n ; i++){
                a = b;
                b = c;
                c = 0;
            
            c = b - a;
            // v[i] = v[i - 1] - v[i - 2];
        }
        cout << (c % mod + mod) % mod << endl;
    }
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
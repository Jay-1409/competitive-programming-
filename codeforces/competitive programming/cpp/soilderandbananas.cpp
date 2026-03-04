#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long k,n,w;
    cin >> k >> n >> w;
    long long fact = 1;
    if(k*(((w)*(w+1))/2) - n < 0){
        cout << 0 << endl;
    }else
    cout << k*(((w)*(w+1))/2) - n << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
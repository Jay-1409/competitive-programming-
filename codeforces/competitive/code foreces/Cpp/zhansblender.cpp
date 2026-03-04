#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;
    int z = min(x,y);
    cout << (n + z - 1) / z << endl;
}
#undef int
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
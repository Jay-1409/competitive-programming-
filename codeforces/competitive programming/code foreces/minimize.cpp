#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin >> a >> b;
    cout << (max(a,b) - a) - (max(a,b) - b) << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
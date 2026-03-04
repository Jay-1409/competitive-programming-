#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int tot = a+b+c;
    if(tot & 1){
        cout << -1 << endl;
    }else{
        cout << min(a+b,tot/2) << endl; 
    }
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
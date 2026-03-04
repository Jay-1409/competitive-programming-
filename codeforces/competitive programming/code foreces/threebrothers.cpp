#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin >> a >> b;
    if(a + b == 3){
        cout << 3 << endl;
    }else if(a + b == 4){
        cout << 2 << endl;
    }else if(a + b == 5){
        cout << 1 << endl;
    }else{
        cout << "GETLOST" << endl;
    }
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
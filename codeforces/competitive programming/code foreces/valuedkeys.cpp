#include<bits/stdc++.h>
using namespace std;
void solve(){
    string a,b;
    cin >> a >> b;
    string x;
    for(int i=0;i<a.length();i++){
        if((int)a[i] > (int)b[i]){
            x.push_back(b[i]);
        }else if(a[i] == b[i]){
            x.push_back(a[i]);
        }
        else{
            cout << -1 << endl;
            return;
        }
    }
    cout << x << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
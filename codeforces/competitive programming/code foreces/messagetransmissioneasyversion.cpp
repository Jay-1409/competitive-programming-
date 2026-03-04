#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s; cin >> s;
    if(true){
        int m = ceil(s.length() / (double)2);
        string x = s.substr(0,m);
        string y = s.substr(m-1,s.length());
        if(x.back() == y.front()){
            string z = x.substr(0,y.size());
            if(z == y){
                cout << "YES" << endl;
                cout << x << endl;
            }else{
                cout << x << " " << y << endl;
                cout << z << endl;
                cout << "NO" << endl; 
            }
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}
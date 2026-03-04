#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    bool flg = true;
    for(int i = 0 ;i < n ;i++){
        if(i&1){
            int t = m - 1;
            if(flg){
                while(t--){
                    cout <<'.';
                }
                cout << '#';
                flg = false;
            }else{
                cout << '#';
                while(t--){
                    cout <<'.';
                }
                flg = true;
            }
            cout << endl;
        }else{
            int t = m;
            while(t--){
                cout << '#';
            }
            cout << endl;
        }
    }
}
int main(){
int t = 1; 
while(t--)solve();
return 0;
}
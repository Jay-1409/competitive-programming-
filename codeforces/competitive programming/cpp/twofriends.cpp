#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i ++){
        cin >> v[i];
    }
    if(n == 2){
        cout << 2 << endl;
    }else{
        int take = 2;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[v[v[i] - 1] - 1] == v[i]){
                cout << 2 << endl;
                return;
            }
        }
        cout << 3 << endl;
    }
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
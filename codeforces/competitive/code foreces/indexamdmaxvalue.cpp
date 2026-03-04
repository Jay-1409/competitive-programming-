#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,m;
    cin >> n >> m;
    vector<long long> v(n);
    for(int i = 0 ; i < n ; i ++ ){
        cin >> v[i];
    }
    long long mx = (*max_element(v.begin(),v.end()));
    for(int i = 0 ; i < m ; i ++ ){
        char c;
        long long x, y;
        cin >> c >> x >> y;
        if(mx >= x && mx <= y){
            if(c == '+'){
                mx ++;
            }else{
                mx --;
            }
        }
        cout << mx << " ";
    }
    cout << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i ++){
        cin >> v[i];
    }

    vector<int> w;
    for(int i = 0 ; i < n ; i++){
        auto it = upper_bound(w.begin(),w.end(), v[i]);
        if(it == w.end()){
            w.push_back(v[i]);
        }else{
            *it = v[i];
        }
    }
    cout << w.size()  << endl;
}
#undef int
int main(){
int t = 1;

while(t--)solve();
return 0;
}
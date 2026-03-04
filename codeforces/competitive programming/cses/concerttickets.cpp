#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> tix(n);
    for(int i = 0; i < n; i++){
        cin >> tix[i];
    }
    sort(tix.begin(),tix.end());
    int x;
    while(m--){
        cin >> x;
        auto it = upper_bound(tix.begin(),tix.end(),x);
        if(it == tix.begin()){
            cout << -1 << endl;
        }else{
            --it;
            cout << *it << endl;
            tix.erase(it);
        }
    }
}
#undef int
int main(){
int t = 1;
while(t--)solve();
return 0;
}
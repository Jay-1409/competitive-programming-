#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++){cin >> v[i];}
    sort(v.begin(),v.end());
    int avg = v[n / 2];
    int cost = 0;
    for(auto i : v){
        cost += abs(i - avg);
    }
    cout << cost << endl;
}
#undef int
int main(){
int t = 1;
while(t--)solve();
return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n;i ++)
    cin >> v[i];
    sort(v.rbegin(),v.rend());
    int l = n - 2;
    int r = n - 1;
    while(v.size() > 1){
        int mean = (v[l] + v[r]) / 2;
        v.pop_back();
        v.pop_back();
        v.push_back(mean);
        l--;
        r--;
    }
    cout << v.front() << endl;
}
#undef int
int main(){
int t;
cin >> t;
#undef int
while(t--)solve();
return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
//problem statement was very confusing fr
void solve() {
    int n, q;
        cin >> n >> q;  
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i]; 
        map<int, int> freq;
        int range;
        for (int i = 1; i <= n; ++i) {
            if(i == 1) freq[n - i]++;
            else
            freq[(n - i + 1)*(i-1) + (n - i)]++;
            if (i < n && i > 0){
                int len = v[i] - v[i - 1]-1;
                if (len > 0) {
                    freq[i * (n -i)] += len;
                }
            }
        }
        int k;
        while(q--){
            cin >> k;
            cout << freq[k] << " ";
        }
     cout << endl;
}
#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();  
    return 0;
}

#include <bits/stdc++.h>

#define ll int64_t
#define vin(x) for(auto &i: x) cin >> i;
#define fr(i, start, end) for(ll i = start; i < end; i++)

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vin(a);

    unordered_map<int, ll> freq;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            int mask = (1 << j);
            int masked_val = a[i] & mask;
            freq[masked_val]++;
        }
    }

    for (auto [val, count] : freq) {
        ans += count * (count - 1);
    }

    cout << ans * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
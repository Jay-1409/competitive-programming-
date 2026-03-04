#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int gcd_ab = __gcd(a, b);

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i] %= gcd_ab;
    }

    sort(c.begin(), c.end());

    int min_range = c[n-1] - c[0];

    for (int i = 1; i < n; ++i) {
        min_range = min(min_range, c[i - 1] + gcd_ab - c[i]);
    }

    cout << min_range << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

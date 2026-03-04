#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = k + i;
    }
    vector<long long> pfx(n + 1, 0); 
    for (int i = 1; i <= n; ++i) {
        pfx[i] = pfx[i - 1] + a[i - 1];
        // cout << pfx[i] << endl;
    }
    vector<long long> sfx(n + 1, 0); 
    for (int i = n - 1; i >= 0; --i) {
        sfx[i] = sfx[i + 1] + a[i];
        // cout << sfx[i] << endl;
    }
    long long min_x = 1e9;
    for (int i = 1; i <= n; ++i) {
        long long P = pfx[i];
        long long Q = sfx[i];
        long long x = abs(P - Q);
        min_x = min(min_x, x);
    }
    cout << min_x << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

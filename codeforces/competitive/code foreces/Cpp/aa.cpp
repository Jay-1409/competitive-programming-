#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    if(k == 1){
        cout << n << endl;
        return;
    }
    while (n > 0) {
        cnt += n % k;
        n /= k;
    }
    cout << cnt << endl;
}
#undef int
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

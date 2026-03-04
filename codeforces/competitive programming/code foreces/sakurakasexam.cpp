#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    while(n--) {
        int x, u;
        cin >> x >> u;
        
        if ((x + 2 * u) % 2 != 0) {
            cout << "NO" << endl;
        } else {
            int sm = (x + 2 * u) / 2;
            if (sm % 2 == 0 || (sm % 2 == 1 && x > 0)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}

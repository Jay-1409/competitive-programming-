#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int r = sqrt(n);
    bool yes = true;
    
    for (int i = 1; i < r - 1 && yes; ++i) {
        if (s[i*r] != '1' || s[(i+1)*r - 1] != '1') {
            yes = false;
            cout << 1;
            break;
        }
        for (int j = 1; j < r - 1; ++j) {
            if (s[i*r + j] != '0') {
                yes = false;
                cout << 2;
                break;
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        if (s[i] != '1' || s[n-r+i] != '1') {
            yes = false;
            cout << 3;
            break;
        }
    }

    if (yes) {
        if (r * r != n) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

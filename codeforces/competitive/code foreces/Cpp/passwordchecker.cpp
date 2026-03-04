#include <bits/stdc++.h>
using namespace std;
 
#define int long long int

 
int query(const string &s) {
    cout << "? " << s << endl;
    cout.flush(); 
    int x;
    cin >> x; 
    return x;
}
 
void solve(string s, int n) {
    string ans = s;
    int behind = 0;
 
    for (int i = 0; i < n - 2; i++) {
        string cur1 = ans + "0";
        string cur2 = ans + "1";
 
        if (behind == 0) {
            if (query(cur1)) {
                ans = cur1;
            } else if (query(cur2)) {
                ans = cur2;
            } else {
                behind = 1;
            }
        }
 
        if (behind == 1) {
            string c1 = "0" + ans;
            string c2 = "1" + ans;
 
            if (query(c1)) {
                ans = c1;
            } else {
                ans = c2;
            }
        }
    }
 
    cout << "! " << ans << endl; 
    cout.flush(); 
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t; 
 
    while (t--) {
        int n;
        cin >> n;
 
        if (n == 1) {
            if (query("1")) {
                cout << "! 1" << endl;
            } else {
                cout << "! 0" << endl;
            }
            continue;
        }
 
        if (query("00")) {
            solve("00", n);
        } else if (query("01")) {
            solve("01", n);
        } else if (query("10")) {
            solve("10", n);
        } else {
            string ans = "";
            for (int i = 0; i < n; i++) {
                ans = ans + "1";
            }
            cout << "! " << ans << endl;
        }
    }
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isUp(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}
    void solve() {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> up, lw;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                s[i] = ' ';
                if (!lw.empty()) {
                    s[lw.back()] = ' ';
                    lw.pop_back();
                }
            } else if (s[i] == 'B') {
                s[i] = ' ';
                if (!up.empty()) {
                    s[up.back()] = ' ';
                    up.pop_back();
                }
            } else if (islower(s[i])) {
                lw.push_back(i);
            } else {
                up.push_back(i);
            }
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        cout << s << endl;
    }

int main() {
    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}

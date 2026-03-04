#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    vector<int> p(n);
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;  
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (res[i] == 0) {  
            int cnt = 0;
            vector<int> cycle;
            int curr = i;
            while (true) {
                cycle.push_back(curr);
                res[curr] = -1e9;  
                if (s[curr] == '0') {
                    cnt++;
                }
                curr = p[curr];
                if(res[curr] != 0)break;
            }
            for (auto i : cycle) {
                res[i] = cnt;
                //set all ele in loop to that number since they r bound to eb cnct;
            }
        }
    }
    for (int i  = 0; i < n ; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

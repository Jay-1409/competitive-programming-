#include <bits/stdc++.h>
using namespace std;

#define f0r(i, a) for (int i = 0; i < (a); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
//SOLVED
void solve() {
    int n;
    cin >> n;
    string h;
    cin >> h;

    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + (h[i] == '1' ? 1 : 0);
    }

    int curr0 = 0;
    int best_pos = 0;
    int min_dist = INT_MAX;
    double mid = (n) / (double)2;

    for (int i = 0; i <= n; ++i) {
        if (i > 0 && h[i - 1] == '0') {
            curr0++;
        }
        int left_size = i;
        int right_size = n - i;

        int needed_zeros = (left_size + 1) / 2;
        int needed_ones = (right_size + 1) / 2;

        if (curr0 >= needed_zeros && suff[i] >= needed_ones) {
            int dist = abs(mid - i);
            if (dist < min_dist) {
                min_dist = dist;
                best_pos = i;
            } else if (dist == min_dist && i < best_pos) {
                best_pos = i;
            }
        }
    }

    cout << best_pos << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

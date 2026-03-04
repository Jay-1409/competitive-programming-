#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        vector<int> A(N);
        int f = N, l = -1;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (!A[i]) {
                f = min(f, i);
                l = max(l, i);
            }
        }
        cout << max(0, l - f + 2) << '\n';
    }
}
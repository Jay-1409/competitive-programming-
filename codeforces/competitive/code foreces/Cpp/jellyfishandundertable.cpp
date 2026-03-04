#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long int a, b, n;
    cin >> a >> b >> n;

    vector<long long int> v;
int x;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        v.push_back(x);
    }

    int flag = 0;
    int k = 0;
    long long int sec = 0;
    while (flag != 1) {
        if (b == 1 && k != v.size()) {
            b += v[k];
            k++;
            b--;
        } else {
            b--;
        }

        if (b == 0) {
            break;
        }

        if (b > a) {
            b = a;
        }

        sec++;
    }

    cout << sec << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

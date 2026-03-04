#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void findCoins(int n) {
    int count1 = 0, count10 = 0, count5 = 0;
    count5 = n / 15;
    n %= 15;
    count10 = n / 10;
    n %= 10;
    count1 = n / 3;
    n %= 3;
    count1 += n;
    cout<<count1<<endl;
    cout<<count10<<endl;
    cout<<count5<<endl;
    }

void solve() {
    int n;
    cin>>n;
    findCoins(n);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
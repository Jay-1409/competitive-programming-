#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool powr(long long int n) {
    if (n == 0) {
        return false;
    }
    while (n != 1) {
        if (n % 2 != 0) {
            return false;
        }
        n = n / 2;
    }
    return true;
}
void solve() {
    long long int n;
    cin>>n;
    if(powr(n)){
        cout<<"NO"<< endl;
    } else{
        cout<<"YES "<<endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check1(vector<int> v){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]%3==1){
            count++;
        }
    } return count>=0;
}
bool check2(vector<int> v){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]%3==2){
            count++;
        }
    } return count>=0;
}
void solve() {
    int n;
    cin >> n;
    int count = 0;
    int x;
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    if (sum % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    if (sum % 3 == 1) {
        if (check1(v)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else if (sum % 3 == 2) {
        if (check2(v)) {
            cout << 1 << endl;
        } else if (check1(v) && v.size() >= 2) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
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
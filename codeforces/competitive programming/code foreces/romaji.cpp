#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string v = "aeiou"; 

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (v.find(s[i]) != string::npos || s[i] == 'n') {
            continue;
        } else {
            if (i == n - 1) {
                cout << "NO" << endl;
                return 0;
            } else {
                if (v.find(s[i + 1]) == string::npos) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}

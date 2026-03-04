#include<bits/stdc++.h>
using namespace std;

int rec = 0;

void level(int cur, int pos, int target, int n) {
    if (cur == n) {
        if (pos == target) rec++;
        return;
    }
    level(cur + 1, pos + 1, target, n);
    level(cur + 1, pos - 1, target, n);
}

void solve() {
    string a, b;
    cin >> a >> b;

    int target_pos = 0, cur_pos = 0;
    int question_marks = 0;

    for (char ch : a) {
        if (ch == '+') target_pos++;
        else target_pos--;
    }

    for (char ch : b) {
        if (ch == '+') cur_pos++;
        else if (ch == '-') cur_pos--;
        else question_marks++;
    }

    if (question_marks == 0) {
        if (cur_pos == target_pos) {
            cout << "1.000000000000" << endl;
        } else {
            cout << "0.000000000000" << endl;
        }
        return;
    }

    rec = 0;
    level(0, cur_pos, target_pos, question_marks);

    int total_possibilities = pow(2, question_marks);
    double probability = rec / (double)total_possibilities;
    cout << fixed << setprecision(12) << probability << endl;
}

int main() {
    int t = 1;
    while (t--) solve();
    return 0;
}

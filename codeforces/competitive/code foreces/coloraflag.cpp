#include <iostream>
#include <vector>
using namespace std;

#define f0r(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
// solved
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    f0r(i, n) {
      f0r(j, m) { cin >> arr[i][j]; }
    }
    vector<vector<char>> newarr1 = arr;
    vector<vector<char>> newarr2 = arr;
    bool bool1 = true;
    bool bool2 = true;

    f0r(i, n) {
      f0r(j, m) {
        if (newarr1[i][j] == '.') {
          if ((i + j) % 2 == 0) {
            newarr1[i][j] = 'R';
          } else {
            newarr1[i][j] = 'W';
          }
        } else {
          if (((i + j) % 2 == 0 && newarr1[i][j] != 'R') ||
              ((i + j) % 2 == 1 && newarr1[i][j] != 'W')) {
            bool1 = false;
            break;
          }
        }
      }
      if (!bool1)
        break;
    }
    f0r(i, n) {
      f0r(j, m) {
        if (newarr2[i][j] == '.') {
          if ((i + j) % 2 == 0) {
            newarr2[i][j] = 'W';
          } else {
            newarr2[i][j] = 'R';
          }
        } else {
          if (((i + j) % 2 == 0 && newarr2[i][j] != 'W') ||
              ((i + j) % 2 == 1 && newarr2[i][j] != 'R')) {
            bool2 = false;
            break;
          }
        }
      }
      if (!bool2)
        break;
    }
    if (bool1) {
      cout << "YES" << endl;
      f0r(i, n) {
        f0r(j, m) { cout << newarr1[i][j]; }
        cout << endl;
      }
    } else if (bool2) {
      cout << "YES" << endl;
      f0r(i, n) {
        f0r(j, m) { cout << newarr2[i][j]; }
        cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  solve();
  return 0;
}

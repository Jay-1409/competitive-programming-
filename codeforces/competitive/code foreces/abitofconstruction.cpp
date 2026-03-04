#include <iostream>
#include <vector>

using namespace std;

vector<int> maximize_ones(int n, int k) {
  vector<int> result(n);
  int i = 0;

  // Use powers of 2 greedily
  while (k > 0 && i < n) {
    int power = 1 << (31 - __builtin_clz(k)); // Find largest power of 2 less than k
    if (power <= k) {
      result[i++] = power;
      k -= power;
    }
  }

  // Fill remaining with 1s
  while (i < n) {
    result[i++] = 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> sequence = maximize_ones(n, k);
    for (int num : sequence) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}

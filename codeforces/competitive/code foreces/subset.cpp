#include <bits/stdc++.h>

using namespace std;

void permutation(int length, int pos, string current, vector<string> &result) {
  if (pos == length) {
    result.push_back(current);
    return;
  }
  permutation(length, pos + 1, current + '0', result);
  permutation(length, pos + 1, current + '1', result);
}
vector<vector<int>> subsets(const vector<int> &nums) {
  vector<string> per;
  vector<vector<int>> ans;
  int n = nums.size();
  permutation(n, 0, "", per);
  vector<int> emp;
  ans.push_back(emp);
  int m = ans.size();
  int total = pow(2, n);
  for (int i = 0; i < total; i++) {
    vector<int> temp;
    for (int k = 0; k < per[i].size(); k++) {
      if (per[i][k] == '1') {
        temp.push_back(nums[k]);
      }
    }
    ans.push_back(temp);
  }
  set<vector<int>> st(ans.begin(), ans.end());
  vector<vector<int>> final(st.begin(), st.end());

  return final;
}

// Custom comparator function to sort based on size and first element
bool compare(const vector<int> &a, const vector<int> &b) {
  if (a.size() != b.size()) {
    return a.size() < b.size();
  }
  // If sizes are the same, compare based on the first element
  if (!a.empty() && !b.empty()) {
    return a[0] < b[0];
  }
  return false; // Handle empty vectors (although empty vectors are unlikely in
                // this case)
}

int main() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> nums;
  int num;

  while (ss >> num) {
    nums.push_back(num);
  }

  // Generate all subsets
  vector<vector<int>> result = subsets(nums);

  // Sort subsets based on size and first element
  sort(result.begin(), result.end(), compare);

  // Print subsets
  for (const auto &subset : result) {
    cout << "[";
    for (size_t i = 0; i < subset.size(); ++i) {
      cout << subset[i];
      if (i < subset.size() - 1)
        cout << ",";
    }
    cout << "]" << endl;
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases
    
    while (t--) {
        int n;
        cin >> n; // length of array a
        vector<int> a(n);
        
        // Input array elements
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Initialize dp array with zeros
        vector<int> dp(n, 0);
        
        // Calculate dp values
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == i + 1) {
                dp[i] = 1 + (i + 2 < n ? dp[i + 2] : 0);
            }
        }
        
        // Find maximum operations
        int max_operations = 0;
        for (int i = 0; i <n; ++i) {
            max_operations = max(max_operations, dp[i]);
        }
        
        // Output the result for this test case
        cout << max_operations << endl;
    }
    
    return 0;
}

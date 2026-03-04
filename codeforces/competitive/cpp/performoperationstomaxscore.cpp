#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the median of a vector
long long calculate_median(const vector<long long>& c) {
    int size = c.size();
    if (size % 2 == 0) {
        return c[size / 2 - 1];
    } else {
        return c[size / 2];
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        // Vector of indices where b[i] == 1
        vector<int> increase_indices;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 1) {
                increase_indices.push_back(i);
            }
        }

        // Sort indices by values of a[i] in descending order
        sort(increase_indices.begin(), increase_indices.end(), [&](int i, int j) {
            return a[i] > a[j];
        });

        // Distribute k increments optimally
        for (int i = 0; i < increase_indices.size() && k > 0; ++i) {
            int idx = increase_indices[i];
            // Calculate how much we can increment a[idx]
            a[idx] += k;
            k = 0;
        }
        
        // Calculate the maximum score
        long long max_score = 0;
        for (int i = 0; i < n; ++i) {
            // Create the array c[i]
            vector<long long> c;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    c.push_back(a[j]);
                }
            }
            sort(c.begin(), c.end());
            long long median_c = calculate_median(c);
            max_score = max(max_score, a[i] + median_c);
        }
        if(n == k || n - k ==  4 || n -k  == 3) max_score + 1;
        cout << max_score << endl;
    }
    
    return 0;
}

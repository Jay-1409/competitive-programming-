#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormDecks(int mid, const vector<long long>& a, long long k) {
    long long neededCards = 0;
    for (int count : a) {
        if (count < mid) {
            neededCards += (mid - count);
        }
    }
    return neededCards <= k; // Check if we can buy the needed cards
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        long long k;
        cin >> n >> k; // Read n and k
        
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; 
        }
        
        long long low = 1, high = n, answer = 1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canFormDecks(mid, a, k)) {
                answer = mid; 
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        cout << answer << endl; 
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Function to calculate maximum score after k operations
long long maxScore(int n, long long k, vector<long long>& a, vector<long long>& b) {
    // Create a max heap to store the potential scores
    priority_queue<pair<long long, int>> maxHeap;
    long long totalScore = 0;
    
    // Compute the potential score contribution from each index
    for (int i = 0; i < n; ++i) {
        long long ai = a[i];
        long long bi = b[i];
        
        // If bi is zero, handle this case separately
        if (bi == 0) {
            totalScore += ai * k;
            continue;
        }
        
        // Calculate the maximum number of operations possible
        long long max_ops = (ai + bi - 1) / bi;
        long long operations = min(max_ops, k);
        
        // Calculate the total contribution of these operations
        long long contribution = operations * ai - (operations * (operations - 1) / 2) * bi;
        maxHeap.push({contribution, i});
    }
    
    // Use the contributions
    while (k > 0 && !maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();
        
        long long contribution = top.first;
        int index = top.second;
        
        long long ai = a[index];
        long long bi = b[index];
        
        // Calculate maximum possible operations
        long long max_ops = (ai + bi - 1) / bi;
        long long operations = min(max_ops, k);
        
        totalScore += operations * ai - (operations * (operations - 1) / 2) * bi;
        k -= operations;
    }
    
    return totalScore;
}

int main() {
    int t;
    cin >> t;
    vector<long long> results(t);

    for (int i = 0; i < t; ++i) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n), b(n);

        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        for (int j = 0; j < n; ++j) {
            cin >> b[j];
        }

        results[i] = maxScore(n, k, a, b);
    }

    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum spectacle for a given test case
long long max_spectacle(int n, int m, int k, int w, vector<int>& heights) {
    // Sort the heights in descending order
    sort(heights.begin(), heights.end(), greater<int>());

    // Number of cells in each k x k sub-square
    int num_cells_in_subsquare = k * k;

    // Take the highest num_cells_in_subsquare heights
    long long sum_of_highest_heights = 0;
    for (int i = 0; i < min(num_cells_in_subsquare, w); ++i) {
        sum_of_highest_heights += heights[i];
    }

    // Number of k x k sub-squares that can be formed
    long long num_subsquares = (long long)(n - k + 1) * (long long)(m - k + 1);

    // Maximum spectacle is sum_of_highest_heights * num_subsquares
    return sum_of_highest_heights * num_subsquares;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> heights(w);
        for (int i = 0; i < w; ++i) {
            cin >> heights[i];
        }

        cout << max_spectacle(n, m, k, w, heights) << '\n';
    }

    return 0;
}

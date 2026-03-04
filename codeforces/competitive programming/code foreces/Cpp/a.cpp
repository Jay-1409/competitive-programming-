#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoinsToReachEnd(int n, vector<int>& locations) {
    int lastLand = 0;
    int maxGap = 0;

    for (int i = 1; i < n; i++) {
        if (locations[i] == 1) {
            int gap = i - lastLand - 1;
            maxGap = max(maxGap, gap);
            lastLand = i;
        }
    }

    return maxGap;
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;

        vector<int> locations(n);
        for (int i = 0; i < n; i++) {
            cin >> locations[i];
        }

        int result = minCoinsToReachEnd(n, locations);
        cout << result << endl;
    }

    return 0;
}

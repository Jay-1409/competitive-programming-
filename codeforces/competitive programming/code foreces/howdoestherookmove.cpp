#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countConfigurations(int n, int k, vector<pair<int, int>>& moves) {
    vector<vector<int>> grid(n, vector<int>(n, 0)); // Initialize the chessboard grid

    // Mark cells with rooks from the moves already made
    for (int i = 0; i < k; ++i) {
        int r = moves[i].first - 1;
        int c = moves[i].second - 1;
        grid[r][c] = 1;
    }

    int configurations = 1; // Initialize with one configuration (all cells empty)

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) { // If the cell is empty
                if (i != j) { // Not on the diagonal
                    // You place a white rook, and the computer mirrors it
                    configurations = (configurations * 2) % MOD;
                }
            }
        }
    }

    return configurations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> moves(k);
        for (int i = 0; i < k; ++i) {
            int r, c;
            cin >> r >> c;
            moves[i] = {r, c};
        }
        cout << countConfigurations(n, k, moves) << endl;
    }
    return 0;
}

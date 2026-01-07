class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; ++j)
                    grid[i][j] ^= 1;
            }
        }
        for (int j = 1; j < m; ++j) {
            int ones = 0;
            for (int i = 0; i < n; ++i)
                ones += grid[i][j];
            if (ones < n - ones) {
                for (int i = 0; i < n; ++i)
                    grid[i][j] ^= 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int val = 0;
            for (int j = 0; j < m; ++j) {
                val = (val << 1) | grid[i][j];
            }
            ans += val;
        }
        return ans;
    }
};

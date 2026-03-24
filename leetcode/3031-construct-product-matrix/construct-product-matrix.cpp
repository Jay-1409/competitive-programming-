class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pfx(n, vector<int>(m, 1));
        int prod = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                pfx[i][j] = prod;
                prod = (1LL * prod * grid[i][j]) % 12345;
            }
        }
        prod = 1;
        vector<vector<int>> sfx(n, vector<int>(m, 1));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                sfx[i][j] = (1LL * prod * pfx[i][j]) % 12345;
                prod = (1LL * prod * grid[i][j]) % 12345;
            }
        }
        return sfx;
    }
};
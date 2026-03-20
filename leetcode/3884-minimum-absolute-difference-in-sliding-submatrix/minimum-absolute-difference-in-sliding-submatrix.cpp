class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for(int i = 0; i < m - k + 1; ++i) {
            for(int j = 0; j < n - k + 1; ++j) {
                set<int> temp;
                for(int a = i; a < i + k; ++a) {
                    for(int b = j; b < j + k; ++b) {
                        temp.insert(grid[a][b]);
                    }
                }
                int best_diff = INT_MAX;
                if((int)temp.size() == 1)
                    best_diff = 0;
                vector<int> vtemp(temp.begin(), temp.end());
                for(int k = 0; k < (int)vtemp.size() - 1; ++k) {
                    best_diff = min(best_diff, abs(vtemp[k + 1] - vtemp[k]));
                }
                ans[i][j] = best_diff;
            }
        }
        return ans;
    }
};
/**
30*30*30*30*8=900*900*8 = 180000*8 = 1e6-1e7
**/
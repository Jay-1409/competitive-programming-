class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for(int i = 0; i < m - k + 1; ++i) {
            for(int j = 0; j < n - k + 1; ++j) {
                vector<int> temp;
                for(int a = i; a < i + k; ++a) {
                    for(int b = j; b < j + k; ++b) {
                        temp.push_back(grid[a][b]);
                    }
                }
                sort(temp.begin(), temp.end());
                int best_diff = INT_MAX;
                if((int)temp.size() == 1)
                    best_diff = 0;
                for(int k = 0; k < (int)temp.size() - 1; ++k) {
                    if(temp[k] == temp[k + 1])
                        continue;
                    best_diff = min(best_diff, abs(temp[k + 1] - temp[k]));
                }
                ans[i][j] = (best_diff == INT_MAX ? 0 : best_diff);
            }
        }
        return ans;
    }
};
/**
30*30*30*30*8=900*900*8 = 180000*8 = 1e6-1e7
**/
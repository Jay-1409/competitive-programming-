class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> v;
        for(int i = x; i < x + k; ++i) {
            vector<int> temp;
            for(int j = y; j < y + k; ++j) {
                temp.push_back(grid[i][j]);
            }
            v.push_back(temp);
        }
        reverse(v.begin(), v.end());
        int locx = 0;
        int locy = 0;
        for(int i = x; i < x + k; ++i) {
            for(int j = y; j < y + k; ++j) {
                grid[i][j] = v[locx][locy];
                locy++;
            }
            locy = 0;
            locx++;
        }
        return grid;
    }
};
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pfx(n, vector<int>(m, 0));
        vector<vector<int>> pfy(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                pfx[i][j] = grid[i][j] == 'X';
                if(i > 0) {
                    pfx[i][j] += pfx[i - 1][j];
                }
                if(j > 0) {
                    pfx[i][j] += pfx[i][j - 1];
                }
                if(i > 0 && j > 0) {
                    pfx[i][j] -= pfx[i - 1][j - 1];
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                pfy[i][j] = grid[i][j] == 'Y';
                if(i > 0) {
                    pfy[i][j] += pfy[i - 1][j];
                }
                if(j > 0) {
                    pfy[i][j] += pfy[i][j - 1];
                }
                if(i > 0 && j > 0) {
                    pfy[i][j] -= pfy[i - 1][j - 1];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(pfx[i][j] == pfy[i][j] && pfx[i][j] >= 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> s;
        
        auto can_place = [&](int x, int y, vector<string> &g) -> bool {
            int n = g.size();
            for(int i = 0; i < n; ++i) {
                if(g[i][y] == 'Q') return false;
                if(g[x][i] == 'Q') return false;
            }
            // check diagonals
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(g[i][j] == 'Q' && abs(i - x) == abs(j - y))
                        return false;
                }
            }
            return true;
        };
        
        auto dfs = [&](int queens, int x, int y, vector<string> &grid, auto &&self) -> void {
            if(queens == 0) {
                s.push_back(grid);
                return;
            }
            
            if(x >= n) return; // past last row
            
            if(y >= n) { // move to next row
                self(queens, x + 1, 0, grid, self);
                return;
            }
            
            // Try placing a queen
            if(can_place(x, y, grid)) {
                grid[x][y] = 'Q';
                self(queens - 1, x + 1, 0, grid, self); // next row
                grid[x][y] = '.';
            }
            
            // Try not placing a queen here
            self(queens, x, y + 1, grid, self); // next column
        };
        
        vector<string> grid(n, string(n, '.'));
        dfs(n, 0, 0, grid, dfs);
        return s;
    }
};

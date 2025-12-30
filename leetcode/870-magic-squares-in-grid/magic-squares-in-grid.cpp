class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                set<int> summ, numm;
                if(i + 2 >= n || j + 2 >= m)
                    continue;
                for(int x = i; x <= i + 2; ++x) {
                    int sum = 0;
                    for(int y = j; y <= j + 2; ++y) {
                        sum += grid[x][y];
                        if(grid[x][y] <= 9 && grid[x][y] > 0)
                            numm.insert(grid[x][y]);
                    }
        
                    summ.insert(sum);
                }
                for(int x = j; x <= j + 2; ++x) {
                    int sum = 0;
                    for(int y = i; y <= i + 2; ++y) {
                        sum += grid[y][x];
                    }
                    summ.insert(sum);
                }
                int sum = 0;
                for(int d = 0; d < 3; ++d) {
                    sum += grid[i + d][j + d];
                }
                summ.insert(sum);
                sum = 0;
                for(int d = 0; d < 3; ++d) {
                    sum += grid[i + d][j + 2 - d];
                }
                summ.insert(sum);
                if(summ.size() == 1 && numm.size() == 9) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
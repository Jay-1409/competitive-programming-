class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));        
        vector<pair<int,int>> dxn = {{0, 1}, {1, 0}};
        auto dfs = [&](int x, int y, int neu, auto && self) -> int {
            if(x >= n || y >= m || x < 0 || y < 0)
                return INT_MIN/2;
            if(x == n - 1 && y == m - 1) {
                if(coins[x][y] >= 0) 
                    return dp[x][y][neu] = coins[x][y];
                if(neu > 0) 
                    return dp[x][y][neu] = max(0, coins[x][y]);
                return dp[x][y][neu] = coins[x][y];
            }
            if(dp[x][y][neu] != -1e9) 
                return dp[x][y][neu];
            int local_best = INT_MIN;
            for(auto &i : dxn) {
                int nx = i.first + x;
                int ny = i.second + y;
                if(nx >= n || ny >= m || nx < 0 || ny < 0)
                    continue;
                if(coins[x][y] >= 0) {
                    local_best = max(local_best, coins[x][y] + self(nx, ny, neu, self));
                } else {
                    if(neu > 0) {
                        local_best = max(local_best, self(nx, ny, neu - 1, self));
                    } 
                    local_best = max(local_best, coins[x][y] + self(nx, ny, neu, self));
                }
            }
            return dp[x][y][neu] = local_best;
        };
        return dfs(0, 0, 2, dfs);
    }
};
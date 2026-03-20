class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1e9 + 7;
        map<tuple<int,int,int>, int> dp;
        int n = pizza.size(); 
        int m = pizza[0].size();
        vector<vector<int>> pfx(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                pfx[i][j] = (pizza[i][j] == 'A');
                if(i > 0) 
                    pfx[i][j] += pfx[i - 1][j];
                if(j > 0)
                    pfx[i][j] += pfx[i][j - 1];
                if(i > 0 && j > 0) 
                    pfx[i][j] -= pfx[i - 1][j - 1];
            }
        }
        auto query = [&](int x, int y, int a, int b) -> int {
            // sum of rectangle from (x,y) to (a,b)
            int sum = pfx[a][b];
            if (x > 0) 
                sum -= pfx[x - 1][b];
            if (y > 0)
                sum -= pfx[a][y - 1];
            if (x > 0 && y > 0) 
                sum += pfx[x - 1][y - 1];
            return sum;
        };
        auto dfs = [&](int x, int y, int cuts, auto && self) -> int {
            if(x >= n || y >= m)
                return 0;
            if(query(x, y, n - 1, m - 1) == 0)
                return 0;
            if(cuts == 0)
                return 1;
            if(dp.find(make_tuple(x, y, cuts)) != dp.end())   
                return dp[make_tuple(x, y, cuts)];
            long long ans = 0;
            // horizontal cuts
            for(int i = x; i < n - 1; ++i) {
                if(query(x, y, i, m - 1) > 0) {
                    ans += self(i + 1, y, cuts - 1, self);
                    ans %= MOD;
                }
            }
            // vertical cuts
            for(int j = y; j < m - 1; ++j) {
                if(query(x, y, n - 1, j) > 0) {
                    ans += self(x, j + 1, cuts - 1, self);
                    ans %= MOD;
                }
            }
            return dp[make_tuple(x, y, cuts)] = ans;
        };
        return dfs(0, 0, k - 1, dfs);
    }
};
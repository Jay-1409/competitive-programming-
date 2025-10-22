class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        pair<int,int> start;
        pair<int,int> end;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'S') start = {i, j};
                if (board[i][j] == 'E') end = {i, j};
            }
        }
        vector<vector<pair<int,long long>>> memo(n, vector<pair<int,long long>>(n, {-2, 0}));
        auto dfs = [&](int i, int j, auto &&self) -> pair<int,long long> {
            if (i < 0 || j < 0 || i >= n || j >= n || board[i][j] == 'X') 
                return {-1, 0};
            if (i == end.first && j == end.second) 
                return {0, 1};
            if (memo[i][j].first != -2)
                return memo[i][j];

            vector<pair<int,long long>> nexts;
            nexts.push_back(self(i-1, j, self));
            nexts.push_back(self(i, j-1, self));
            nexts.push_back(self(i-1, j-1, self));
            int best = -1;
            long long ways = 0;
            for (auto [val, cnt] : nexts) {
                if (cnt == 0) continue;
                if (val > best) {
                    best = val;
                    ways = cnt;
                } else if (val == best) {
                    ways = (ways + cnt) % MOD;
                }
            }
            if (best == -1) return memo[i][j] = {-1, 0};
            int cur = (board[i][j] == 'S' ? 0 : board[i][j] - '0');
            return memo[i][j] = {best + cur, ways % MOD};
        };
        auto res = dfs(start.first, start.second, dfs);
        if (res.second == 0 || res.first < 0)
            return {0, 0};
        return {(int)res.first, (int)(res.second % MOD)};
    }
};

/**
NOTES

- We can simply do dfs + dp in this situation 
- memoize the [x][y] = the maximum sum that we can get 


But how to get the number of paths that lead to the maximum sum ? 
- at each coordinate we would want to find the maximum subsum that we can acheive 
- just cont the number of times we can acheive that maximum subsum and keep adding that
- then just return that value



**/
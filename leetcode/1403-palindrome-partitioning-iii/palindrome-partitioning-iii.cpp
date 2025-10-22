class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                cost[i][j] = cost[i+1][j-1] + (s[i] != s[j]);
            }
        vector<vector<int>> memo(n, vector<int>(k+1, -1));
        auto f = [&](int pos, int parts_left, auto &&self) -> int {
            if (pos == n && parts_left == 0) 
                return 0;
            if (pos == n || parts_left == 0) 
                return 1e9;
            if (memo[pos][parts_left] != -1) 
                return memo[pos][parts_left];
            int ans = 1e9;
            for (int end = pos; end < n; ++end)
                ans = min(ans, cost[pos][end] + self(end + 1, parts_left - 1, self));
            return memo[pos][parts_left] = ans;
        };
        return f(0, k, f);
    }
};
/**
NOTES

we can reccurse through the string 
- for each location you can check all the 26 possible alphabets that can be placed in that location 
- then you select that and move onwards 
- if you choose a character at the current location whcih is change then you will increase the cnt:moves_done
- you can then memoize the steps with the steps [pos][moves_done][current_choosen_chr][partitions_done]

**/
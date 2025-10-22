class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(27, vector<int>(27, 1e9)));
        int dist[27][27];
        for (int i = 0; i < 26; ++i) {
            int r1 = i / 6, c1 = i % 6;
            for (int j = 0; j < 26; ++j) {
                int r2 = j / 6, c2 = j % 6;
                dist[i][j] = abs(r1 - r2) + abs(c1 - c2);
            }
        }
        for (int f1 = 0; f1 <= 26; ++f1)
            for (int f2 = 0; f2 <= 26; ++f2)
                dp[n][f1][f2] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int next = word[i] - 'A';
            for (int f1 = 0; f1 <= 26; ++f1) {
                for (int f2 = 0; f2 <= 26; ++f2) {
                    int costF1 = (f1 == 26 ? 0 : dist[f1][next]) + dp[i + 1][next][f2];
                    int costF2 = (f2 == 26 ? 0 : dist[f2][next]) + dp[i + 1][f1][next];
                    dp[i][f1][f2] = min(costF1, costF2);
                }
            }
        }
        return dp[0][26][26];
    }
};


/**
NOTES

- we can place the two fingers in all possible combinations 26*26
- then we can memoize on the states [location_in_target_string][finger1][finger2] ||[location_in_target_string][finger2][finger1]
- finding the distance between two letters : [*] precompute and store -> use manhatan distance
- standing on the position x we will calculate the cost to reach that letter from both the fingers 1 and 2
- we have to add the cost to complete the word after that particular move : [bottom up]
- we start from n - 1 donw till 0 
**/
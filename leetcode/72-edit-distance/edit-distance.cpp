class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> cache(n, vector<int>(m, -1));
        auto dp = [&](int p1, int p2, auto && self) -> int {
            if(p1 < 0 && p2 < 0)
                return 0;
            else if(p1 < 0)
                return p2 + 1;
            else if(p2 < 0) {
                return p1 + 1;
            }
            if(cache[p1][p2] != -1) {
                return cache[p1][p2];
            }
            int ans = 0;
            if(word1[p1] == word2[p2]) {
                ans = self(p1 - 1, p2 - 1, self);
            } else {
                int insert = self(p1, p2 - 1, self) + 1;
                int _delete = self(p1 - 1, p2, self) + 1;
                int replace = self(p1 - 1, p2 - 1, self) + 1;
                ans = min({insert, _delete, replace});
            }
            return cache[p1][p2] = ans;
        };
        return dp(n - 1, m - 1, dp);
    }
};
/**
fuck it 
1) incase you are going to insert a new character 
    - word1_idx and word2_idx - 1
2) incase you are going to delete a existing chacter 
    - word1_idx - 1 and word2_idx no change 
3) incase you are going to replace the character
    - word1_idx - 1 and word2_idx - 1
**/
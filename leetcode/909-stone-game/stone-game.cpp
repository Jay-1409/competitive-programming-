class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        bool winner=false;
        auto dfs = [&](int x, int y, int turn, int bob, int alice, auto && self) -> void {
            if(dp[x][y])    return;
            if(x == y) {
                //cout << alice << " " << bob << endl;
                if(alice > bob) {
                    winner |= true;
                } else
                    winner |= false;
                return;
            }
            dp[x][y] = true;
            if(turn == 1) {
                    self(x + 1, y, 1 - turn, bob, alice + piles[x], self);
                    self(x, y - 1, 1 - turn, bob, alice + piles[y], self);
            } else {
                    self(x + 1, y, 1 - turn, bob + piles[x], alice, self);
                    self(x, y - 1, 1 - turn, bob + piles[y], alice, self);
            }
        };  
        dfs(0, n - 1, 1, 0, 0, dfs);
        return winner;
    }
};
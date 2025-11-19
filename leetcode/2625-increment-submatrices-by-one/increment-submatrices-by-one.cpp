class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mp(n + 1, vector<int>(n + 1, 0));
        for(auto &i : queries) {
            int x1 = i[0], y1 = i[1];
            int x2 = i[2], y2 = i[3];
            mp[x1][y1]++;      
            mp[x1][y2 + 1]--;      
            mp[x2 + 1][y1]--;
            mp[x2 + 1][y2 + 1]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                mp[i][j] += mp[i][j-1];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                mp[i][j] += mp[i-1][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                ans[i][j] = mp[i][j];
            }
        }
        return ans;
    }
};
/**
    line sweep on 2D Matrix?
**/
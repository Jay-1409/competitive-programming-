class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> cnt(4, 0);
        int x = 0, y = 0;
        int x_ = 0, y_ =  m - 1;
        int ycells = 0;
        int xcenter = -1, ycenter = -1;
        while(y != y_) {
            //cout << x << " " << y << " - " << x_ << " " << y_ << endl;
            cnt[grid[x][y]]++;
            cnt[grid[x_][y_]]++;
            x++;y++;
            x_++;y_--;
            ycells += 2;
            xcenter = x; ycenter = y;
        }
        while(xcenter < n) {
            cnt[grid[xcenter][ycenter]]++;
            ycells++;
            xcenter++;
        }
        vector<int> cnt_(4, 0);
        for(auto &i : grid) {
            for(auto &j : i) {
                cnt_[j]++;
            }
        }
        vector<int> cnt_rem(4, 0);
        for(int i = 0; i < 3; ++i) {
            cnt_rem[i] = cnt_[i] - cnt[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i == j)
                    continue;
                // i-> color of y, j -> rest color
                int y_req_extra = ycells - cnt[i];
                int ny_req_extra = (n * m - ycells) - (cnt_rem[j]);
                ans = min(ans, y_req_extra + ny_req_extra);
            }
        }
        return ans;
    }
};
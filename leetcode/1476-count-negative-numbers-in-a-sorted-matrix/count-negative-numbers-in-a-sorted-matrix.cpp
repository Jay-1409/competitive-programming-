class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            int pos = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (grid[i][mid] < 0) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            cnt += (n - pos);
        }
        return cnt;
    }
};

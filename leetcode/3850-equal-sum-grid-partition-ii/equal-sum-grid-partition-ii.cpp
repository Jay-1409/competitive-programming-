class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        auto check = [&](vector<vector<int>> g) -> bool {
            int n = g.size();
            int m = g[0].size();
            if(n == 1)
                return false;
            vector<long long> pfx(n + 1, 0);
            for (int i = 0; i < n; ++i) {
                long long sum = 0;
                for (int j = 0; j < m; ++j) {
                    sum += g[i][j];
                }
                pfx[i + 1] = pfx[i] + sum;
            }
            map<long long, vector<int>> presence;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    presence[g[i][j]].push_back(i);
                }
            }
            auto existsInUpper = [&](int mid, long long diff, int width) -> bool {
                int height = mid + 1;
                if(height == 1 && width == 1) {
                    return g[0][0] == diff;
                }
                if (height > 1 && width == 1) {
                    return g[0][0] == diff || g[mid][0] == diff;
                }
                if (height == 1 && width > 1) {
                    return g[0][0] == diff || g[0][m - 1] == diff;
                }
                auto it = presence.find(diff);
                if (it == presence.end()) return false;
                auto &vec = it->second;
                auto ub = upper_bound(vec.begin(), vec.end(), mid);
                return ub != vec.begin();   // some index <= mid
            };
            auto existsInLower = [&](int mid, long long diff, int width) -> bool {
                int height = n - (mid + 1);
                if(height == 1 && width == 1) {
                    return g[mid + 1][0] == diff;
                }
                if(height > 1 && width == 1) {
                    return g[mid + 1][0] == diff || g[n - 1][0] == diff;
                }
                if(height == 1 && width > 1) {
                    return g[mid + 1][0] == diff || g[mid + 1][m - 1] == diff;
                }
                auto it = presence.find(diff);
                if (it == presence.end()) return false;
                auto &vec = it->second;
                auto ub = upper_bound(vec.begin(), vec.end(), mid);
                return ub != vec.end();     // some index > mid
            };
            for (int mid = 0; mid < n - 1; ++mid) {
                long long usum = pfx[mid + 1];
                long long dsum = pfx[n] - pfx[mid + 1];
                if (usum == dsum) return true;
                if (usum > dsum) {
                    long long diff = usum - dsum;
                    if (existsInUpper(mid, diff, m)) return true;
                } else {
                    long long diff = dsum - usum;
                    if (existsInLower(mid, diff, m)) return true;
                }
            }

            return false;
        };
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rgrid(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rgrid[j][i] = grid[i][j];
            }
        }
        bool call1= check(grid);
        bool call2 = check(rgrid);
        return call1 || call2;
    }
};
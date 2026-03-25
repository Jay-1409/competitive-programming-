class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        auto checker = [&](vector<vector<int>> grid) -> bool {
            int n = grid.size();
            int m = grid[0].size();
            if(n == 1)
                return false;
            vector<long long> upsum(n + 1, 0);
            for(int i = 0; i < n; ++i) {
                long long sum = 0;
                for(int j = 0; j < m; ++j) {
                    sum += grid[i][j];
                }
                upsum[i + 1] = upsum[i] + sum;
            }
            /**
                86427
            **/
            int lo = 0;
            int hi = n - 1; 
            while(lo <= hi) {
                int mid = (hi + lo) / 2;
                long long up = upsum[mid + 1];
                long long down = upsum[n] - upsum[mid + 1];
                // cout << mid << " " << up << " " << down << endl;
                if(up < down) {
                    lo = mid + 1;
                } else if(up == down) {
                    return true;
                } else {
                    hi = mid - 1;
                }
            }
            // cout <<" 00" << endl;
            return false;
        } ;
        vector<vector<int>> rgrid(m, vector<int> (n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                rgrid[i][j] = g[j][i];
            }
        }
        bool a = checker(g);
        bool b = checker(rgrid);
        return a || b;
    }
};